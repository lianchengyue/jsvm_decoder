#ifndef _CREATERH264AVCENCODER_H_
#define _CREATERH264AVCENCODER_H_

#include "Typedefs.h"

namespace JSVM {


class H264AVCEncoder;
class MbData;
class BitWriteBuffer;
class Transform;
class YuvBufferCtrl;
class QuarterPelFilter;
class ParameterSetMng;
class LoopFilter;
class SampleWeighting;
class PocCalculator;

class BitCounter;
class SliceEncoder;
class UvlcWriter;
class MbCoder;
class MbEncoder;
class IntraPredictionSearch;
class CodingParameter;
class CabacWriter;
class NalUnitEncoder;
class Distortion;
class MotionEstimation;
class MotionEstimationQuarterPel;
class RateDistortion;
class RateDistortionRateConstraint;
class History;
class LayerEncoder;
class XDistortion;
class ControlMngH264AVCEncoder;
class ReconstructionBypass;
class PicEncoder;
// JVT-V068 {
class Scheduler;
class SequenceParameterSet;
// JVT-V068 }


class CreaterH264AVCEncoder
{
protected:
    CreaterH264AVCEncoder();
    virtual ~CreaterH264AVCEncoder();

public:
    static ErrVal create(CreaterH264AVCEncoder*& rpcCreaterH264AVCEncoder);
    ErrVal destroy();

    ErrVal init(CodingParameter* pcCodingParameter);
    ErrVal uninit();
    ErrVal writeParameterSets(ExtBinDataAccessor* pcExtBinDataAccessor,
                              SequenceParameterSet*& rpcAVCSPS,
                              Bool&               rbMoreSets);

// JVT-V068 {
    ErrVal writeAVCCompatibleHRDSEI( ExtBinDataAccessor* pcExtBinDataAccessor, SequenceParameterSet*pcAVCSPS);
// JVT-V068 }

    ErrVal process(ExtBinDataAccessorList&  rcExtBinDataAccessorList,
                   PicBuffer*  apcOriginalPicBuffer[MAX_LAYERS],
                   PicBuffer*  apcReconstructPicBuffer[MAX_LAYERS],
                   PicBufferList* apcPicBufferOutputList,
                   PicBufferList* apcPicBufferUnusedList);

    ErrVal finish (ExtBinDataAccessorList&  rcExtBinDataAccessorList,
                   PicBufferList* apcPicBufferOutputList,
                   PicBufferList* apcPicBufferUnusedList,
                   UInt&   ruiNumCodedFrames,
                   Double& rdHighestLayerOutputRate);
    Bool getScalableSeiMessage (void);
    Void SetVeryFirstCall(void);
    //JVT-S080 LMI {
    ErrVal xWriteScalableSEILayersNotPresent(ExtBinDataAccessor* pcExtBinDataAccessor,
                                             UInt uiInputLayers,
                                             UInt* m_layer_id);
    ErrVal xWriteScalableSEIDependencyChange(ExtBinDataAccessor* pcExtBinDataAccessor,
                                             UInt uiNumLayers,
                                             UInt* uiLayerId,
                                             Bool* pbLayerDependencyInfoPresentFlag,
                                             UInt* uiNumDirectDependentLayers,
                                             UInt** puiDirectDependentLayerIdDeltaMinus1,
                                             UInt* puiLayerDependencyInfoSrcLayerIdDeltaMinus1);
    //JVT-S080 LMI }
    //JVT-W043
    CodingParameter* getCodingParameter(void);

protected:
    ErrVal xCreateEncoder();

protected:
    //SVC编码器实例
    H264AVCEncoder*           m_pcH264AVCEncoder;
    //AVC编码器实例
    PicEncoder*               m_pcPicEncoder;

    LayerEncoder*             m_apcLayerEncoder[MAX_LAYERS];
    SliceEncoder*             m_pcSliceEncoder;
    ControlMngH264AVCEncoder* m_pcControlMng;
    BitWriteBuffer*           m_pcBitWriteBuffer;
    BitCounter*               m_pcBitCounter;
    NalUnitEncoder*           m_pcNalUnitEncoder;

    UvlcWriter*               m_pcUvlcWriter;
    UvlcWriter*               m_pcUvlcTester;
    MbCoder*                  m_pcMbCoder;
    LoopFilter*               m_pcLoopFilter;
    MbEncoder*                m_pcMbEncoder;
    Transform*                m_pcTransform;
    IntraPredictionSearch*    m_pcIntraPrediction;
    YuvBufferCtrl*            m_apcYuvFullPelBufferCtrl[MAX_LAYERS];
    YuvBufferCtrl*            m_apcYuvHalfPelBufferCtrl[MAX_LAYERS];
    QuarterPelFilter*         m_pcQuarterPelFilter;
    CodingParameter*          m_pcCodingParameter;
    ParameterSetMng*          m_pcParameterSetMng;
    PocCalculator*            m_apcPocCalculator[MAX_LAYERS];
    SampleWeighting*          m_pcSampleWeighting;
    CabacWriter*              m_pcCabacWriter;
    XDistortion*              m_pcXDistortion;
    MotionEstimation*         m_pcMotionEstimation;
    RateDistortion*           m_pcRateDistortion;
    History*                  m_pcHistory;
    ReconstructionBypass*     m_pcReconstructionBypass;
    Bool                      m_bTraceEnable;
    // JVT-V068 HRD {
    StatBuf<Scheduler*, MAX_SCALABLE_LAYERS> m_apcScheduler;
    // JVT-V068 HRD }
};

}  //namespace JSVM {


#endif //_CREATERH264AVCENCODER_H_
