#ifndef _H264AVCDECODER_H_
#define _H264AVCDECODER_H_


#include "GOPDecoder.h"
#include "H264AVCCommonLib/Sei.h"
#include "H264AVCCommonLib/MotionCompensation.h"
#include "H264AVCCommonLib/LoopFilter.h"

namespace JSVM {


class SliceReader;
class SliceDecoder;
class PocCalculator;
class LoopFilter;
class HeaderSymbolReadIf;
class ParameterSetMng;
class NalUnitParser;
class ControlMngIf;
class AccessUnit;
class NALUnit;
class NonVCLNALUnit;


class H264AVCDecoder
{
protected:
    H264AVCDecoder();
    virtual ~H264AVCDecoder();

public:
    //===== creation and initialization =====
    static  ErrVal create(H264AVCDecoder*&  rpcH264AVCDecoder);
    ErrVal  destroy();
    ErrVal  init(NalUnitParser*      pcNalUnitParser,
                 HeaderSymbolReadIf* pcHeaderSymbolReadIf,
                 ParameterSetMng*    pcParameterSetMngAUInit,
                 ParameterSetMng*    pcParameterSetMngDecode,
                 LayerDecoder*       apcLayerDecoder[MAX_LAYERS]);
    ErrVal  uninit();

    //===== main processing functions =====
    ErrVal  initNALUnit(BinData*&   rpcBinData,
                        AccessUnit& rcAccessUnit);
    ErrVal  processNALUnit(PicBuffer*      pcPicBuffer,
                           PicBufferList&  rcPicBufferOutputList,
                           PicBufferList&  rcPicBufferUnusedList,
                           BinDataList&    rcBinDataList,
                           NALUnit&        rcNALUnit);

    //===== update decoded picture buffer of all layers =====
    ErrVal  updateDPB(UInt uiTargetDependencyId,
                      PicBufferList&  rcPicBufferOutputList,
                      PicBufferList&  rcPicBufferUnusedList);

    //===== get inter-layer prediction data =====
    ErrVal  getBaseLayerData(SliceHeader&      rcELSH,
                             Frame*&           pcFrame,
                             Frame*&           pcResidual,
                             MbDataCtrl*&      pcMbDataCtrl,
                             ResizeParameters& rcResizeParameters,
                             UInt              uiBaseLayerId);
    ErrVal  getBaseSliceHeader(SliceHeader*& rpcSliceHeader,
                               UInt          uiRefLayerDependencyId);

protected:
    ErrVal  xProcessNonVCLNALUnit(NonVCLNALUnit& rcNonVCLNALUnit);


protected:
    Bool                m_bInitDone;
    NalUnitParser*      m_pcNalUnitParser;
    HeaderSymbolReadIf* m_pcHeaderSymbolReadIf;
    ParameterSetMng*    m_pcParameterSetMngAUInit;
    ParameterSetMng*    m_pcParameterSetMngDecode;
    LayerDecoder*       m_apcLayerDecoder[MAX_LAYERS];
    UInt                m_auiLastDQTPId[4];  //only for setting correct parameters in filler data instances
};

}  //namespace JSVM {

#endif //_H264AVCDECODER_H_
