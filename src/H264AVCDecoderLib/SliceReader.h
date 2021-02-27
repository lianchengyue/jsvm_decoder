#ifndef _SLICEREADER_H_
#define _SLICEREADER_H_



#include "H264AVCCommonLib/HeaderSymbolReadIf.h"
#include "H264AVCCommonLib/ControlMngIf.h"
#include "NalUnitParser.h"

namespace JSVM {


class MbParser;
class ParameterSetMng;
class MbStatus;

class SliceReader
{
protected:
    SliceReader();
    virtual ~SliceReader();

public:
    static ErrVal create(SliceReader*& rpcSliceReader);
    ErrVal destroy();
    ErrVal init(MbParser* pcMbParser);
    ErrVal uninit();

    ErrVal read(SliceHeader&  rcSH,
                MbDataCtrl*   pcMbDataCtrl,
                MbStatus*     pacMbStatus,
                UInt          uiMbInRow,
                UInt&         ruiMbRead);

protected:
    Bool      m_bInitDone;
    MbParser* m_pcMbParser;
};

}  //namespace JSVM {

#endif //_SLICEREADER_H_
