#ifndef _CABACCONTEXTMODEL_H_
#define _CABACCONTEXTMODEL_H_

#include "Typedefs.h"

namespace JSVM {


class CabacContextModel
{
public:
    CabacContextModel();
    ~CabacContextModel();

    const UChar getState()           { return m_ucState>>1; }
    const UChar getMps()             { return m_ucState&1;  }
    Void toggleMps()                 { m_ucState ^= 1;      }
    Void setState(UChar ucState)   { m_ucState = (ucState<<1)+getMps(); }

    Void init(Short asCtxInit[], Int iQp)
    {
        Int iState = ((asCtxInit[0] * iQp) >> 4) + asCtxInit[1];
        iState = gMin(gMax(1, iState), 126);

        if (iState>=64)
        {
            m_ucState = iState - 64;
            m_ucState += m_ucState + 1;
        }
        else
        {
            m_ucState = 63 - iState;
            m_ucState += m_ucState;
        }
        m_uiCount = 0;
    }

    Void initEqualProbability()
    {
        m_ucState = 0;
        m_uiCount = 0;
    }

    Void incrementCount()
    {
        m_uiCount++;
    }
    //JVT-X046 {
    UChar getucState(void)
    {
        return m_ucState;
    }
    UInt getuiCount(void)
    {
       return m_uiCount;
    }
    void set(CabacContextModel* pcCContextModel)
    {
        m_ucState = pcCContextModel->getucState();
        m_uiCount = pcCContextModel->getuiCount();
    }
    //JVT-X046 }
private:
    UChar m_ucState;
    UInt m_uiCount;

    static const Double m_afProbability[128];
    static const Double m_afEntropy[128];
};


}  //namespace JSVM {

#endif // _CABACCONTEXTMODEL_H_
