#ifndef _NALUNITPARSER_H_
#define _NALUNITPARSER_H_


#include "Typedefs.h"

namespace JSVM {



class BitReadBuffer;


class NalUnitParser : public NalUnitHeader
{
protected:
    NalUnitParser();
    virtual ~NalUnitParser();

public:
    static ErrVal  create(NalUnitParser*&  rpcNalUnitParser);
    ErrVal destroy();
    ErrVal init(BitReadBuffer* pcBitReadBuffer,
                HeaderSymbolReadIf* pcHeaderSymbolReadIf);
    ErrVal uninit();

    ErrVal initNalUnit(BinDataAccessor&  rcBinDataAccessor, Int  iDQId = MSYS_INT_MIN);
    ErrVal closeNalUnit(Bool bCheckEndOfNalUnit = true);

private:
    ErrVal xInitSODB(BinDataAccessor&  rcBinDataAccessor,  Bool bTrailingBits);

private:
    Bool m_bInitialized;
    Bool m_bNalUnitInitialized;
    BitReadBuffer*      m_pcBitReadBuffer;
    HeaderSymbolReadIf* m_pcHeaderSymbolReadIf;
};



}  //namespace JSVM {


#endif //_NALUNITPARSER_H_
