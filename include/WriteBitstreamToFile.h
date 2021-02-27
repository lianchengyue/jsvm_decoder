#ifndef _WRITEBITSTREAMTOFILE_H_
#define _WRITEBITSTREAMTOFILE_H_


#include "LargeFile.h"
#include "WriteBitstreamIf.h"

class WriteBitstreamToFile :
public WriteBitstreamIf
{
protected:
    WriteBitstreamToFile() : m_uiNumber(0), m_bNewFileOnNewAu(false)
    {
    }
    virtual ~WriteBitstreamToFile()
    {
    }

public:
    static ErrVal create(WriteBitstreamToFile*& rpcWriteBitstreamToFile);
    virtual ErrVal destroy();
    ErrVal init(const std::string& rcFileName, Bool bNewFileOnNewAu = false);
    virtual ErrVal uninit();

    virtual ErrVal writePacket(BinDataAccessor* pcBinDataAccessor, Bool bNewAU = false);
    virtual ErrVal writePacket(BinData* pcBinData, Bool bNewAU = false);

    virtual ErrVal writePacket(Void* pBuffer, UInt uiLength);

private:
    UInt m_uiNumber;
    LargeFile m_cFile;
    std::string m_cFileName;
    Bool m_bNewFileOnNewAu;
};


#endif //_WRITEBITSTREAMTOFILE_H_
