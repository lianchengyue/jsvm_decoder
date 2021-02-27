#ifndef _READPESTREAM_H_
#define _READPESTREAM_H_

#include "LargeFile.h"

class ReadPEStream
{
protected:
    ReadPEStream();
    virtual ~ReadPEStream();
public:
    ErrVal extractPacket(BinData*& rpcBinData, UInt& uiCts, Bool& rbEOS);
    ErrVal releasePacket(BinData* pcBinData);

    static ErrVal create(ReadPEStream*& rpcReadPEStream);
    ErrVal destroy();

    ErrVal reset();

    ErrVal init(const std::string& rcFileName);
    ErrVal uninit();
protected:
    LargeFile m_cFile;
    UInt   m_uiAULength;
    UChar* m_pucReadPtr;
    UChar* m_pucPayload;
    UInt64 m_uiCts90;
    UInt64 m_uiDts90;
    ErrVal xGetPtsDts(UChar* pucHeader, UInt64& uiTS90);
};

#endif //_READPESTREAM_H_
