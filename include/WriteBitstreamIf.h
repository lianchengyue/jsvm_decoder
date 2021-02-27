#ifndef AFX_WRITEBITSTREAMIF_H_
#define AFX_WRITEBITSTREAMIF_H_


class WriteBitstreamIf
{
public:
    WriteBitstreamIf()
    {
    }
    virtual ~WriteBitstreamIf()
    {
    }

    virtual ErrVal destroy() = 0;
    virtual ErrVal uninit() = 0;

    virtual ErrVal writePacket(BinDataAccessor* pcBinDataAccessor, Bool bNewAU = false) = 0;
    virtual ErrVal writePacket(BinData* pcBinData, Bool bNewAU = false) = 0;
    virtual ErrVal writePacket(Void* pBuffer, UInt uiLength) = 0;
};

#endif //AFX_WRITEBITSTREAMIF_H_
