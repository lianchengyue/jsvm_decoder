#ifndef _MBDECODER_H_
#define _MBDECODER_H_


#include "H264AVCCommonLib/YuvPicBuffer.h"
#include "H264AVCCommonLib/YuvMbBuffer.h"
#include "H264AVCCommonLib/Transform.h"
#include "Typedefs.h"

namespace JSVM {

class Transform;
class IntraPrediction;
class MotionCompensation;

class Frame;
class YuvPicBuffer;
class YuvMbBuffer;

class MbDecoder
{

protected:
    MbDecoder();
    virtual ~MbDecoder();

public:
    static ErrVal create(MbDecoder*&  rpcMbDecoder);
    ErrVal destroy();

    ErrVal init(Transform*  pcTransform,
                IntraPrediction*  pcIntraPrediction,
                MotionCompensation*  pcMotionCompensation);
    ErrVal uninit();

    ErrVal decode(MbDataAccess&       rcMbDataAccess,
                  MbDataAccess*       pcMbDataAccessBase,
                  Frame*              pcFrame,
                  Frame*              pcResidualLF,
                  Frame*              pcResidualILPred,
                  Frame*              pcBaseLayer,
                  Frame*              pcBaseLayerResidual,
                  RefFrameList*       pcRefFrameList0,
                  RefFrameList*       pcRefFrameList1,
                  Bool                bReconstructAll);
    ErrVal calcMv(MbDataAccess&       rcMbDataAccess,
                  MbDataAccess*       pcMbDataAccessBaseMotion);

protected:
    ErrVal xDecodeMbPCM(MbDataAccess&       rcMbDataAccess,
                        YuvMbBuffer&        rcYuvMbBuffer);
    ErrVal xDecodeMbIntra4x4(MbDataAccess&       rcMbDataAccess,
                             YuvMbBuffer&        cYuvMbBuffer,
                             YuvMbBuffer&        rcPredBuffer);
    ErrVal xDecodeMbIntra8x8(MbDataAccess&       rcMbDataAccess,
                             YuvMbBuffer&        cYuvMbBuffer,
                             YuvMbBuffer&        rcPredBuffer);
    ErrVal xDecodeMbIntra16x16(MbDataAccess&       rcMbDataAccess,
                               YuvMbBuffer&        cYuvMbBuffer,
                               YuvMbBuffer&        rcPredBuffer);
    ErrVal xDecodeMbIntraBL(MbDataAccess&       rcMbDataAccess,
                            YuvPicBuffer*       pcRecYuvBuffer,
                            YuvMbBuffer&        rcPredBuffer,
                            YuvPicBuffer*       pcBaseYuvBuffer);
    ErrVal xDecodeMbInter(MbDataAccess&       rcMbDataAccess,
                          MbDataAccess*       pcMbDataAccessBase,
                          YuvMbBuffer&        rcPredBuffer,
                          YuvPicBuffer*       pcRecYuvBuffer,
                          Frame*              pcResidualLF,
                          Frame*              pcResidualILPred,
                          Frame*              pcBaseResidual,
                          RefFrameList&       rcRefFrameList0,
                          RefFrameList&       rcRefFrameList1,
                          Bool                bReconstruct,
                          Frame*              pcBaseLayerRec = 0);
    ErrVal xDecodeChroma(MbDataAccess&       rcMbDataAccess,
                         YuvMbBuffer&        rcRecYuvBuffer,
                         YuvMbBuffer&        rcPredBuffer,
                         UInt                uiChromaCbp,
                         Bool                bPredChroma,
                         Bool                bAddBaseCoeffsChroma = false);


    ErrVal xScaleTCoeffs(MbDataAccess&       rcMbDataAccess);
    ErrVal xScale4x4Block(TCoeff*             piCoeff,
                          const UChar*        pucScale,
                          UInt                uiStart,
                          const QpParameter&  rcQP);
    ErrVal xScale8x8Block(TCoeff*             piCoeff,
                          const UChar*        pucScale,
                          const QpParameter&  rcQP);
    ErrVal xAddTCoeffs(MbDataAccess&  rcMbDataAccess,
                       MbDataAccess&  rcMbDataAccessBase);


    ErrVal xPredictionFromBaseLayer(MbDataAccess&  rcMbDataAccess,
                                    MbDataAccess*  pcMbDataAccessBase);

protected:
    MbTransformCoeffs   m_cTCoeffs;
    Transform*          m_pcTransform;
    IntraPrediction*    m_pcIntraPrediction;
    MotionCompensation* m_pcMotionCompensation;
    Bool                m_bInitDone;
};

}  //namespace JSVM {

#endif //_MBDECODER_H_
