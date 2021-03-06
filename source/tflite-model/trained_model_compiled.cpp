/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 09.09.2021 18:49:42

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 1776;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,637 } };
const TfArray<1, float> quant0_scale = { 1, { 0.046185612678527832, } };
const TfArray<1, int> quant0_zero = { 1, { -5 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 208, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int32_t tensor_data2[8] = { -3059, -7842, -4472, -6302, -6032, -5477, -3578, -12126, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<8, float> quant2_scale = { 8, { 0.00051500258268788457, 0.00020936829969286919, 0.00036070068017579615, 0.00023582568974234164, 0.00025661170366220176, 0.00023394284653477371, 0.00029581153648905456, 0.00022789639479015023, } };
const TfArray<8, int> quant2_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int32_t tensor_data3[16] = { -2670, 227, -549, -535, -913, -38, -187, 345, -558, -1453, -5645, 420, -947, -20, -2098, 154, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<16, float> quant3_scale = { 16, { 0.0005796278128400445, 0.0011621080338954926, 0.0017173535889014602, 0.002272697864100337, 0.0019991167355328798, 0.00026079246890731156, 0.00079351390013471246, 0.0015908209607005119, 0.0015000323764979839, 0.0015862368745729327, 0.00017321751511190087, 0.0015740179223939776, 0.0014511379413306713, 0.0010841765906661749, 0.00090427650138735771, 0.00014148208720143884, } };
const TfArray<16, int> quant3_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[7] = { 1723, 1107, 2313, -4153, 2695, -155, -6089, };
const TfArray<1, int> tensor_dimension4 = { 1, { 7 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00032191225909627974, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[7*208] = { 
  -11, -25, -10, -30, -75, -32, 10, 5, 30, 14, -1, -5, 31, -15, 6, 11, -10, -28, -10, -33, -4, -15, -5, 3, 20, -1, -6, -4, 29, -4, 4, 6, -8, -36, -47, -3, -97, 1, -6, 3, 21, 11, 0, 0, 30, -21, 9, 3, -18, -25, -43, -28, -17, 3, 6, -17, 32, 14, -20, 3, 20, -15, -5, 1, -6, -35, -52, -9, -18, -9, -17, 0, 15, -6, 7, -5, 20, -8, -22, -7, -23, -40, -20, -11, -26, -14, -15, -4, 15, -15, -1, 13, 30, 1, -20, 5, -14, -29, -32, -15, -34, -29, -17, 9, 5, -34, -3, 3, 31, -1, -10, 3, -14, -32, -42, -14, -28, -6, -9, 14, -5, -21, 3, 0, 24, 0, -18, -6, -21, -40, -36, -5, -68, -12, -13, -12, 2, -31, -9, -6, 21, -16, -11, -6, -32, -35, -18, -6, -8, -26, -15, 5, 21, -15, -10, 3, 11, -12, 1, -8, -14, -29, -26, -7, -1, -2, -2, -16, 29, -21, 2, 8, 25, -11, 1, -5, -11, -40, -21, -8, -48, -20, -33, -17, 37, -7, 0, 5, 19, 3, 5, -14, -36, -50, -6, -25, -34, -52, -29, 1, 27, -8, -1, 2, 25, -16, 18, 1, 
  -51, 33, 5, 26, -8, 12, 11, -9, -18, -15, -30, -7, -33, 9, -15, -1, -40, 18, 10, 17, -9, 11, 6, -30, -27, -12, -14, -19, -35, 13, -27, -1, -3, 3, 23, 8, -5, 22, 12, -17, -29, -20, -11, -9, -32, -3, -26, 12, -25, 3, 26, 10, -29, 13, -8, -24, -24, -34, -13, 3, -22, -17, -34, -9, -35, 20, 14, 5, -19, 8, -18, -15, -41, 8, -8, -1, -18, 4, -39, -4, -19, 13, 7, 0, -4, 25, -17, -22, -36, 8, -12, -6, -35, 5, -30, -10, -23, 12, 1, 10, -34, 3, -11, 3, 1, -28, -21, -5, -16, 22, -23, -7, -22, 15, 19, 10, -37, 1, -13, -5, -31, -7, -2, -1, -51, 0, -24, -9, -8, 15, 11, 14, -2, 11, 1, -33, 3, -37, -24, -6, -43, 6, -30, -13, -13, 18, 20, 4, -18, 8, -14, -26, -13, -19, -7, 11, -48, 6, -12, -8, -32, 18, 12, 20, -24, 4, -13, -19, -28, -7, -17, 2, -32, 6, -1, -23, -34, 29, 14, 19, -15, 12, -2, -12, -23, -34, -5, -3, -54, 8, -11, -4, -62, 37, 1, 35, 1, 23, -10, -3, -21, -9, -24, -3, -35, -7, -63, 9, 
  -6, -29, -19, -16, 29, -5, -1, -28, -33, 4, -11, -24, -16, -5, 14, -2, 5, -17, -40, -24, 26, -9, -4, -3, -23, 1, -10, -11, 1, 6, 22, -1, -8, -27, -28, -31, 24, -14, -12, -17, -35, -9, -9, -2, 5, 4, 19, 0, -8, -17, -27, -11, 30, -8, -13, -2, -35, -23, 3, -5, 13, -10, 3, -2, 1, 11, -15, -42, 43, -12, -14, -13, -38, -2, -6, -8, -29, 10, 11, -9, -6, -47, -20, -5, 36, -6, -28, -9, -48, -39, -10, -14, -16, -2, -6, -11, 2, -51, -15, -29, 49, -7, -13, -29, -52, -22, -5, 3, -19, -5, 4, -7, 7, -15, -14, -24, 27, -1, -7, -15, -19, -21, -10, -9, -10, -19, 2, -14, -4, -35, -32, -41, 40, -7, -28, -1, -31, -12, -7, 6, -23, -4, 4, -2, -6, -7, -23, -26, 34, -5, -9, -16, -22, -4, -8, 0, -17, -19, 0, -15, 0, -20, -26, -23, 34, -1, 2, -4, -27, -3, 2, 2, -6, -6, -5, -13, -3, 3, -5, -29, 27, -7, -12, -5, -48, 2, 2, -8, -6, -11, 1, -16, -19, -31, -1, -32, 26, -9, 2, 16, -52, -33, -25, 3, 2, 1, 6, 3, 
  1, 23, 28, 19, -40, -6, -3, 25, 30, -29, 6, 8, -12, -63, 28, 1, 0, -7, 15, 3, -54, -42, -16, 29, 4, -24, -45, 27, -4, -62, 3, -8, -5, 1, 21, 12, -30, -9, -17, 50, 27, -13, -16, 14, -3, -56, 9, -4, -2, 25, 13, 1, -28, -14, -30, 32, 23, -14, 2, 7, -2, -29, 6, -4, 12, 10, 11, 18, -35, 2, -33, 34, 26, -20, 8, 15, -14, -28, 8, 14, 10, 28, 9, 4, -13, -30, -29, 36, 24, -19, -7, 16, -7, -45, 11, -2, 0, 32, 7, 22, -25, 17, -27, 41, 29, -40, 5, -9, -5, -42, 18, -7, 3, 33, 24, 3, -21, -12, -47, 36, 6, -49, -29, 1, -24, -8, 4, -32, 7, 24, 18, 28, -9, -6, -31, 35, 25, -24, -5, 15, -3, -35, 4, -30, -4, 27, 3, 18, -27, -40, -26, 32, 26, -21, -9, 14, -12, -17, 8, -2, -7, 11, 9, 27, -19, -15, -37, 34, 11, -27, -15, 19, -6, -40, 18, -7, 7, 3, 2, 26, -37, -13, -22, 43, 26, 7, -17, 5, -13, -67, 18, -6, -13, 24, 5, -13, -6, -43, -8, 14, 12, 5, -66, 11, -25, -56, 17, -30, 
  12, 16, -11, -12, -33, -21, -17, -17, -8, -4, 11, -24, 1, -19, -15, 12, 14, 10, 2, -14, -38, -16, -17, -19, -13, -12, 17, -17, -7, -13, -21, 11, 10, 4, 2, -10, 0, -20, 7, -17, 5, -15, 20, -22, -22, -21, -27, 13, 10, 1, -9, -8, -13, -15, -14, -8, -5, -3, 14, -24, -43, -4, -16, 11, 17, 15, 1, -8, -23, -28, 1, -11, 5, 8, 9, -31, -24, 1, -2, 12, 9, 6, -20, -7, -46, -10, -15, -26, 3, -11, 18, -28, -25, -15, -20, 10, 11, 2, -20, -8, -26, -8, -1, -9, 1, -2, 7, -19, -30, -23, -3, 21, 15, 17, -6, -18, -14, -25, 7, -15, -10, 5, 11, -22, -6, -15, -22, 16, 9, -10, -7, -2, -26, -15, 9, -10, -30, 17, 13, -29, -13, -22, -4, 6, 10, 14, -9, -19, -8, -16, 4, -13, -13, -16, 7, -24, -17, -10, -12, 4, 11, 2, -15, -20, -34, -20, 1, -5, 9, 1, 9, -28, -9, -16, -5, 19, 5, 0, -6, -22, -25, -20, 9, -25, -17, 17, 6, -28, -7, -23, -4, 10, 25, -8, -21, -42, -37, -21, -10, 7, -5, -1, 6, -17, -18, -23, -22, -14, 
  -6, 0, -31, 1, -7, 22, 16, 3, -35, -22, -41, -24, -8, 31, -1, -1, 2, -18, -18, -10, 12, 13, 15, -9, -26, -32, -18, -32, -5, 26, -20, -6, 0, -16, -42, -15, -2, 23, 2, -8, -27, -49, -22, -14, -10, 24, -29, 0, 2, -29, -62, 13, -19, 18, 4, -4, -53, -4, -15, -4, -33, 12, -23, -4, -10, -40, -96, -3, -30, 20, -2, -16, -23, -39, -11, -9, -24, 16, -55, -13, -3, -54, -52, -8, -25, 24, 18, -10, -69, -36, -19, -3, -9, 11, -19, -2, 8, -39, -46, -4, -64, 13, -5, -24, -40, -38, -7, 4, -12, 23, -37, -13, 16, -50, -29, 12, -48, 25, 3, -35, 3, -18, -4, 3, -1, 17, -19, -17, -17, -28, -59, -13, -46, 13, 5, -21, -35, -27, -25, 2, -19, 13, -25, -15, 5, -25, -72, -4, -23, 19, 15, -8, -11, -47, -26, -8, -33, 20, -16, -9, 4, -58, -36, -4, -15, 22, 16, -10, -23, -34, -7, -6, -23, 17, -25, -11, -1, -11, -93, -4, -13, 19, 13, 0, -38, -45, -13, -10, -22, 13, -27, -5, 1, -26, -38, -7, -8, 26, 16, -27, -75, -52, 0, -20, 3, 15, -36, 16, 
  7, -39, -44, -12, -12, 3, -83, -3, -6, 4, 8, 38, -4, 7, -12, -53, 14, -12, -12, -19, -10, -6, -34, 1, -3, 14, 8, 43, -12, 6, 12, -52, 12, 2, 17, -2, 8, -4, 2, -4, -4, 25, 11, 29, 10, 0, 17, -46, 11, 7, 19, -14, 5, -8, 19, -7, -1, 24, 2, 20, 14, 1, 22, -28, 7, 18, 20, -13, -2, 3, 20, 12, -12, 25, 5, 13, 10, -4, 15, -17, 2, 9, 18, -35, -6, -14, 26, 1, 10, 25, 7, 10, 15, -12, 17, -11, -3, 4, 14, -19, 6, -12, 37, 2, -12, 26, -4, -1, 17, -1, 18, -13, 9, 11, 23, -18, 1, -21, 23, -16, 3, 26, -3, 2, 15, -10, 16, -11, 6, 5, 9, -2, 9, -3, 30, -9, -5, 32, -2, -3, 15, 4, 9, 1, 4, -5, 14, -8, -22, -1, 15, -3, -8, 36, 1, 19, 2, 9, 14, 3, 4, -1, 12, -9, 3, 1, 8, -11, -2, 28, 9, 20, 9, 10, 16, 3, 10, -12, -6, -10, -17, -12, -3, -11, -5, 1, 14, 22, -11, 1, 7, 7, 30, -42, -13, -57, -4, 4, -59, -10, -15, -31, 36, 16, -1, 3, -9, -127, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 7,208 } };
const TfArray<1, float> quant5_scale = { 1, { 0.015003322623670101, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int8_t tensor_data6[8*1*3*13] = { 
  /* [0][0][][] */ 29,41,15,-1,4,18,8,-3,9,5,1,0,1, 101,-38,-15,-36,-41,-1,4,-18,11,-10,10,2,-5, -127,102,28,10,7,35,-4,8,9,-6,19,9,9, 
  /* [1][0][][] */ 89,102,108,-123,-6,-4,-4,0,39,-12,12,20,-2, 6,50,77,-83,-28,-27,-8,5,30,-14,4,18,-17, 59,75,127,-119,-51,30,-67,22,-24,17,12,0,3, 
  /* [2][0][][] */ 111,46,-66,7,32,21,16,14,-16,-11,9,-2,-29, 78,11,-74,52,-23,37,4,-27,-40,-18,23,14,-19, 127,24,-95,10,9,10,29,4,-34,18,-15,-7,-13, 
  /* [3][0][][] */ -50,127,-25,69,70,-59,11,12,-38,55,-72,55,25, -35,94,-18,57,68,-51,-15,61,-51,64,-73,37,2, 8,76,-14,53,80,-53,-9,54,-73,79,-47,32,-5, 
  /* [4][0][][] */ -104,21,-56,38,38,69,14,53,-38,-13,43,-5,12, -127,-33,-84,8,15,83,-13,22,-42,-10,22,-27,-25, -58,-46,-53,52,55,72,9,37,-24,-49,24,16,-25, 
  /* [5][0][][] */ -3,110,-57,-43,52,-75,-14,-48,43,17,-13,-27,10, 37,109,-34,-63,45,-127,38,-7,8,32,11,-39,-30, -10,73,-54,-16,78,-100,40,16,10,18,27,-55,28, 
  /* [6][0][][] */ -89,-34,67,-19,-66,-50,34,3,-14,-8,-13,23,-11, -99,20,78,17,37,-5,20,-10,6,0,-9,-6,-4, -127,-12,100,-41,-32,-45,-5,-23,-16,-8,-45,15,-13, 
  /* [7][0][][] */ 79,-52,-52,-74,58,43,-119,-73,62,-13,16,7,21, -26,-24,-62,8,32,35,-54,-90,82,5,-27,31,33, -66,-54,-114,-21,66,72,-76,-100,127,-25,-29,24,-29, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant6_scale = { 8, { 0.011150714010000229, 0.0045331930741667747, 0.0078098061494529247, 0.0051060421392321587, 0.0055560958571732044, 0.0050652753561735153, 0.0064048417843878269, 0.0049343588761985302, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[16*1*3*8] = { 
  /* [0][0][][] */ -4,7,-7,4,-16,16,32,-18, -5,3,-35,8,-28,6,1,-105, 20,5,-127,6,-7,5,29,-101, 
  /* [1][0][][] */ 1,2,-14,-7,-33,-17,-11,-4, -5,12,-18,-95,-127,-10,-8,-5, 1,1,-28,-19,-20,-15,0,-21, 
  /* [2][0][][] */ 0,13,-7,1,-127,-2,-6,-8, 1,-2,-5,1,-110,-3,-4,-54, -1,7,-16,2,-28,-4,1,-49, 
  /* [3][0][][] */ -2,-127,-5,3,0,-1,-7,0, -1,-76,-4,2,11,-2,-8,-2, 1,-2,-7,2,0,2,-7,4, 
  /* [4][0][][] */ -16,13,0,2,-3,-4,2,17, -3,-2,0,-18,-5,-10,-24,0, -5,-7,1,-87,-14,-127,-58,7, 
  /* [5][0][][] */ -40,-32,-56,-15,4,-13,-11,10, -48,-55,-27,66,-10,-34,-29,-11, -60,-127,-55,-8,1,-5,-14,-13, 
  /* [6][0][][] */ 5,5,7,-43,-46,-15,-127,1, 7,-2,1,-34,-45,-17,-44,-2, 7,13,10,-1,-94,-4,-27,-8, 
  /* [7][0][][] */ -10,-35,-14,-34,2,-24,-8,0, -4,-127,-4,-69,-1,-18,-14,-5, -4,-38,-4,-7,3,-13,-13,-7, 
  /* [8][0][][] */ -11,-110,-2,-2,9,-104,2,-1, -10,-100,-4,-6,0,-127,0,-6, -5,-2,-2,-6,11,-105,3,-4, 
  /* [9][0][][] */ -8,0,10,3,-11,3,-73,2, -8,-2,-1,3,-5,5,-127,-2, -3,-9,9,-4,3,3,-59,-5, 
  /* [10][0][][] */ 64,-6,-36,-55,-2,19,12,-66, 69,-31,-74,-60,30,-27,127,35, 58,1,-17,-28,-21,-61,-32,-30, 
  /* [11][0][][] */ -21,-31,-127,-1,0,-4,1,-1, -5,-20,-82,-5,0,1,-1,0, -30,-10,-115,-1,0,1,2,1, 
  /* [12][0][][] */ -2,3,-5,-12,-127,17,-14,5, 0,5,-3,-18,-53,-2,-70,7, 0,-1,0,-17,-22,14,-37,3, 
  /* [13][0][][] */ -11,-37,-111,10,0,-1,6,2, -32,-127,-95,-4,-1,0,2,-9, -22,-101,-31,9,-2,-2,3,-15, 
  /* [14][0][][] */ -3,10,12,6,-5,3,4,-5, -2,-3,-4,0,-127,14,0,-31, 4,18,2,8,-69,3,-4,-21, 
  /* [15][0][][] */ -28,-11,9,-79,-3,-2,-69,-89, 127,-25,-4,-28,-34,8,-97,-35, 25,-55,-39,-3,-11,-17,3,4, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant7_scale = { 16, { 0.011789546348154545, 0.023637110367417336, 0.034930724650621414, 0.046226348727941513, 0.040661748498678207, 0.0053044813685119152, 0.016139958053827286, 0.032357070595026016, 0.030510442331433296, 0.032263830304145813, 0.0035232193768024445, 0.032015297561883926, 0.029515936970710754, 0.022051995620131493, 0.018392853438854218, 0.002877725288271904, } };
const TfArray<16, int> quant7_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[4] = { 1, 1, 49, 13, };
const TfArray<1, int> tensor_dimension8 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data9[4] = { 1, 49, 1, 8, };
const TfArray<1, int> tensor_dimension9 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data10[4] = { 1, 1, 25, 8, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[4] = { 1, 25, 1, 16, };
const TfArray<1, int> tensor_dimension11 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,49,13 } };
const TfArray<1, float> quant12_scale = { 1, { 0.046185612678527832, } };
const TfArray<1, int> quant12_zero = { 1, { -5 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,49,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.049164555966854095, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,49,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.049164555966854095, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,25,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.049164555966854095, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,25,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.049164555966854095, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,25,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.021456064656376839, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.021456064656376839, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,13,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.021456064656376839, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,208 } };
const TfArray<1, float> quant20_scale = { 1, { 0.021456064656376839, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,7 } };
const TfArray<1, float> quant21_scale = { 1, { 0.078916892409324646, } };
const TfArray<1, int> quant21_zero = { 1, { 33 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,7 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,8 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,2 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,9 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,10 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,7,3 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,11 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,1 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,5,4 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension0, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 28, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 1456, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension13, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension15, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension17, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension19, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 208, (TfLiteIntArray*)&tensor_dimension21, 7, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 7, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for(size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
