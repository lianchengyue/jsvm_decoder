#ifndef _SAMPLEWEIGHTING_H_
#define _SAMPLEWEIGHTING_H_

#include  "H264AVCCommonLib/YuvMbBuffer.h"
#include  "Typedefs.h"

namespace JSVM {

class SampleWeighting
{
    typedef Void (*MixSampleFunc) (Pel* pucDest,  Int iDestStride, Pel*  pucSrc, Int iSrcStride, Int iSizeY);
    typedef Void (*XMixSampleFunc)(XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY);

protected:
    SampleWeighting();
    virtual ~SampleWeighting()
    {
    }

public:
    static ErrVal create(SampleWeighting*& rpcSampleWeighting);
    ErrVal destroy();
    virtual ErrVal init();
    ErrVal uninit();

    ErrVal initSlice(const SliceHeader& rcSliceHeader);

    Void getTargetBuffers(YuvMbBuffer* apcTarBuffer[2], YuvMbBuffer* pcRecBuffer, const PredWeight* pcPW0, const PredWeight* pcPW1);

    Void weightLumaSamples(YuvMbBuffer* pcRecBuffer, Int iSizeX, Int iSizeY, LumaIdx cIdx, const PredWeight* pcPW0, const PredWeight* pcPW1);
    Void weightChromaSamples(YuvMbBuffer* pcRecBuffer, Int iSizeX, Int iSizeY, LumaIdx cIdx, const PredWeight* pcPW0, const PredWeight* pcPW1);

    //===== for motion estimation of bi-predicted blocks with standard weights =====
    Void inverseLumaSamples(YuvMbBuffer* pcDesBuffer, YuvMbBuffer* pcOrgBuffer, YuvMbBuffer* pcFixBuffer, Int iYSize, Int iXSize);

    //===== for motion estimation of bi-predicted blocks with non-standard weights =====
    Void weightInverseLumaSamples(YuvMbBuffer* pcDesBuffer, YuvMbBuffer* pcOrgBuffer, YuvMbBuffer* pcFixBuffer, const PredWeight* pcSearchPW, const PredWeight* pcFixPW, Double&  rdWeight, Int iYSize, Int iXSize);

    //===== for motion estimation of unidirectional predicted blocks with non-standard weights =====
    Void weightInverseLumaSamples  (YuvMbBuffer* pcDesBuffer, YuvMbBuffer* pcOrgBuffer, const PredWeight* pcPW, Double&  rdWeight, Int iYSize, Int iXSize);
    Void weightInverseChromaSamples(YuvMbBuffer* pcDesBuffer, YuvMbBuffer* pcOrgBuffer, const PredWeight* pcPW, Double* padWeight, Int iYSize, Int iXSize);

//TMM_WP
    ErrVal initSliceForWeighting(const SliceHeader& rcSliceHeader);

//TMM_WP

protected:
    Void xMixB       (Pel*  pucDest, Int iDestStride, Pel*  pucSrc, Int iSrcStride, Int iSizeY, Int iSizeX);
    Void xMixB       (XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY, Int iSizeX);
    Void xMixBWeight (Pel*  pucDest, Int iDestStride, Pel*  pucSrc, Int iSrcStride, Int iSizeY, Int iSizeX, Int iWD, Int iWS, Int iOffset, UInt uiDenom);
    Void xMixBWeight (XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY, Int iSizeX, Int iWD, Int iWS, Int iOffset, UInt uiDenom);
    Void xWeight     (Pel*  pucDest, Int iDestStride,                               Int iSizeY, Int iSizeX, Int iWeight,      Int iOffset, UInt uiDenom);
    Void xWeight     (XPel* pucDest, Int iDestStride,                               Int iSizeY, Int iSizeX, Int iWeight,      Int iOffset, UInt uiDenom);

private:
    static Void xMixB16x  (Pel* pucDest, Int iDestStride, Pel* pucSrc, Int iSrcStride, Int iSizeY);
    static Void xMixB8x   (Pel* pucDest, Int iDestStride, Pel* pucSrc, Int iSrcStride, Int iSizeY);
    static Void xMixB4x   (Pel* pucDest, Int iDestStride, Pel* pucSrc, Int iSrcStride, Int iSizeY);
    static Void xXMixB16x (XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY);
    static Void xXMixB8x  (XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY);
    static Void xXMixB4x  (XPel* pucDest, Int iDestStride, XPel* pucSrc, Int iSrcStride, Int iSizeY);

protected:
    MixSampleFunc m_afpMixSampleFunc[5];
    XMixSampleFunc m_afpXMixSampleFunc[5];

private:
    YuvMbBuffer  m_cIntYuvBiBuffer;
    UInt  m_uiLumaLogWeightDenom;
    UInt  m_uiChromaLogWeightDenom;
    Bool  m_bExplicit;
    Bool  m_bWeightedPredDisableP;
    Bool  m_bWeightedPredDisableB;
};


}  //namespace JSVM {


#endif //_SAMPLEWEIGHTING_H_
