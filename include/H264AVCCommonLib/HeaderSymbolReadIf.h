#ifndef _HEADERSYMBOLREADIF_H_
#define _HEADERSYMBOLREADIF_H_

namespace JSVM {

class HeaderSymbolReadIf
{
protected:
    HeaderSymbolReadIf()
    {
    }
    virtual ~HeaderSymbolReadIf()
    {
    }

public:
    virtual ErrVal  getSvlc(Int& riCode, const Char* pcTraceString) = 0;
    virtual ErrVal  getUvlc(UInt& ruiCode, const Char* pcTraceString) = 0;
    virtual ErrVal  getCode(UInt& ruiCode, UInt uiLength, const Char* pcTraceString) = 0;
    virtual ErrVal  getSCode(Int&  riCode, UInt uiLength, const Char* pcTraceString) = 0;
    virtual ErrVal  getFlag(Bool& rbFlag, const Char* pcTraceString) = 0;
    virtual ErrVal  readByteAlign() = 0;
// JVT-T073 {
    virtual ErrVal  readZeroByteAlign() = 0;
// JVT-T073 }
    virtual Bool    moreRBSPData() = 0;
};


}//  namespace JSVM {

#endif //_HEADERSYMBOLREADIF_H_
