#ifndef _MOTIONVECTORCALCULATION_H_
#define _MOTIONVECTORCALCULATION_H_

#include "Typedefs.h"

namespace JSVM {


class MotionVectorCalculation
{
protected:
  MotionVectorCalculation();
  virtual ~MotionVectorCalculation();

public:
  static ErrVal create (MotionVectorCalculation*& rpcMotionVectorCalculation);
  ErrVal        destroy ();

  ErrVal initSlice (const SliceHeader& rcSH );
  ErrVal uninit ();

  ErrVal  calcMvMb (MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase);
  ErrVal  calcMvSubMb (B8x8Idx c8x8Idx, MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase);

protected:
  Void xCalc16x16 (MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase);
  Void xCalc16x8 (MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase);
  Void xCalc8x16 (MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase);
  Void xCalc8x8 (MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase, Bool bFaultTolerant);
  Void xCalc8x8 (B8x8Idx c8x8Idx, MbDataAccess& rcMbDataAccess, MbDataAccess* pcMbDataAccessBase, Bool bFaultTolerant);

protected:
  UInt m_uiMaxBw;
  Bool m_bSpatialDirectMode;
  Mv3D m_cMvA;
  Mv3D m_cMvB;
  Mv3D m_cMvC;
};


}  //namespace JSVM {

#endif //_MOTIONVECTORCALCULATION_H_
