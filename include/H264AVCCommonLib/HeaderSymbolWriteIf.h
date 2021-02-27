#ifndef _HEADERSYMBOLWRITEIF_H_
#define _HEADERSYMBOLWRITEIF_H_


namespace JSVM {

class HeaderSymbolWriteIf
{
protected:
    HeaderSymbolWriteIf()
    {
    }
    virtual ~HeaderSymbolWriteIf()
    {
    }

public:
    virtual HeaderSymbolWriteIf* getHeaderSymbolWriteIfNextSlice (Bool bStartNewBitstream) = 0;

    virtual ErrVal writeUvlc (UInt uiCode, const Char* pcTraceString) = 0;
    virtual ErrVal writeSvlc (Int iCode, const Char* pcTraceString) = 0;
    virtual ErrVal writeCode (UInt uiCode, UInt uiLength, const Char* pcTraceString) = 0;
    virtual ErrVal writeSCode (Int iCode, UInt uiLength, const Char* pcTraceString) = 0;
    virtual ErrVal writeFlag (Bool bFlag, const Char* pcTraceString ) = 0;
    virtual UInt getNumberOfWrittenBits () = 0;
};


}  //namespace JSVM {

#endif //_HEADERSYMBOLWRITEIF_H_
