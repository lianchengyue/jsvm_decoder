#ifndef _CABADECODER_H_
#define _CABADECODER_H_


namespace JSVM {

class BitReadBuffer;
class CabacContextModel;

class CabaDecoder
{
protected:
    CabaDecoder();
    virtual ~CabaDecoder();

public:
    ErrVal init(BitReadBuffer* pcBitReadBuffer);
    ErrVal start();
    ErrVal finish();
    ErrVal uninit();

    ErrVal getSymbol            (UInt& ruiSymbol, CabacContextModel& rcCCModel);
    ErrVal getEpSymbol          (UInt& ruiSymbol);
    ErrVal getEpExGolomb        (UInt& ruiSymbol, UInt uiCount);
    ErrVal getExGolombLevel     (UInt& ruiSymbol, CabacContextModel& rcCCModel);
    ErrVal getExGolombMvd       (UInt& ruiSymbol, CabacContextModel* pcCCModel, UInt uiMaxBin);
    ErrVal getTerminateBufferBit(UInt& ruiBit);
    ErrVal getUnaryMaxSymbol    (UInt& ruiSymbol, CabacContextModel* pcCCModel, Int iOffset, UInt uiMaxSymbol);
    ErrVal getUnarySymbol       (UInt& ruiSymbol, CabacContextModel* pcCCModel, Int iOffset);

private:
    __inline ErrVal xReadBit(UInt& ruiValue);

protected:
    BitReadBuffer*  m_pcBitReadBuffer;
    UInt  m_uiRange;
    UInt  m_uiValue;
    UInt  m_uiWord;
    UInt  m_uiBitsLeft;
};

}  //namespace JSVM {

#endif //_CABADECODER_H_
