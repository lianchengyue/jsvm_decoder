#ifndef _PARAMETERSETMNG_H_
#define _PARAMETERSETMNG_H_

#include "H264AVCCommonLib/SequenceParameterSet.h"

#include "list"


namespace JSVM {

class ParameterSetMng
{
protected:
  ParameterSetMng();
  virtual ~ParameterSetMng()
  {
  }

public:
  static ErrVal create (ParameterSetMng*& rpcParameterSetMng);
  ErrVal destroy ();
  ErrVal init ()                                        { return Err::m_nOK; }
  ErrVal uninit ();

  ErrVal setParamterSetList (std::list<SequenceParameterSet*>& rcSPSList, std::list<PictureParameterSet*>& rcPPSList) const;
  Bool   isValidSPS (UInt uiSPSId, Bool bSubSetSPS)   { return m_cSPSBuf.isValidOffset(uiSPSId+(bSubSetSPS?32:0)) && NULL != m_cSPSBuf.get(uiSPSId+(bSubSetSPS?32:0)); }
  Bool   isValidPPS (UInt uiPPSId)                    { return m_cPPSBuf.isValidOffset(uiPPSId) && NULL != m_cPPSBuf.get(uiPPSId); }
  ErrVal get (SequenceParameterSet *& rpcSPS, UInt uiSPSId, Bool bSubSetSPS);
  ErrVal get (PictureParameterSet *& rpcPPS, UInt uiPPSId);
  ErrVal store (SequenceParameterSet* pcSPS);
  ErrVal store (PictureParameterSet* pcPPS);
  Void   setActiveSPS (UInt uiSPSId, UInt uiDQId)  { m_auiActiveSPSId[uiDQId] = uiSPSId + (uiDQId ? NUM_SPS_IDS : 0); }
  ErrVal getActiveSPS (SequenceParameterSet*& rpcSPS, UInt uiDQId);
  ErrVal getActiveSPSDQ0 (SequenceParameterSet*& rpcSPS);

private:
  ErrVal xDestroyPPS (UInt uiPPSId);
  ErrVal xDestroySPS (UInt uiSPSId);

private:
  StatBuf<SequenceParameterSet*,2*NUM_SPS_IDS>  m_cSPSBuf;
  StatBuf<PictureParameterSet*,256> m_cPPSBuf;
  UInt m_auiActiveSPSId[16*8];
  std::list<SequenceParameterSet*>  m_cSPSList;
  std::list<PictureParameterSet*>   m_cPPSList;
};



}  //namespace JSVM {

#endif //_PARAMETERSETMNG_H_
