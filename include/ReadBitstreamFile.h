#ifndef _READBITSTREAMFILE_H_
#define _READBITSTREAMFILE_H_


#include "H264AVCVideoIoLib.h"
#include "LargeFile.h"
#include "ReadBitstreamIf.h"


class ReadBitstreamFile : public ReadBitstreamIf
{
protected:
    ReadBitstreamFile();
    virtual ~ReadBitstreamFile();

public:
    virtual ErrVal extractPacket(BinData*& rpcBinData, Bool& rbEOS);
    virtual ErrVal releasePacket(BinData* pcBinData);

    static ErrVal create(ReadBitstreamFile*& rpcReadBitstreamFile);
    virtual ErrVal destroy();

    ErrVal init(const std::string& rcFileName);
    virtual ErrVal uninit();

    virtual ErrVal getPosition(Int& iPos);
    virtual ErrVal setPosition(Int  iPos);

    virtual Int64  getFilePos() {
        return m_cFile.tell();
    }

protected:
    LargeFile m_cFile;
};

#endif //_READBITSTREAMFILE_H_
