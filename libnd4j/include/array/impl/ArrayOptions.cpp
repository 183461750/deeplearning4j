/*******************************************************************************
 * Copyright (c) 2015-2018 Skymind, Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

#include <array/ArrayOptions.h>
#include <helpers/shape.h>
#include <stdexcept>

namespace nd4j {
    _CUDA_HD bool ArrayOptions::isNewFormat(const Nd4jLong *shapeInfo) {
        return (shape::extra(const_cast<Nd4jLong*>(shapeInfo)) != 0);
    }


    _CUDA_HD bool ArrayOptions::isSparseArray(Nd4jLong *shapeInfo) {
        return hasPropertyBitSet(shapeInfo, ARRAY_SPARSE);
    }

    _CUDA_HD bool ArrayOptions::hasExtraProperties(Nd4jLong *shapeInfo) {
        return hasPropertyBitSet(shapeInfo, ARRAY_EXTRAS);
    }

    _CUDA_HD bool ArrayOptions::hasPropertyBitSet(const Nd4jLong *shapeInfo, int property) {
        if (!isNewFormat(shapeInfo))
            return false;

        return ((shape::extra(const_cast<Nd4jLong*>(shapeInfo)) & property) == property);
    }

    _CUDA_HD bool ArrayOptions::isUnsigned(Nd4jLong *shapeInfo) {
        if (!isNewFormat(shapeInfo))
            return false;

        return hasPropertyBitSet(shapeInfo, ARRAY_UNSIGNED);
    }

    _CUDA_HD nd4j::DataType ArrayOptions::dataType(const Nd4jLong *shapeInfo) {
        /*if (hasPropertyBitSet(shapeInfo, ARRAY_QUANTIZED))
            return nd4j::DataType::QINT8;
        else */if (hasPropertyBitSet(shapeInfo, ARRAY_FLOAT))
            return nd4j::DataType::FLOAT32;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_DOUBLE))
            return nd4j::DataType::DOUBLE;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_HALF))
            return nd4j::DataType::HALF;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_BOOL))
            return nd4j::DataType ::BOOL;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_UNSIGNED)) {
            if (hasPropertyBitSet(shapeInfo, ARRAY_CHAR))
                return nd4j::DataType ::UINT8;
            else if (hasPropertyBitSet(shapeInfo, ARRAY_SHORT))
                return nd4j::DataType ::UINT16;
            else if (hasPropertyBitSet(shapeInfo, ARRAY_INT))
                return nd4j::DataType ::UINT32;
            else if (hasPropertyBitSet(shapeInfo, ARRAY_LONG))
                return nd4j::DataType ::UINT64;
            else if (hasPropertyBitSet(shapeInfo, ARRAY_STRING))
                return nd4j::DataType ::UTF8;
            else {
                shape::printShapeInfoLinear("Bad unsigned datatype (not)stored in shape", const_cast<Nd4jLong*>(shapeInfo));
                throw std::runtime_error("Bad datatype");
            }
        }
        else if (hasPropertyBitSet(shapeInfo, ARRAY_CHAR))
            return nd4j::DataType::INT8;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_SHORT))
            return nd4j::DataType::INT16;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_INT))
            return nd4j::DataType::INT32;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_LONG))
            return nd4j::DataType::INT64;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_STRING))
            return nd4j::DataType::UTF8;
        else {
            shape::printShapeInfoLinear("Bad signed datatype (not)stored in shape", const_cast<Nd4jLong*>(shapeInfo));
            throw std::runtime_error("Bad datatype");
        }
    }

    _CUDA_HD SpaceType ArrayOptions::spaceType(const Nd4jLong *shapeInfo) {
        return spaceType(const_cast<Nd4jLong *>(shapeInfo));
    }

    _CUDA_HD SpaceType ArrayOptions::spaceType(Nd4jLong *shapeInfo) {
        if (hasPropertyBitSet(shapeInfo, ARRAY_QUANTIZED))
            return SpaceType::QUANTIZED;
        if (hasPropertyBitSet(shapeInfo, ARRAY_COMPLEX))
            return SpaceType::COMPLEX;
        else // by default we return continuous type here
            return SpaceType::CONTINUOUS;
    }

    _CUDA_HD ArrayType ArrayOptions::arrayType(const Nd4jLong *shapeInfo) {
        return arrayType(const_cast<Nd4jLong *>(shapeInfo));
    }

    _CUDA_HD ArrayType ArrayOptions::arrayType(Nd4jLong *shapeInfo) {
        if (hasPropertyBitSet(shapeInfo, ARRAY_SPARSE))
            return ArrayType::SPARSE;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_COMPRESSED))
            return ArrayType::COMPRESSED;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_EMPTY))
            return ArrayType::EMPTY;
        else // by default we return DENSE type here
            return ArrayType::DENSE;
    }

    _CUDA_HD bool ArrayOptions::togglePropertyBit(Nd4jLong *shapeInfo, int property) {
        shape::extra(shapeInfo) ^= property;

        return hasPropertyBitSet(shapeInfo, property);
    }

    _CUDA_HD void ArrayOptions::setPropertyBit(Nd4jLong *shapeInfo, int property) {
        shape::extra(shapeInfo) |= property;
    }

    _CUDA_HD void ArrayOptions::unsetPropertyBit(Nd4jLong *shapeInfo, int property) {
        shape::extra(shapeInfo) &= property;
    }

    _CUDA_HD SparseType ArrayOptions::sparseType(const Nd4jLong *shapeInfo) {
        return sparseType(const_cast<Nd4jLong *>(shapeInfo));
    }

    _CUDA_HD SparseType ArrayOptions::sparseType(Nd4jLong *shapeInfo) {
        if (!isSparseArray(shapeInfo))
            throw std::runtime_error("Not a sparse array");

        if (hasPropertyBitSet(shapeInfo, ARRAY_CSC))
            return SparseType::CSC;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_CSR))
            return SparseType::CSR;
        else if (hasPropertyBitSet(shapeInfo, ARRAY_COO))
            return SparseType::COO;
        else
            return SparseType::LIL;
    }

    _CUDA_HD void ArrayOptions::setPropertyBits(Nd4jLong *shapeInfo, std::initializer_list<int> properties) {
        for (auto v: properties) {
            if (!hasPropertyBitSet(shapeInfo, v))
                setPropertyBit(shapeInfo, v);
        }
    }

    _CUDA_HD void ArrayOptions::resetDataType(Nd4jLong *shapeInfo) {
        unsetPropertyBit(shapeInfo, ARRAY_BOOL);
        unsetPropertyBit(shapeInfo, ARRAY_HALF);
        unsetPropertyBit(shapeInfo, ARRAY_FLOAT);
        unsetPropertyBit(shapeInfo, ARRAY_DOUBLE);
        unsetPropertyBit(shapeInfo, ARRAY_INT);
        unsetPropertyBit(shapeInfo, ARRAY_LONG);
        unsetPropertyBit(shapeInfo, ARRAY_CHAR);
        unsetPropertyBit(shapeInfo, ARRAY_SHORT);
        unsetPropertyBit(shapeInfo, ARRAY_UNSIGNED);
    }

    _CUDA_HD void ArrayOptions::setDataType(Nd4jLong *shapeInfo, const nd4j::DataType dataType) {
        resetDataType(shapeInfo);
        if (dataType == nd4j::DataType::UINT8 ||
                dataType == nd4j::DataType::UINT16 ||
                dataType == nd4j::DataType::UINT32 ||
                dataType == nd4j::DataType::UINT64) {

            setPropertyBit(shapeInfo, ARRAY_UNSIGNED);
        }

        switch (dataType) {
            case nd4j::DataType::BOOL:
                setPropertyBit(shapeInfo, ARRAY_BOOL);
                break;
            case nd4j::DataType::HALF:
                setPropertyBit(shapeInfo, ARRAY_HALF);
                break;
            case nd4j::DataType::FLOAT32:
                setPropertyBit(shapeInfo, ARRAY_FLOAT);
                break;
            case nd4j::DataType::DOUBLE:
                setPropertyBit(shapeInfo, ARRAY_DOUBLE);
                break;
            case nd4j::DataType::INT8:
                setPropertyBit(shapeInfo, ARRAY_CHAR);
                break;
            case nd4j::DataType::INT16:
                setPropertyBit(shapeInfo, ARRAY_SHORT);
                break;
            case nd4j::DataType::INT32:
                setPropertyBit(shapeInfo, ARRAY_INT);
                break;
            case nd4j::DataType::INT64:
                setPropertyBit(shapeInfo, ARRAY_LONG);
                break;
            case nd4j::DataType::UINT8:
                setPropertyBit(shapeInfo, ARRAY_CHAR);
                break;
            case nd4j::DataType::UINT16:
                setPropertyBit(shapeInfo, ARRAY_SHORT);
                break;
            case nd4j::DataType::UINT32:
                setPropertyBit(shapeInfo, ARRAY_INT);
                break;
            case nd4j::DataType::UINT64:
                setPropertyBit(shapeInfo, ARRAY_LONG);
                break;
            case nd4j::DataType::UTF8:
                setPropertyBit(shapeInfo, ARRAY_STRING);
                break;
            default:
                throw std::runtime_error("Can't set unknown data type");
        }
    }

////////////////////////////////////////////////////////////////////////////////
    _CUDA_HD void ArrayOptions::copyDataType(Nd4jLong* to, const Nd4jLong* from) {

    setDataType(to, dataType(from));
}

}