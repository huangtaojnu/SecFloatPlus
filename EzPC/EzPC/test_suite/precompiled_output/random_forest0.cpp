/*
This is an autogenerated file, generated using the EzPC compiler.
*/
#include<vector>
#include<math.h>
#include<cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

uint32_t public_lrshift(uint32_t x, uint32_t y){
return (x >> y);
}

int32_t public_lrshift(int32_t x, uint32_t y){
return ((int32_t)(((uint32_t)x) >> y));
}

uint64_t public_lrshift(uint64_t x, uint64_t y){
return (x >> y);
}

int64_t public_lrshift(int64_t x, uint64_t y){
return ((int64_t)(((uint64_t)x) >> y));
}

template<typename T>
vector<T> make_vector(size_t size) {
return std::vector<T>(size);
}

template <typename T, typename... Args>
auto make_vector(size_t first, Args... sizes)
{
auto inner = make_vector<T>(sizes...);
return vector<decltype(inner)>(first, inner);
}

template<typename T>
ostream& operator<< (ostream &os, const vector<T> &v)
{
for(auto it = v.begin (); it != v.end (); ++it) {
os << *it << endl;
}
return os;
}


#include "ezpc.h"
ABYParty *party;
Circuit* ycirc;
Circuit* acirc;
Circuit* bcirc;
uint32_t bitlen = 64;
output_queue out_q;
e_role role;

share* signedgtbl(share* x, share* y){

share* ux = x;

share* uy = y;
/* Temporary variable for sub-expression on source location: (25,28-25,35) */
int64_t __tac_var1 = ( (int64_t)1 <<  (int64_t)63);
/* Temporary variable for sub-expression on source location: (25,28-25,35) */
share* __tac_var2 = put_cons64_gate(ycirc, __tac_var1);

share* signBitX = ycirc->PutANDGate(x, __tac_var2);
/* Temporary variable for sub-expression on source location: (26,28-26,35) */
int64_t __tac_var3 = ( (int64_t)1 <<  (int64_t)63);
/* Temporary variable for sub-expression on source location: (26,28-26,35) */
share* __tac_var4 = put_cons64_gate(ycirc, __tac_var3);

share* signBitY = ycirc->PutANDGate(y, __tac_var4);
/* Temporary variable for sub-expression on source location: (27,10-27,29) */
share* __tac_var5 = ycirc->PutXORGate(signBitX, signBitY);
/* Temporary variable for sub-expression on source location: (27,33-27,36) */
share* __tac_var6 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (27,9-27,36) */
share* __tac_var7 = ycirc->PutGTGate(__tac_var5, __tac_var6);
/* Temporary variable for sub-expression on source location: (27,53-27,56) */
share* __tac_var8 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (27,42-27,56) */
share* __tac_var9 = ycirc->PutGTGate(signBitX, __tac_var8);
/* Temporary variable for sub-expression on source location: (27,60-27,65) */
share* __tac_var10 = put_cons1_gate(ycirc, 0);
/* Temporary variable for sub-expression on source location: (27,68-27,72) */
share* __tac_var11 = put_cons1_gate(ycirc, 1);
/* Temporary variable for sub-expression on source location: (27,41-27,72) */
share* __tac_var12 = ycirc->PutMUXGate(__tac_var10, __tac_var11, __tac_var9);
/* Temporary variable for sub-expression on source location: (27,77-27,84) */
share* __tac_var13 = ycirc->PutGTGate(ux, uy);
/* Temporary variable for sub-expression on source location: (27,8-27,85) */
share* __tac_var14 = ycirc->PutMUXGate(__tac_var12, __tac_var13, __tac_var7);
return __tac_var14;
}

share* signedarshiftbl(share* x, uint64_t y){

share* ux = x;
/* Temporary variable for sub-expression on source location: (35,28-35,35) */
int64_t __tac_var15 = ( (int64_t)1 <<  (int64_t)63);
/* Temporary variable for sub-expression on source location: (35,28-35,35) */
share* __tac_var16 = put_cons64_gate(ycirc, __tac_var15);

share* signBitX = ycirc->PutANDGate(x, __tac_var16);
/* Temporary variable for sub-expression on source location: (36,21-36,24) */
share* __tac_var17 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (36,10-36,24) */
share* __tac_var18 = ycirc->PutGTGate(signBitX, __tac_var17);
/* Temporary variable for sub-expression on source location: (36,29-36,32) */
share* __tac_var19 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (36,37-36,40) */
share* __tac_var20 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (36,37-36,45) */
share* __tac_var21 = ycirc->PutSUBGate(__tac_var20, ux);
/* Temporary variable for sub-expression on source location: (36,36-36,51) */
share* __tac_var22 = arithmetic_right_shift(ycirc, __tac_var21, y);
/* Temporary variable for sub-expression on source location: (36,29-36,52) */
share* __tac_var23 = ycirc->PutSUBGate(__tac_var19, __tac_var22);
/* Temporary variable for sub-expression on source location: (36,57-36,64) */
share* __tac_var24 = arithmetic_right_shift(ycirc, ux, y);
/* Temporary variable for sub-expression on source location: (36,9-36,65) */
share* __tac_var25 = ycirc->PutMUXGate(__tac_var23, __tac_var24, __tac_var18);
return __tac_var25;
}

share* unsignedltbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (40,9-40,14) */
share* __tac_var26 = ycirc->PutGTGate(y, x);
return __tac_var26;
}

share* signedltbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (43,9-43,14) */
share* __tac_var27 = signedgtbl(y, x);
return __tac_var27;
}

share* unsignedleqbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (47,10-47,15) */
share* __tac_var28 = ycirc->PutGTGate(x, y);
/* Temporary variable for sub-expression on source location: (47,8-47,16) */
share* __tac_var29 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var28);
return __tac_var29;
}

share* signedleqbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (50,10-50,15) */
share* __tac_var30 = signedgtbl(x, y);
/* Temporary variable for sub-expression on source location: (50,8-50,16) */
share* __tac_var31 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var30);
return __tac_var31;
}

share* unsignedgeqbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (54,10-54,15) */
share* __tac_var32 = ycirc->PutGTGate(y, x);
/* Temporary variable for sub-expression on source location: (54,8-54,16) */
share* __tac_var33 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var32);
return __tac_var33;
}

share* signedgeqbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (57,10-57,15) */
share* __tac_var34 = signedgtbl(y, x);
/* Temporary variable for sub-expression on source location: (57,8-57,16) */
share* __tac_var35 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var34);
return __tac_var35;
}

share* unsignedequalsbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (61,11-61,16) */
share* __tac_var36 = unsignedltbl(x, y);
/* Temporary variable for sub-expression on source location: (61,9-61,17) */
share* __tac_var37 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var36);
/* Temporary variable for sub-expression on source location: (61,25-61,30) */
share* __tac_var38 = unsignedltbl(y, x);
/* Temporary variable for sub-expression on source location: (61,23-61,31) */
share* __tac_var39 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var38);
/* Temporary variable for sub-expression on source location: (61,8-61,32) */
share* __tac_var40 = ycirc->PutANDGate(__tac_var37, __tac_var39);
return __tac_var40;
}

share* signedequalsbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (64,11-64,16) */
share* __tac_var41 = signedltbl(x, y);
/* Temporary variable for sub-expression on source location: (64,9-64,17) */
share* __tac_var42 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var41);
/* Temporary variable for sub-expression on source location: (64,25-64,30) */
share* __tac_var43 = signedltbl(y, x);
/* Temporary variable for sub-expression on source location: (64,23-64,31) */
share* __tac_var44 = ((BooleanCircuit *) ycirc)->PutINVGate(__tac_var43);
/* Temporary variable for sub-expression on source location: (64,8-64,32) */
share* __tac_var45 = ycirc->PutANDGate(__tac_var42, __tac_var44);
return __tac_var45;
}

share* longDivision(share* x, share* y, uint32_t getQuotient){

share* q = put_cons64_gate(ycirc,  (uint64_t)0);

share* divisor = put_cons64_gate(ycirc,  (uint64_t)0);

share* cond = put_cons1_gate(ycirc, 0);
for (uint32_t iter =  (int32_t)0; iter <  (int32_t)64; iter++){

uint64_t i = ( (int64_t)63 - iter);
divisor = left_shift(ycirc, divisor,  (uint64_t)1);
/* Temporary variable for sub-expression on source location: (81,32-81,40) */
uint64_t __tac_var46 = ( (uint64_t)1 << i);
/* Temporary variable for sub-expression on source location: (81,32-81,40) */
share* __tac_var47 = put_cons64_gate(ycirc, __tac_var46);
/* Temporary variable for sub-expression on source location: (81,27-81,41) */
share* __tac_var48 = ycirc->PutANDGate(x, __tac_var47);
/* Temporary variable for sub-expression on source location: (81,26-81,48) */
share* __tac_var49 = logical_right_shift(ycirc, __tac_var48, i);
divisor = ycirc->PutADDGate(divisor, __tac_var49);
cond = unsignedgeqbl(divisor, y);
/* Temporary variable for sub-expression on source location: (83,22-83,36) */
share* __tac_var50 = ycirc->PutSUBGate(divisor, y);
divisor = ycirc->PutMUXGate(__tac_var50, divisor, cond);
q = left_shift(ycirc, q,  (uint64_t)1);
/* Temporary variable for sub-expression on source location: (85,19-85,22) */
share* __tac_var51 = put_cons64_gate(ycirc,  (uint64_t)1);
/* Temporary variable for sub-expression on source location: (85,15-85,22) */
share* __tac_var52 = ycirc->PutADDGate(q, __tac_var51);
q = ycirc->PutMUXGate(__tac_var52, q, cond);
}
/* Temporary variable for sub-expression on source location: (88,9-88,34) */
share* __tac_var53 = getQuotient ? q : divisor;
return __tac_var53;
}

share* unsigneddivbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (91,8-91,32) */
share* __tac_var54 = longDivision(x, y, 1);
return __tac_var54;
}

share* unsigneddival(share* x, share* y){

share* bx = ycirc->PutA2YGate(x);

share* by = ycirc->PutA2YGate(y);
/* Temporary variable for sub-expression on source location: (96,8-96,13) */
share* __tac_var55 = unsigneddivbl(bx, by);
return __tac_var55;
}

share* signeddivbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (99,23-99,25) */
share* __tac_var56 = put_cons64_gate(ycirc,  (int64_t)0);

share* isXNeg = signedltbl(x, __tac_var56);
/* Temporary variable for sub-expression on source location: (100,23-100,25) */
share* __tac_var57 = put_cons64_gate(ycirc,  (int64_t)0);

share* isYNeg = signedltbl(y, __tac_var57);
/* Temporary variable for sub-expression on source location: (101,26-101,28) */
share* __tac_var58 = put_cons64_gate(ycirc,  (int64_t)0);
/* Temporary variable for sub-expression on source location: (101,26-101,32) */
share* __tac_var59 = ycirc->PutSUBGate(__tac_var58, x);

share* ux = ycirc->PutMUXGate(__tac_var59, x, isXNeg);
/* Temporary variable for sub-expression on source location: (102,26-102,28) */
share* __tac_var60 = put_cons64_gate(ycirc,  (int64_t)0);
/* Temporary variable for sub-expression on source location: (102,26-102,32) */
share* __tac_var61 = ycirc->PutSUBGate(__tac_var60, y);

share* uy = ycirc->PutMUXGate(__tac_var61, y, isYNeg);

share* ures = unsigneddivbl(ux, uy);

share* isResNeg = ycirc->PutXORGate(isXNeg, isYNeg);
/* Temporary variable for sub-expression on source location: (105,21-105,24) */
share* __tac_var62 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (105,21-105,31) */
share* __tac_var63 = ycirc->PutSUBGate(__tac_var62, ures);
/* Temporary variable for sub-expression on source location: (105,9-105,39) */
share* __tac_var64 = ycirc->PutMUXGate(__tac_var63, ures, isResNeg);
return __tac_var64;
}

share* signeddival(share* x, share* y){

share* bx = ycirc->PutA2YGate(x);

share* by = ycirc->PutA2YGate(y);
/* Temporary variable for sub-expression on source location: (110,8-110,13) */
share* __tac_var65 = signeddivbl(bx, by);
return __tac_var65;
}

share* unsignedmodbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (118,8-118,33) */
share* __tac_var66 = longDivision(x, y, 0);
return __tac_var66;
}

share* unsignedmodal(share* x, share* y){

share* bx = ycirc->PutA2YGate(x);

share* by = ycirc->PutA2YGate(y);
/* Temporary variable for sub-expression on source location: (123,8-123,13) */
share* __tac_var67 = unsignedmodbl(bx, by);
return __tac_var67;
}

share* signedmodbl(share* x, share* y){
/* Temporary variable for sub-expression on source location: (126,23-126,25) */
share* __tac_var68 = put_cons64_gate(ycirc,  (int64_t)0);

share* isXNeg = signedltbl(x, __tac_var68);
/* Temporary variable for sub-expression on source location: (127,23-127,25) */
share* __tac_var69 = put_cons64_gate(ycirc,  (int64_t)0);

share* isYNeg = signedltbl(y, __tac_var69);
/* Temporary variable for sub-expression on source location: (128,26-128,28) */
share* __tac_var70 = put_cons64_gate(ycirc,  (int64_t)0);
/* Temporary variable for sub-expression on source location: (128,26-128,32) */
share* __tac_var71 = ycirc->PutSUBGate(__tac_var70, x);

share* ux = ycirc->PutMUXGate(__tac_var71, x, isXNeg);
/* Temporary variable for sub-expression on source location: (129,26-129,28) */
share* __tac_var72 = put_cons64_gate(ycirc,  (int64_t)0);
/* Temporary variable for sub-expression on source location: (129,26-129,32) */
share* __tac_var73 = ycirc->PutSUBGate(__tac_var72, y);

share* uy = ycirc->PutMUXGate(__tac_var73, y, isYNeg);

share* urem = unsignedmodbl(ux, uy);
/* Temporary variable for sub-expression on source location: (131,19-131,22) */
share* __tac_var74 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (131,19-131,29) */
share* __tac_var75 = ycirc->PutSUBGate(__tac_var74, urem);
/* Temporary variable for sub-expression on source location: (131,9-131,37) */
share* __tac_var76 = ycirc->PutMUXGate(__tac_var75, urem, isXNeg);
return __tac_var76;
}

share* signedmodal(share* x, share* y){

share* bx = ycirc->PutA2YGate(x);

share* by = ycirc->PutA2YGate(y);
/* Temporary variable for sub-expression on source location: (136,8-136,13) */
share* __tac_var77 = signedmodbl(bx, by);
return __tac_var77;
}

const uint32_t noOfFeatures =  (int32_t)13;

const uint32_t maxDepth =  (int32_t)11;

const int32_t maxDepthInt =  (int32_t)11;

const uint32_t noOfTrees =  (int32_t)10;

const uint32_t noOfNodes =  (int32_t)3035;

void accessElementOneD(auto& arr, share* idx, auto& result){
result[ (int32_t)0] = put_cons64_gate(ycirc,  (uint64_t)0);

uint64_t ctr =  (uint64_t)0;
for (uint32_t i =  (int32_t)0; i < noOfFeatures; i++){
/* Temporary variable for sub-expression on source location: (154,14-154,23) */
share* __tac_var78 = result[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (154,37-154,40) */
share* __tac_var79 = put_cons64_gate(ycirc, ctr);
/* Temporary variable for sub-expression on source location: (154,30-154,40) */
share* __tac_var80 = unsignedequalsbl(idx, __tac_var79);
/* Temporary variable for sub-expression on source location: (154,41-154,47) */
share* __tac_var81 = arr[i];
/* Temporary variable for sub-expression on source location: (154,48-154,51) */
share* __tac_var82 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (154,30-154,51) */
share* __tac_var83 = ycirc->PutMUXGate(__tac_var81, __tac_var82, __tac_var80);
result[ (int32_t)0] = ycirc->PutADDGate(__tac_var78, __tac_var83);
ctr = (ctr +  (uint64_t)1);
}
}

void accessElementTwoD(auto& arr, int64_t treeId, share* idx, auto& result, uint32_t start, uint32_t end){
result[ (int32_t)0] = put_cons64_gate(ycirc,  (uint64_t)0);

uint64_t ctr =  (uint64_t)0;

share* idxcpy = ycirc->PutA2YGate(idx);
for (uint32_t i = start; i < end; i++){
/* Temporary variable for sub-expression on source location: (165,14-165,23) */
share* __tac_var84 = result[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (165,40-165,43) */
share* __tac_var85 = put_cons64_gate(ycirc, ctr);
/* Temporary variable for sub-expression on source location: (165,30-165,43) */
share* __tac_var86 = unsignedequalsbl(idxcpy, __tac_var85);
/* Temporary variable for sub-expression on source location: (165,44-165,58) */
share* __tac_var87 = arr[treeId][i];
/* Temporary variable for sub-expression on source location: (165,59-165,62) */
share* __tac_var88 = put_cons64_gate(ycirc,  (uint64_t)0);
/* Temporary variable for sub-expression on source location: (165,30-165,62) */
share* __tac_var89 = ycirc->PutMUXGate(__tac_var87, __tac_var88, __tac_var86);
result[ (int32_t)0] = ycirc->PutADDGate(__tac_var84, __tac_var89);
ctr = (ctr +  (uint64_t)1);
}
}

uint32_t pow(uint32_t base, int32_t power){

uint32_t result =  (int32_t)1;
for (uint32_t i =  (int32_t)0; i < power; i++){
result = (result * base);
}
return result;
}

void infer(auto& modelFeatureChoice, auto& modelThresholdValue, auto& query, auto& result){

share* currentIndex = put_cons64_gate(acirc,  (uint64_t)0);

share* leftOrRight = put_cons64_gate(acirc,  (uint64_t)0);

auto currentSharedFeatureChoice = make_vector<share*>( (int32_t)1);

auto currentSharedThreshold = make_vector<share*>( (int32_t)1);

auto currentSharedQueryValue = make_vector<share*>( (int32_t)1);
currentSharedFeatureChoice[ (int32_t)0] = put_cons64_gate(ycirc,  (uint64_t)0);
currentSharedThreshold[ (int32_t)0] = put_cons64_gate(ycirc,  (uint64_t)0);
currentSharedQueryValue[ (int32_t)0] = put_cons64_gate(ycirc,  (uint64_t)0);

uint32_t startIdx =  (int32_t)0;

uint32_t endIdx =  (int32_t)0;
for (uint32_t i =  (int32_t)0; i < noOfTrees; i++){
currentIndex = put_cons64_gate(acirc,  (uint64_t)0);
currentSharedFeatureChoice[ (int32_t)0] = modelFeatureChoice[i][ (int32_t)0];
currentSharedThreshold[ (int32_t)0] = modelThresholdValue[i][ (int32_t)0];
/* Temporary variable for sub-expression on source location: (199,27-199,56) */
share* __tac_var90 = currentSharedFeatureChoice[ (int32_t)0];
accessElementOneD(query, __tac_var90, currentSharedQueryValue);
/* Temporary variable for sub-expression on source location: (200,17-200,42) */
share* __tac_var91 = currentSharedThreshold[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (200,45-200,71) */
share* __tac_var92 = currentSharedQueryValue[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (200,17-200,71) */
share* __tac_var93 = ycirc->PutGTGate(__tac_var91, __tac_var92);
/* Temporary variable for sub-expression on source location: (200,73-200,75) */
share* __tac_var94 = put_cons64_gate(ycirc,  (int64_t)1);
/* Temporary variable for sub-expression on source location: (200,76-200,78) */
share* __tac_var95 = put_cons64_gate(ycirc,  (int64_t)2);
/* Temporary variable for sub-expression on source location: (200,16-200,78) */
share* __tac_var96 = ycirc->PutMUXGate(__tac_var94, __tac_var95, __tac_var93);
leftOrRight = acirc->PutY2AGate(__tac_var96, bcirc);
/* Temporary variable for sub-expression on source location: (201,11-201,24) */
int32_t __tac_var97 = (maxDepthInt -  (int32_t)1);
for (uint32_t j =  (int32_t)1; j < __tac_var97; j++){
/* Temporary variable for sub-expression on source location: (203,37-203,40) */
share* __tac_var98 = put_cons64_gate(acirc,  (uint64_t)2);
/* Temporary variable for sub-expression on source location: (203,19-203,40) */
share* __tac_var99 = acirc->PutMULGate(currentIndex, __tac_var98);
currentIndex = acirc->PutADDGate(__tac_var99, leftOrRight);
/* Temporary variable for sub-expression on source location: (204,14-204,24) */
uint32_t __tac_var100 = pow( (uint32_t)2, j);
startIdx = (__tac_var100 -  (uint32_t)1);
/* Temporary variable for sub-expression on source location: (205,20-205,23) */
int32_t __tac_var101 = (j +  (int32_t)1);
/* Temporary variable for sub-expression on source location: (205,12-205,24) */
uint32_t __tac_var102 = pow( (uint32_t)2, __tac_var101);
endIdx = (__tac_var102 -  (uint32_t)1);
accessElementTwoD(modelThresholdValue, i, currentIndex, currentSharedThreshold, startIdx, endIdx);
accessElementTwoD(modelFeatureChoice, i, currentIndex, currentSharedFeatureChoice, startIdx, endIdx);
/* Temporary variable for sub-expression on source location: (208,28-208,57) */
share* __tac_var103 = currentSharedFeatureChoice[ (int32_t)0];
accessElementOneD(query, __tac_var103, currentSharedQueryValue);
/* Temporary variable for sub-expression on source location: (209,18-209,43) */
share* __tac_var104 = currentSharedThreshold[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (209,46-209,72) */
share* __tac_var105 = currentSharedQueryValue[ (int32_t)0];
/* Temporary variable for sub-expression on source location: (209,18-209,72) */
share* __tac_var106 = ycirc->PutGTGate(__tac_var104, __tac_var105);
/* Temporary variable for sub-expression on source location: (209,74-209,76) */
share* __tac_var107 = put_cons64_gate(ycirc,  (int64_t)1);
/* Temporary variable for sub-expression on source location: (209,77-209,79) */
share* __tac_var108 = put_cons64_gate(ycirc,  (int64_t)2);
/* Temporary variable for sub-expression on source location: (209,17-209,79) */
share* __tac_var109 = ycirc->PutMUXGate(__tac_var107, __tac_var108, __tac_var106);
leftOrRight = acirc->PutY2AGate(__tac_var109, bcirc);
}
/* Temporary variable for sub-expression on source location: (212,36-212,39) */
share* __tac_var110 = put_cons64_gate(acirc,  (uint64_t)2);
/* Temporary variable for sub-expression on source location: (212,18-212,39) */
share* __tac_var111 = acirc->PutMULGate(currentIndex, __tac_var110);
currentIndex = acirc->PutADDGate(__tac_var111, leftOrRight);
/* Temporary variable for sub-expression on source location: (213,21-213,34) */
int32_t __tac_var112 = (maxDepthInt -  (int32_t)1);
/* Temporary variable for sub-expression on source location: (213,13-213,35) */
uint32_t __tac_var113 = pow( (uint32_t)2, __tac_var112);
startIdx = (__tac_var113 -  (uint32_t)1);
/* Temporary variable for sub-expression on source location: (214,11-214,31) */
uint32_t __tac_var114 = pow( (uint32_t)2, maxDepthInt);
endIdx = (__tac_var114 -  (uint32_t)1);
accessElementTwoD(modelThresholdValue, i, currentIndex, currentSharedThreshold, startIdx, endIdx);
result[i] = currentSharedThreshold[ (int32_t)0];
}
}


int64_t ezpc_main (e_role role_param, char* address, uint16_t port, seclvl seclvl,
uint32_t nvals, uint32_t nthreads, e_mt_gen_alg mt_alg,
e_sharing sharing) {
role = role_param;
party = new ABYParty(role_param, address, port, seclvl, bitlen, nthreads, mt_alg, 4000000);
std::vector<Sharing*>& sharings = party->GetSharings();
ycirc = (sharings)[S_YAO]->GetCircuitBuildRoutine();
acirc = (sharings)[S_ARITH]->GetCircuitBuildRoutine();
bcirc = (sharings)[S_BOOL]->GetCircuitBuildRoutine();


auto inferenceQuery = make_vector<share*>(noOfFeatures);

auto modelFeatureChoice = make_vector<share*>(noOfTrees, noOfNodes);

auto modelThresholdValue = make_vector<share*>(noOfTrees, noOfNodes);

auto inferenceResult = make_vector<share*>(noOfTrees);

share* finalResult = put_cons64_gate(ycirc,  (uint64_t)0);
for (uint32_t i =  (int32_t)0; i < noOfFeatures; i++){
inferenceQuery[i] = put_cons64_gate(ycirc,  (uint64_t)20);
}
for (uint32_t i =  (int32_t)0; i < noOfTrees; i++){
for (uint32_t j =  (int32_t)0; j < noOfNodes; j++){
/* Temporary variable for sub-expression on source location: (239,31-239,57) */
uint32_t __tac_var115 = (noOfNodes % noOfFeatures);
/* Temporary variable for sub-expression on source location: (239,30-239,62) */
uint64_t __tac_var116 = (__tac_var115 +  (uint64_t)0);
modelFeatureChoice[i][j] = put_cons64_gate(ycirc, __tac_var116);
/* Temporary variable for sub-expression on source location: (240,31-240,48) */
uint64_t __tac_var117 = (noOfNodes +  (uint64_t)351);
modelThresholdValue[i][j] = put_cons64_gate(ycirc, __tac_var117);
}
}
infer(modelFeatureChoice, modelThresholdValue, inferenceQuery, inferenceResult);
for (uint32_t i =  (int32_t)0; i < noOfTrees; i++){
/* Temporary variable for sub-expression on source location: (247,16-247,27) */
share* __tac_var118 = acirc->PutY2AGate(finalResult, bcirc);
/* Temporary variable for sub-expression on source location: (247,33-247,51) */
share* __tac_var119 = inferenceResult[i];
/* Temporary variable for sub-expression on source location: (247,33-247,51) */
share* __tac_var120 = acirc->PutY2AGate(__tac_var119, bcirc);
/* Temporary variable for sub-expression on source location: (247,16-247,51) */
share* __tac_var121 = acirc->PutADDGate(__tac_var118, __tac_var120);
finalResult = ycirc->PutA2YGate(__tac_var121);
}
add_print_msg_to_output_queue(out_q, "Value of finalResult:", ALL, cout);
add_to_output_queue(out_q, ycirc->PutOUTGate(finalResult, ALL), ALL, cout);
party->ExecCircuit();
flush_output_queue(out_q, role, bitlen);
return 0;
}

