#ifndef _POCCALCULATOR_H_
#define _POCCALCULATOR_H_

#include "Typedefs.h"

namespace JSVM {

class PocCalculator
{
public:
    PocCalculator();

    static  ErrVal create(PocCalculator*& rpcPocCalculator);
    ErrVal  copy(PocCalculator*& rpcPocCalculator);
    ErrVal  destroy();

    ErrVal  setPoc(SliceHeader& rcSliceHeader, Int iContNumber);
    ErrVal  calculatePoc(SliceHeader& rcSliceHeader);
    ErrVal  resetMMCO5(SliceHeader& rcSliceHeader);

protected:
    ErrVal  xInitSPS(const SequenceParameterSet& rcSPS);

private:
    UInt    m_iLastIdrFieldNum;
    Int     m_iBitsLsb;
    Int     m_iTop2BotOffset;

    Int     m_iPrevRefPocMsb;
    Int     m_iPrevRefPocLsb;
    Int     m_iMaxPocLsb;
    Int     m_iFrameNumOffset;
    Int     m_iRefOffsetSum;
    Int     m_iPrevFrameNum;
};


}  //namespace JSVM {


#endif //_POCCALCULATOR_H_
