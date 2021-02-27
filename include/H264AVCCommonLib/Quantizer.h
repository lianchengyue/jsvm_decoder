#ifndef _QUANTIZER_H_
#define _QUANTIZER_H_

#include "Typedefs.h"

// h264 namepace begin
namespace JSVM {


class QpParameter
{
public :
    const QpParameter& operator= (const QpParameter& rcQp)
    {
        m_iPer  = rcQp.m_iPer;
        m_iRem  = rcQp.m_iRem;
        m_iBits = rcQp.m_iBits;
        m_iAdd  = rcQp.m_iAdd;
        return *this;
    }

    Void setQp(Int iQp, Bool bIntra)
    {
        m_iPer  = (iQp)/6;
        m_iRem  = (iQp)%6;
        m_iBits = QP_BITS + m_iPer;
        m_iAdd  = (1 << m_iBits) / ((bIntra) ?  3 : 6);
    }

    const Int per() const     { return m_iPer; }
    const Int rem() const     { return m_iRem; }
    const Int bits() const    { return m_iBits; }
    const Int add() const     { return m_iAdd; }
    const Int mode() const    { return m_iMode; }
    const Int value() const   { return 6*m_iPer+m_iRem; }

private:
    Int m_iPer;
    Int m_iRem;
    Int m_iBits;
    Int m_iAdd;
    Int m_iMode;
};



class Quantizer
{
public:
    Quantizer();
    virtual ~Quantizer();


    Void setQp(const MbDataAccess& rcMbDataAccess, Bool bIntraMb)
    {
        Int   iLumaQp   = rcMbDataAccess.getMbData().getQp();
        Int   iCbQp     = rcMbDataAccess.getSH().getCbQp(iLumaQp);
        Int   iCrQp     = rcMbDataAccess.getSH().getCrQp(iLumaQp);
        Bool  bRefPic   = rcMbDataAccess.getSH().getNalRefIdc () != NAL_REF_IDC_PRIORITY_LOWEST;
        Bool  bKeyPic   = rcMbDataAccess.getSH().getTemporalId() == 0;
        Bool  bOneThird = (bKeyPic || (bRefPic && bIntraMb));

        m_cLumaQp.setQp(iLumaQp, bOneThird);
        m_cCbQp.setQp(iCbQp, bOneThird);
        m_cCrQp.setQp(iCrQp, bOneThird);
    }

    Void setDecompositionStages(Int iDStages)
    {
        m_iDStages = iDStages;
    }


    //Luma Qp, Cb Qp与Cr Qp
    const QpParameter&  getCbQp() const                 { return m_cCbQp; }
    const QpParameter&  getCrQp() const                 { return m_cCrQp; }
    const QpParameter&  getChromaQp(UInt uiIdx) const   { AOT(uiIdx > 1); return (uiIdx ? getCrQp() : getCbQp()); }
    const QpParameter&  getLumaQp() const               { return m_cLumaQp; }

protected:
    QpParameter m_cLumaQp;
    QpParameter m_cCbQp;
    QpParameter m_cCrQp;
    Int m_iDStages;
};


}  //namespace JSVM {



#endif //_QUANTIZER_H_
