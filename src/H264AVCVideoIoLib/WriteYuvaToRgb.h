#ifndef _WRITEYUVATORGB_H_
#define _WRITEYUVATORGB_H_

#include "Typedefs.h"

class WriteYuvaToRgb
{

protected:
    WriteYuvaToRgb();
    virtual ~WriteYuvaToRgb();

public:
    static ErrVal create(WriteYuvaToRgb*& rpcWriteYuvaToRgb);
    ErrVal destroy();

    ErrVal setFrameDimension(UInt uiLumHeight, UInt uiLumWidth);

    virtual ErrVal writeFrameRGB (UChar* pucRGB,
                                  UInt uiDestStride,
                                  const UChar *pLum,
                                  const UChar *pCb,
                                  const UChar *pCr,
                                  UInt uiLumHeight,
                                  UInt uiLumWidth,
                                  UInt uiLumStride);

    virtual ErrVal writeFrameYUYV (UChar* pucYUYV,
                                   UInt uiDestStride,
                                   const UChar *pLum,
                                   const UChar *pCb,
                                   const UChar *pCr,
                                   UInt uiLumHeight,
                                   UInt uiLumWidth,
                                   UInt uiLumStride);

    virtual ErrVal writeFrameYV12 (UChar* pucYUYV,
                                   UInt uiDestStride,
                                   const UChar *pLum,
                                   const UChar *pCb,
                                   const UChar *pCr,
                                   UInt uiLumHeight,
                                   UInt uiLumWidth,
                                   UInt uiLumStride);

protected:
    UInt m_uiHeight;
    UInt m_uiWidth;
};

#endif //_WRITEYUVATORGB_H_
