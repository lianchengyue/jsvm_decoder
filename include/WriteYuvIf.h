#ifndef _WRITEYUVIF_H_
#define _WRITEYUVIF_H_


class WriteYuvIf
{
protected:
    WriteYuvIf()
    {
    }
    virtual ~WriteYuvIf()
    {
    }

public:
    virtual ErrVal writeFrame (const UChar *pLum,
                               const UChar *pCb,
                               const UChar *pCr,
                               UInt uiLumHeight,
                               UInt uiLumWidth,
                               UInt uiLumStride,
                               const UInt rauiCropping[])  = 0;

    virtual ErrVal destroy() = 0;
};

#endif //_WRITEYUVIF_H_
