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

//
// @author raver119@gmail.com
//

#ifndef ND4J_ARRAY_OPTIONS_H
#define ND4J_ARRAY_OPTIONS_H

#include <op_boilerplate.h>
#include <pointercast.h>
#include <dll.h>
#include <array/DataType.h>
#include <array/ArrayType.h>
#include <array/SpaceType.h>
#include <array/SparseType.h>
#include <initializer_list>


#define ARRAY_SPARSE 2
#define ARRAY_COMPRESSED 4
#define ARRAY_EMPTY 8

#define ARRAY_CSR 16
#define ARRAY_CSC 32
#define ARRAY_COO 64

// complex values
#define ARRAY_COMPLEX 512

// quantized values
#define ARRAY_QUANTIZED 1024

//  16 bit float
#define ARRAY_HALF 4096

// regular 32 bit float
#define ARRAY_FLOAT 8192

// regular 64 bit float
#define ARRAY_DOUBLE 16384

// 8 bit integer
#define ARRAY_CHAR 32768

// 16 bit integer
#define ARRAY_SHORT 65536

// 32 bit integer
#define ARRAY_INT 131072

// 64 bit integer
#define ARRAY_LONG 262144

// boolean values
#define ARRAY_BOOL 524288

// utf-8 values
#define ARRAY_STRING 1048576

// flag for extras 
#define ARRAY_EXTRAS 2097152


// flag for signed/unsigned integers
#define ARRAY_UNSIGNED 8388608


namespace nd4j {
    class ND4J_EXPORT ArrayOptions {

    public:
        static _CUDA_HD bool isNewFormat(const Nd4jLong *shapeInfo);
        static _CUDA_HD bool hasPropertyBitSet(const Nd4jLong *shapeInfo, int property);
        static _CUDA_HD bool togglePropertyBit(Nd4jLong *shapeInfo, int property);
        static _CUDA_HD void unsetPropertyBit(Nd4jLong *shapeInfo, int property);
        static _CUDA_HD void setPropertyBit(Nd4jLong *shapeInfo, int property);
        static _CUDA_HD void setPropertyBits(Nd4jLong *shapeInfo, std::initializer_list<int> properties);

        static _CUDA_HD bool isSparseArray(Nd4jLong *shapeInfo);
        static _CUDA_HD bool isUnsigned(Nd4jLong *shapeInfo);

        static _CUDA_HD nd4j::DataType dataType(const Nd4jLong *shapeInfo);

        static _CUDA_HD SpaceType spaceType(Nd4jLong *shapeInfo);
        static _CUDA_HD SpaceType spaceType(const Nd4jLong *shapeInfo);

        static _CUDA_HD ArrayType arrayType(Nd4jLong *shapeInfo);
        static _CUDA_HD ArrayType arrayType(const Nd4jLong *shapeInfo);

        static _CUDA_HD SparseType sparseType(Nd4jLong *shapeInfo);
        static _CUDA_HD SparseType sparseType(const Nd4jLong *shapeInfo);

        static _CUDA_HD bool hasExtraProperties(Nd4jLong *shapeInfo);


        static _CUDA_HD void resetDataType(Nd4jLong *shapeInfo);
        static _CUDA_HD void setDataType(Nd4jLong *shapeInfo, const nd4j::DataType dataType);

        static _CUDA_HD void copyDataType(Nd4jLong* to, const Nd4jLong* from);
    };
}

#endif // ND4J_ARRAY_OPTIONS_H :)