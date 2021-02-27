#ifndef _TABLES_H_
#define _TABLES_H_

#include "Typedefs.h"

namespace JSVM {

extern const UChar g_aucInvFrameScan     [16];
extern const UChar g_aucFrameScan        [16];
extern const UChar g_aucIndexChromaDCScan[4];
extern const UChar g_aucLumaFrameDCScan  [16];
extern const UChar g_aucFieldScan        [16];
extern const UChar g_aucLumaFieldDCScan  [16];
extern const Int   g_aaiQuantCoef     [6][16];
extern const Int   g_aaiDequantCoef   [6][16];
extern const UChar g_aucChromaScale      [52];


extern const UChar g_aucInvFrameScan64   [64];
extern const UChar g_aucFrameScan64      [64];
extern const UChar g_aucFieldScan64      [64];
extern const Int   g_aaiDequantCoef64 [6][64];
extern const Int   g_aaiQuantCoef64   [6][64];

extern const UChar g_aucScalingMatrixDefault4x4Intra[16];
extern const UChar g_aucScalingMatrixDefault4x4Inter[16];
extern const UChar g_aucScalingMatrixDefault8x8Intra[64];
extern const UChar g_aucScalingMatrixDefault8x8Inter[64];


}  //namespace JSVM {


#endif //_TABLES_H_

