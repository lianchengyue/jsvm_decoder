#ifndef _SLICEDECODER_H_
#define _SLICEDECODER_H_

#include "H264AVCCommonLib/ControlMngIf.h"
#include "Typedefs.h"

namespace JSVM {


class MbDecoder;
class Frame;

class SliceDecoder
{
protected:
    SliceDecoder();
    virtual ~SliceDecoder();

public:
    static ErrVal create(SliceDecoder*&  rpcSliceDecoder);
    ErrVal destroy();

    ErrVal init(MbDecoder* pcMbDecoder, ControlMngIf* pcControlMng);
    ErrVal uninit();

    ErrVal  decode(SliceHeader&   rcSH,
                   MbDataCtrl*    pcMbDataCtrl,
                   MbDataCtrl*    pcMbDataCtrlBase,
                   Frame*         pcFrame,
                   Frame*         pcResidualLF,
                   Frame*         pcResidualILPred,
                   Frame*         pcBaseLayer,
                   Frame*         pcBaseLayerResidual,
                   RefFrameList*  pcRefFrameList0,
                   RefFrameList*  pcRefFrameList1,
                   MbDataCtrl*    pcMbDataCtrl0L1,
                   Bool           bReconstructAll);

    ErrVal decodeMbAff(SliceHeader&   rcSH,
                       MbDataCtrl*    pcMbDataCtrl,
                       MbDataCtrl*    pcMbDataCtrlBase,
                       MbDataCtrl*    pcMbDataCtrlBaseField,
                       Frame*         pcFrame,
                       Frame*         pcResidualLF,
                       Frame*         pcResidualILPred,
                       Frame*         pcBaseLayer,
                       Frame*         pcBaseLayerResidual,
                       RefFrameList*  pcRefFrameList0,
                       RefFrameList*  pcRefFrameList1,
                       MbDataCtrl*    pcMbDataCtrl0L1,
                       Bool           bReconstructAll);

    Void setIntraBLFlagArrays(Bool* apabBaseModeFlagAllowedArrays[2])
    {
        m_apabBaseModeFlagAllowedArrays[0] = apabBaseModeFlagAllowedArrays[0];
        m_apabBaseModeFlagAllowedArrays[1] = apabBaseModeFlagAllowedArrays[1];
    }

protected:
    Bool            m_bInitDone;
    ControlMngIf*   m_pcControlMng;
    MbDecoder*      m_pcMbDecoder;
    Bool*           m_apabBaseModeFlagAllowedArrays[2];
};


}  //namespace JSVM {


#endif //_SLICEDECODER_H_
