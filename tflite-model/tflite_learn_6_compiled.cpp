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
// Generated on: 27.04.2024 00:18:46

#include <stdio.h>
#include <stdlib.h>
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
#elif defined __ICCARM__
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 1408;
#else
constexpr int kTensorArenaSize = 384;
#endif

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
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};

struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];

namespace g0 {
const TfArray<2, int> tensor_dimension0 = { 2, { 1,39 } };
const TfArray<1, float> quant0_scale = { 1, { 31.902341842651367, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { 1, -1, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const TfArray<1, float> quant1_scale = { 1, { 0.037563201040029526, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(16) int8_t tensor_data2[2*10] = { 
  75, -100, 72, 114, 127, -79, -43, -104, 27, 91, 
  68, 12, -23, -30, -100, -1, -118, 52, -111, 34, 
};
const TfArray<2, int> tensor_dimension2 = { 2, { 2,10 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0055704433470964432, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(16) int32_t tensor_data3[10] = { 1, 0, 0, 1, 0, 0, 1, -1, 2, 1, };
const TfArray<1, int> tensor_dimension3 = { 1, { 10 } };
const TfArray<1, float> quant3_scale = { 1, { 0.039123188704252243, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(16) int8_t tensor_data4[10*20] = { 
  44, -79, -70, 18, 108, 22, 125, -110, -4, -55, 18, 25, 73, 127, 61, -85, 3, -24, -76, 26, 
  -61, -127, 69, 68, 58, -48, -60, -108, -100, 20, -56, -61, 64, 20, 71, 93, -58, 33, -48, -33, 
  -24, -104, -3, 113, -52, -64, -38, 22, -44, -12, 35, 55, -23, -93, -14, -75, 91, -105, -108, -87, 
  63, 14, 105, 4, -68, 90, -59, -46, -26, 79, 100, 58, -78, -101, -2, -48, -40, -47, 114, 90, 
  -49, 69, -100, -42, -91, 79, -35, 33, -99, 66, 97, 66, -18, 57, 31, -98, -48, 112, 78, 62, 
  -94, 75, -76, 54, -33, -126, -8, 83, -125, -51, 84, 64, -56, 67, -27, -74, -41, 66, -73, 4, 
  99, 51, -61, -85, 88, 90, 14, -35, -26, 3, 60, 48, -77, -44, 11, -19, 52, -9, -17, -37, 
  -16, 94, 47, 62, -14, 88, 91, -122, 120, -32, -57, 117, 68, -33, -110, 50, 90, 2, 15, 90, 
  67, 33, 65, 33, 99, 52, -112, -25, -27, 13, 98, 33, -29, -124, -34, 92, -103, 86, -51, -35, 
  47, -73, -14, 2, 88, 113, -18, 14, 86, -100, -72, 57, -76, -54, 63, -16, -17, 100, 3, 83, 
};
const TfArray<2, int> tensor_dimension4 = { 2, { 10,20 } };
const TfArray<1, float> quant4_scale = { 1, { 0.0035547276493161917, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int32_t tensor_data5[20] = { 0, 0, 0, 0, 1, 1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension5 = { 1, { 20 } };
const TfArray<1, float> quant5_scale = { 1, { 0.095033034682273865, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int8_t tensor_data6[20*39] = { 
  0, -15, -23, 87, 30, 51, 30, -68, 35, -84, -3, 38, -93, -69, -23, 93, 26, 76, -51, -51, 91, -27, 88, 19, -97, 67, -51, -52, -73, -95, 25, 32, 63, -87, -99, 45, -66, 76, -10, 
  -99, -12, 81, 18, -26, 22, 38, 36, 51, 102, -63, 49, 19, 24, 69, -61, 87, 57, 111, -58, -13, -6, 92, -15, 58, 56, -14, 75, -21, -73, -12, 103, 96, 107, 77, -28, -79, -5, 32, 
  65, -10, -85, -67, 53, -50, 71, 95, 108, -2, -72, 24, -69, 47, -66, 78, 36, 56, 6, 50, 110, -94, 64, -78, 18, -19, 105, 52, -62, -74, -45, 78, 62, -68, -12, -26, -82, 2, 69, 
  -92, 60, -51, 58, -13, 57, -15, 97, 48, -94, 81, 80, 46, 60, 41, -19, -85, -56, 30, 62, -74, 38, -73, -44, 59, 49, -80, 63, 84, 64, -52, 39, 84, -52, 59, 9, 99, -106, 15, 
  83, 17, 32, -45, -62, -59, 109, -5, -29, 83, -10, 40, -45, -45, -85, 55, 78, 55, 11, -4, 9, 118, 0, 4, -13, 26, 82, 68, -100, -62, 71, -48, 114, -55, -13, -31, -12, -76, 44, 
  -30, 74, 31, 17, -14, -64, 31, 126, -20, 44, -78, -17, -84, 54, 11, -8, -79, 22, -12, 29, -62, -67, 10, -32, 98, -7, 37, -19, -49, 127, 3, 10, 103, -44, 45, -78, 93, -40, 64, 
  51, -25, -53, -77, -85, -121, -53, 57, -55, -9, -22, -26, -17, 57, 50, -11, -58, -43, 86, 64, -68, 2, -66, 50, -60, -28, 99, -84, 85, 7, 50, -116, -17, -31, -101, 43, -114, 25, -104, 
  79, -109, 34, 103, 104, 42, 41, 55, -22, 101, -10, 114, -25, 46, -76, -108, -25, -60, -60, 111, 99, -56, -44, 10, -12, 114, -26, 26, -95, -2, 37, 110, 35, -80, -26, -86, -6, 41, 85, 
  58, 106, 50, -34, -108, 50, -28, -78, -24, -33, -9, 49, 45, -42, 25, -43, 31, -37, 89, 6, 81, 56, 79, 27, 49, 52, 70, -7, 87, -110, 41, -116, -31, -17, -103, -46, -109, 73, -86, 
  -89, 48, -90, -7, -62, 63, -97, -1, -58, -107, -91, -73, -107, -28, -68, 83, -12, 62, 75, -68, -22, 67, 21, 99, 107, 72, 6, 31, -3, 48, -47, -30, -77, -3, 75, 32, 72, 80, -15, 
  92, 24, 59, -101, -85, -42, 62, 17, -6, 36, -80, 32, 29, -92, 41, -63, -4, -10, 37, 23, -90, 50, -97, 84, 88, -18, -60, -33, 88, 74, -99, -84, -84, -23, 107, 94, -29, -82, -82, 
  -12, 40, 88, -39, -88, -102, 98, -49, 71, -32, 84, 90, 60, 102, -34, 48, -50, -29, 88, -4, -31, -30, 94, -4, 25, 35, 66, 52, 103, 33, -16, -30, -3, -51, 21, -31, -81, 19, 20, 
  -53, -99, 4, -38, 61, -96, -67, -107, -90, 47, -29, -102, 22, 52, -36, 83, 9, -39, 84, -33, 45, 55, -71, 62, 49, -37, 5, -51, 85, -32, -49, 21, -106, 92, 62, 62, 82, -74, -94, 
  30, -111, -63, -1, 100, 108, -85, 104, -10, 30, 25, 33, 99, 33, -16, -80, -102, -12, -81, -35, -77, -79, -1, -30, -41, -102, -67, 90, -13, 13, 37, -98, -74, -98, -10, 31, 53, -3, 90, 
  97, -95, -46, 35, 22, -49, -33, 50, 64, 49, 117, -91, -77, 107, -112, -47, -82, 5, 74, -70, 103, 117, -39, 91, -85, -49, -11, -91, 87, -14, 123, -43, -34, 80, -2, -56, -70, 39, 99, 
  -5, 94, -74, -105, -104, 24, -18, 13, 34, 30, -11, 36, -64, 45, 45, 87, 13, 42, 32, 58, -102, 84, -91, 42, 20, -4, -52, -38, -25, -63, 23, -42, -43, 51, -13, 18, -5, -103, 22, 
  10, -69, -44, -12, 84, -29, -39, -80, 35, -97, -96, -37, 21, 49, -29, 44, -83, -45, 43, -38, -93, -66, 36, -50, 39, -39, -10, 83, -81, 70, 31, -3, 80, -67, -36, -60, 27, -95, -52, 
  -15, 49, 90, 78, 81, -30, -38, 92, 40, -11, -35, 107, -35, 80, -70, -40, -70, 32, 102, -54, 61, -41, -75, 108, -54, -80, -52, 34, -3, -58, -10, -78, 6, 29, 12, 107, 104, -54, 77, 
  -90, -27, 57, -104, 51, 9, -69, -10, -3, -37, -98, -41, -91, -75, -79, -55, 7, -63, -58, 41, -53, 88, -58, 84, -46, -93, -4, -30, -95, -74, 49, -46, -67, -96, 105, 84, 29, -72, -82, 
  -3, 80, 6, -52, -18, -35, 32, -14, 77, 72, -86, 84, 73, -1, -2, -44, -3, -89, -57, 29, -40, -98, 83, -84, -7, 3, -69, -45, 38, 84, -74, 16, 90, -66, 9, 37, -97, 23, 6, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 20,39 } };
const TfArray<1, float> quant6_scale = { 1, { 0.0029788732063025236, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const TfArray<2, int> tensor_dimension7 = { 2, { 1,20 } };
const TfArray<1, float> quant7_scale = { 1, { 11.005959510803223, } };
const TfArray<1, int> quant7_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<2, int> tensor_dimension8 = { 2, { 1,10 } };
const TfArray<1, float> quant8_scale = { 1, { 6.7433052062988281, } };
const TfArray<1, int> quant8_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,2 } };
const TfArray<1, float> quant9_scale = { 1, { 2.9245913028717041, } };
const TfArray<1, int> quant9_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,2 } };
const TfArray<1, float> quant10_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,6,5 } };
const TfArray<1, int> outputs0 = { 1, { 7 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 7,4,3 } };
const TfArray<1, int> outputs1 = { 1, { 8 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 8,2,1 } };
const TfArray<1, int> outputs2 = { 1, { 9 } };
const TfLiteSoftmaxParams opdata3 = { 1 };
const TfArray<1, int> inputs3 = { 1, { 9 } };
const TfArray<1, int> outputs3 = { 1, { 10 } };
};

TensorInfo_t tensorData[] = {
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension0, 39, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant0))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data1, (TfLiteIntArray*)&g0::tensor_dimension1, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant1))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data2, (TfLiteIntArray*)&g0::tensor_dimension2, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant2))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data3, (TfLiteIntArray*)&g0::tensor_dimension3, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant3))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data4, (TfLiteIntArray*)&g0::tensor_dimension4, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant4))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data5, (TfLiteIntArray*)&g0::tensor_dimension5, 80, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant5))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data6, (TfLiteIntArray*)&g0::tensor_dimension6, 780, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant6))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 48), (TfLiteIntArray*)&g0::tensor_dimension7, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant7))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension8, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant8))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 16), (TfLiteIntArray*)&g0::tensor_dimension9, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant9))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension10, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant10))}, },
};

#ifndef TF_LITE_STATIC_MEMORY
TfLiteNode tflNodes[4] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
};
#else
TfLiteNode tflNodes[4] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
};
#endif

used_operators_e used_ops[] =
{OP_FULLY_CONNECTED, OP_FULLY_CONNECTED, OP_FULLY_CONNECTED, OP_SOFTMAX, };


// Indices into tflTensors and tflNodes for subgraphs
const size_t tflTensors_subgraph_index[] = {0, 11, };
const size_t tflNodes_subgraph_index[] = {0, 4, };

// Input/output tensors
static const int in_tensor_indices[] = {
  0, 
};

static const int out_tensor_indices[] = {
  10, 
};


size_t current_subgraph_index = 0;

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = false;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}

typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;

static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
 
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  }

  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }

  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }
 
  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }

  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }

  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }

};


} // namespace

TfLiteStatus tflite_learn_6_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  
  // Set microcontext as the context ptr
  ctx.impl_ = static_cast<void*>(&micro_context_);
  // Setup tflitecontext functions
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.ReportError = &MicroContextReportOpError;

  ctx.tensors_size = 11;
  for (size_t i = 0; i < 11; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }

  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }

  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].init) {
        tflNodes[i].user_data = registrations[used_ops[i]].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
      }
    }
  }
  current_subgraph_index = 0;

  for(size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].prepare) {
        ResetTensors();
        TfLiteStatus status = registrations[used_ops[i]].prepare(&ctx, &tflNodes[i]);
        if (status != kTfLiteOk) {
          return status;
        }
      }
    }
  }
  current_subgraph_index = 0;

  return kTfLiteOk;
}

TfLiteStatus tflite_learn_6_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(in_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_6_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(out_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_6_invoke() {
  for (size_t i = 0; i < 4; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[used_ops[i]].invoke(&ctx, &tflNodes[i]);

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

TfLiteStatus tflite_learn_6_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}