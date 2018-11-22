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
// Created by raver on 6/12/2018.
//

#ifndef LIBND4J_TYPES_H
#define LIBND4J_TYPES_H

#include <pointercast.h>
#include <types/float8.h>
#include <types/float16.h>
#include <types/int8.h>
#include <types/int16.h>
#include <types/uint8.h>
#include <types/uint16.h>
#include <types/utf8string.h>

#include <type_boilerplate.h>


#define LIBND4J_TYPES \
        (nd4j::DataType::HALF, float16), \
        (nd4j::DataType::FLOAT32, float), \
        (nd4j::DataType::DOUBLE, double), \
        (nd4j::DataType::BOOL, bool), \
        (nd4j::DataType::INT8, int8_t), \
        (nd4j::DataType::UINT8, uint8_t), \
        (nd4j::DataType::INT16, int16_t), \
        (nd4j::DataType::INT32, int32_t), \
        (nd4j::DataType::INT64, Nd4jLong)

#define LIBND4J_TYPES_EXTENDED \
        (nd4j::DataType::HALF, float16), \
        (nd4j::DataType::FLOAT32, float), \
        (nd4j::DataType::DOUBLE, double), \
        (nd4j::DataType::BOOL, bool), \
        (nd4j::DataType::INT8, int8_t), \
        (nd4j::DataType::UINT8, uint8_t), \
        (nd4j::DataType::INT16, int16_t), \
        (nd4j::DataType::INT32, int32_t), \
        (nd4j::DataType::INT64, Nd4jLong), \
        (nd4j::DataType::UINT16, uint16_t), \
        (nd4j::DataType::UINT64, Nd4jULong), \
        (nd4j::DataType::UINT32, uint32_t)

#define BOOL_TYPES \
        (nd4j::DataType::BOOL, bool)

#define LONG_TYPES \
        (nd4j::DataType::INT64, Nd4jLong)

#define FLOAT_TYPES \
        (nd4j::DataType::HALF, float16), \
        (nd4j::DataType::FLOAT32, float), \
        (nd4j::DataType::DOUBLE, double)

#define FLOAT_TYPES_0 \
        (nd4j::DataType::HALF, float16)

#define FLOAT_TYPES_1 \
        (nd4j::DataType::FLOAT32, float)

#define FLOAT_TYPES_2 \
        (nd4j::DataType::DOUBLE, double)

#define LIBND4J_TYPES_0 \
        (nd4j::DataType::HALF, float16)

#define LIBND4J_TYPES_1 \
        (nd4j::DataType::FLOAT32, float)

#define LIBND4J_TYPES_2 \
        (nd4j::DataType::DOUBLE, double)

#define LIBND4J_TYPES_3 \
        (nd4j::DataType::BOOL, bool)

#define LIBND4J_TYPES_4 \
        (nd4j::DataType::INT8, int8_t)

#define LIBND4J_TYPES_5 \
        (nd4j::DataType::UINT8, uint8_t)

#define LIBND4J_TYPES_6 \
        (nd4j::DataType::INT16, int16_t)

#define LIBND4J_TYPES_7 \
        (nd4j::DataType::INT32, int32_t)

#define LIBND4J_TYPES_8 \
        (nd4j::DataType::INT64, Nd4jLong)

#define INTEGER_TYPES \
        (nd4j::DataType::INT8, int8_t), \
        (nd4j::DataType::UINT8, uint8_t), \
        (nd4j::DataType::INT16, int16_t), \
        (nd4j::DataType::INT32, int32_t), \
        (nd4j::DataType::INT64, Nd4jLong)


#define NUMERIC_TYPES \
        (nd4j::DataType::HALF, float16), \
        (nd4j::DataType::FLOAT32, float), \
        (nd4j::DataType::DOUBLE, double), \
        (nd4j::DataType::INT8, int8_t), \
        (nd4j::DataType::UINT8, uint8_t), \
        (nd4j::DataType::INT16, int16_t), \
        (nd4j::DataType::INT32, int32_t), \
        (nd4j::DataType::INT64, Nd4jLong)



#ifndef __ND4J_EXPERIMENTAL__

#define PAIRWISE_TYPES_0 \
(Nd4jLong, float, Nd4jLong), \
(uint8_t, double, uint8_t), \
(float, uint8_t, uint8_t), \
(float, int, float), \
(uint8_t, Nd4jLong, Nd4jLong), \
(uint8_t, Nd4jLong, uint8_t), \
(float, float, float), \
(int16_t, Nd4jLong, Nd4jLong), \
(int, bool, bool), \
(uint8_t, int16_t, int16_t), \
(uint8_t, double, double), \
(double, bool, double), \
(Nd4jLong, int8_t, Nd4jLong), \
(double, uint8_t, uint8_t), \
(int8_t, double, double), \
(Nd4jLong, bool, bool)

#define PAIRWISE_TYPES_1 \
(int16_t, bool, bool), \
(int8_t, float, int8_t), \
(float, bool, float), \
(float16, int, float16), \
(int8_t, Nd4jLong, Nd4jLong), \
(float16, uint8_t, float16), \
(double, float16, float16), \
(float, uint8_t, float), \
(double, int8_t, double) , \
(Nd4jLong, int, Nd4jLong), \
(bool, int16_t, bool), \
(float, float16, float16), \
(int, float16, int), \
(double, double, double), \
(int, Nd4jLong, int), \
(bool, float, bool)

#define PAIRWISE_TYPES_2 \
(int, float, int), \
(bool, bool, bool), \
(uint8_t, int16_t, uint8_t), \
(uint8_t, uint8_t, uint8_t), \
(float16, int16_t, float16), \
(int8_t, Nd4jLong, int8_t), \
(int8_t, int8_t, int8_t), \
(int8_t, uint8_t, uint8_t), \
(float, int8_t, float), \
(Nd4jLong, float16, Nd4jLong), \
(int8_t, int, int8_t), \
(bool, Nd4jLong, Nd4jLong), \
(Nd4jLong, double, Nd4jLong), \
(bool, float16, float16), \
(uint8_t, float16, float16)

#define PAIRWISE_TYPES_3 \
(int, int16_t, int), \
(int, int16_t, int16_t), \
(int8_t, bool, bool), \
(int8_t, uint8_t, int8_t), \
(int, Nd4jLong, Nd4jLong), \
(bool, int, int), \
(uint8_t, bool, uint8_t), \
(double, int16_t, double), \
(int16_t, float16, int16_t), \
(double, int16_t, int16_t), \
(Nd4jLong, double, double), \
(uint8_t, int8_t, int8_t), \
(double, float, double), \
(int16_t, bool, int16_t), \
(uint8_t, int8_t, uint8_t), \
(float16, int8_t, int8_t), \
(double, float, float)

#define PAIRWISE_TYPES_4 \
(Nd4jLong, int16_t, int16_t), \
(uint8_t, bool, bool), \
(uint8_t, float, uint8_t), \
(int16_t, int8_t, int8_t), \
(int16_t, int, int16_t), \
(int16_t, float16, float16), \
(int16_t, int8_t, int16_t), \
(float16, float16, float16), \
(bool, int, bool), \
(Nd4jLong, int16_t, Nd4jLong), \
(int16_t, Nd4jLong, int16_t), \
(bool, uint8_t, uint8_t), \
(bool, int8_t, bool), \
(float, int16_t, float), \
(float, Nd4jLong, float), \
(int8_t, int, int), \
(Nd4jLong, int8_t, int8_t)

#define PAIRWISE_TYPES_5 \
(int, int8_t, int) , \
(int, float16, float16), \
(uint8_t, float, float), \
(double, Nd4jLong, double), \
(float16, int16_t, int16_t), \
(int, int8_t, int8_t), \
(int16_t, double, double), \
(int, float, float), \
(float, double, double), \
(float16, double, float16), \
(float16, Nd4jLong, Nd4jLong), \
(int, int, int), \
(int, uint8_t, int), \
(float16, double, double), \
(int8_t, int16_t, int16_t), \
(int16_t, int16_t, int16_t), \
(double, uint8_t, double), \
(float16, int8_t, float16)

#define PAIRWISE_TYPES_6 \
(uint8_t, int, uint8_t) ,\
(float, int, int), \
(Nd4jLong, float16, float16), \
(uint8_t, float16, uint8_t) , \
(float, float16, float), \
(int16_t, uint8_t, int16_t), \
(int16_t, uint8_t, uint8_t), \
(float, Nd4jLong, Nd4jLong), \
(float16, uint8_t, uint8_t), \
(float16, bool, float16), \
(Nd4jLong, int, int), \
(int16_t, int, int), \
(bool, double, double), \
(int8_t, float, float), \
(float, bool, bool), \
(double, Nd4jLong, Nd4jLong), \
(float, double, float)

#define PAIRWISE_TYPES_7 \
(int8_t, double, int8_t), \
(Nd4jLong, Nd4jLong, Nd4jLong), \
(Nd4jLong, uint8_t, Nd4jLong), \
(int8_t, float16, int8_t), \
(float16, bool, bool), \
(bool, float, float), \
(int, double, int), \
(int8_t, float16, float16), \
(bool, double, bool), \
(bool, int8_t, int8_t), \
(int16_t, float, int16_t), \
(bool, int16_t, int16_t), \
(int8_t, bool, int8_t), \
(float16, float, float16), \
(double, int8_t, int8_t), \
(int, uint8_t, uint8_t), \
(uint8_t, int, int), \
(int, bool, int)

#define PAIRWISE_TYPES_8 \
(float16, Nd4jLong, float16), \
(double, int, int), \
(float16, int, int), \
(double, bool, bool), \
(Nd4jLong, uint8_t, uint8_t), \
(int16_t, double, int16_t), \
(Nd4jLong, float, float), \
(bool, Nd4jLong, bool), \
(float, int8_t, int8_t) ,\
(int16_t, float, float), \
(Nd4jLong, bool, Nd4jLong), \
(float, int16_t, int16_t), \
(bool, uint8_t, bool), \
(bool, float16, bool), \
(int8_t, int16_t, int8_t), \
(float16, float, float), \
(int, double, double), \
(double, int, double), \
(double, float16, double)

#else

#define PAIRWISE_TYPES_0 \
(float16, float16, float16)

#define PAIRWISE_TYPES_1 \
(float, float, float)

#define PAIRWISE_TYPES_2 \
(double, double, double)

#define PAIRWISE_TYPES_3 \
(int8_t, int8_t, int8_t)

#define PAIRWISE_TYPES_4 \
(int16_t, int16_t, int16_t)

#define PAIRWISE_TYPES_5 \
(uint8_t, uint8_t, uint8_t)

#define PAIRWISE_TYPES_6 \
(int, int, int)

#define PAIRWISE_TYPES_7 \
(bool, bool, bool)

#define PAIRWISE_TYPES_8 \
(Nd4jLong, Nd4jLong, Nd4jLong)

#endif

#endif //LIBND4J_TYPES_H
