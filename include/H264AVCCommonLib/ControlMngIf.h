#ifndef _CONTROLMNGIF_H_
#define _CONTROLMNGIF_H_

#include "Typedefs.h"

namespace JSVM {

class MbDataCtrl;

class ControlMngIf
{
protected:
    ControlMngIf()
    {
    }
    virtual ~ControlMngIf()
    {
    }

public:
    virtual ErrVal initSlice0 (SliceHeader*  rcSH) = 0;
    virtual ErrVal initSPS (SequenceParameterSet&  rcSPS,
                            UInt  uiLayer) = 0;

    virtual ErrVal initParameterSets (const SequenceParameterSet& rcSPS,
                                      const PictureParameterSet&  rcPPS) = 0;

    virtual ErrVal initSliceForCoding (const SliceHeader&  rcSH) = 0;
    virtual ErrVal initSliceForReading (const SliceHeader&  rcSH) = 0;
    virtual ErrVal initSliceForDecoding (const SliceHeader&  rcSH) = 0;
    virtual ErrVal initSliceForFiltering (const SliceHeader&  rcSH) = 0;
    virtual ErrVal initSliceForWeighting (const SliceHeader&  rcSH) = 0;
    virtual ErrVal finishSlice (const SliceHeader&  rcSH,
                                Bool&  rbPicDone,
                                Bool&  rbFrameDone) = 0;

    virtual ErrVal initMbForParsing (MbDataAccess*& rpcMbDataAccess, UInt uiMbIndex) = 0;
    virtual ErrVal initMbForDecoding (MbDataAccess*& rpcMbDataAccess, UInt uiMbY, UInt uiMbX, Bool bMbAff) = 0;
    virtual ErrVal initMbForFiltering (MbDataAccess*& rpcMbDataAccess, UInt uiMbY, UInt uiMbX, Bool bMbAff) = 0;

    virtual ErrVal initMbForCoding (MbDataAccess& rcMbDataAccess, UInt uiMbY, UInt uiMbX, Bool bMbAff, Bool bFieldFlag) = 0;
    virtual ErrVal initMbForDecoding (MbDataAccess& rcMbDataAccess, UInt uiMbY, UInt uiMbX, Bool bMbAff) = 0;
    virtual ErrVal initMbForFiltering (MbDataAccess& rcMbDataAccess, UInt uiMbY, UInt uiMbX, Bool bMbAff) = 0;
};


}  //namespace JSVM {


#endif // _CONTROLMNGIF_H_
