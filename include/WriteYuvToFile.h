#ifndef _WRITEYUVTOFILE_H_
#define _WRITEYUVTOFILE_H_


#include "WriteYuvIf.h"
#include "LargeFile.h"


class WriteYuvToFile : public WriteYuvIf
{
protected:
    WriteYuvToFile();
    virtual ~WriteYuvToFile();

public:
    static ErrVal create(WriteYuvToFile*& rpcWriteYuv);
    ErrVal destroy();

    ErrVal init(const std::string& rcFileName);
    ErrVal uninit();

    ErrVal writeFrame(const UChar*  pLum,
                      const UChar*  pCb,
                      const UChar*  pCr,
                      UInt          uiLumHeight,
                      UInt          uiLumWidth,
                      UInt          uiLumStride,
                      const UInt    rauiCropping[]);

protected:
    LargeFile m_cFile;
};

#endif //_WRITEYUVTOFILE_H_
