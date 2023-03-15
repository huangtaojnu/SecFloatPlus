/*
Authors: Deepak Kumaraswamy, Kanav Gupta
Copyright:
Copyright (c) 2022 Microsoft Research
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <llama/group_element.h>
#include <llama/stats.h>
#include <Eigen/Dense>

using eigenMatrix = Eigen::Matrix<uint64_t, Eigen::Dynamic, Eigen::Dynamic>;

void MatAdd(int s1, int s2, GroupElement *A, GroupElement* B, GroupElement *C);

void MatAdd4(int s0, int s1, int s2, int s3, GroupElement* A, GroupElement* B, GroupElement* C);

void MatSub(int s1, int s2, GroupElement *A, GroupElement* B, GroupElement *C);

void MatSub4(int s0, int s1, int s2, int s3, GroupElement* A, GroupElement* B, GroupElement* C);

void MatMul(int s1, int s2, int s3, GroupElement *A, GroupElement* B, GroupElement *C);

void MatCopy(int s1, int s2, GroupElement *input, GroupElement *output);

// C = C - A*B
void MatSubMul(int s1, int s2, int s3, GroupElement *A, GroupElement* B, GroupElement *C);

// C = C + A*B
void MatAddMul(int s1, int s2, int s3, GroupElement *A, GroupElement* B, GroupElement *C);

void MatCopy4(int s1, int s2, int s3, int s4, GroupElement *input, GroupElement *output);

void MatFinalize4(int bw, int s1, int s2, int s3, int s4, GroupElement *input);

void Conv2DReshapeFilter(int FH, int FW, int CI, int CO, GroupElement* filter, eigenMatrix &reshapedFilter);

void Conv2DReshapeInput(size_t N, size_t H, size_t W, size_t CI, size_t FH, size_t FW, size_t zPadHLeft, size_t zPadHRight, size_t zPadWLeft, size_t zPadWRight, size_t strideH, size_t strideW, size_t RRows, size_t RCols, GroupElement *inputArr, GroupElement *outputArr);

void Conv2DReshapeOutput(int N, int finalH, int finalW, int CO, GroupElement *inputArr, GroupElement *outputArr);

void Conv2DPlaintext(int N, int H, int W, int CI, 
				   int FH, int FW, int CO, 
				   int zPadHLeft, int zPadHRight, int zPadWLeft, int zPadWRight, 
				   int strideH, int strideW, 
				   GroupElement *inputArr, 
				   GroupElement * filterArr, 
				   GroupElement * outArr);

void matmul_eval_helper(int party, int dim1, int dim2, int dim3, GroupElement *A,
                            GroupElement *B, GroupElement *C, GroupElement *ka, GroupElement *kb, GroupElement *kc);

void packBitArray(GroupElement *A, int size, uint8_t *out);

struct Conv2DCache {
    eigenMatrix reshapedFilter;
    eigenMatrix reshapedInput;
    eigenMatrix matmulResult;
    GroupElement *temp;
};

Conv2DCache allocateConv2DCache(int N, int H, int W, int CI, 
                                int FH, int FW, int CO, 
                                int zPadHLeft, int zPadHRight, int zPadWLeft, int zPadWRight, 
                                int strideH, int strideW);

void freeConv2DCache(const Conv2DCache &cache);

void Conv2DPlaintext(int N, int H, int W, int CI, 
				   int FH, int FW, int CO, 
				   int zPadHLeft, int zPadHRight, int zPadWLeft, int zPadWRight, 
				   int strideH, int strideW, 
				   GroupElement *inputArr, 
				   GroupElement * filterArr, 
				   GroupElement * outArr,
                   Conv2DCache &cache);
