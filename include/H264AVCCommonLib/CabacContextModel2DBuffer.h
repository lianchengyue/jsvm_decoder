#ifndef _CABACCONTEXTMODEL2DBUFFER_H_
#define _CABACCONTEXTMODEL2DBUFFER_H_


#include "H264AVCCommonLib/CabacContextModel.h"

namespace JSVM {

class CabacContextModel2DBuffer
{
public:
    CabacContextModel2DBuffer(UInt uiSizeY, UInt uiSizeX);
    ~CabacContextModel2DBuffer();

    CabacContextModel& get(UInt uiY, UInt uiX)
    {
        AOT_DBG( uiY >= m_uiSizeY );
        AOT_DBG( uiX >= m_uiSizeX );
        return m_pcCContextModel[ uiY * m_uiSizeX + uiX];
    }
    CabacContextModel* get(UInt uiY)
    {
        AOT_DBG( uiY >= m_uiSizeY );
        return &m_pcCContextModel[uiY * m_uiSizeX];
    }

    ErrVal initBuffer(Short* psCtxModel, Int iQp)
    {
        ROT( NULL == m_pcCContextModel );

        for(UInt n = 0; n < m_uiSizeY * m_uiSizeX; n++)
        {
            m_pcCContextModel[n].init( psCtxModel + 2*n, iQp);
        }
        return Err::m_nOK;
    }
    //JVT-X046 {
    CabacContextModel* getCabacContextModel(void)
    {
        return m_pcCContextModel;
    }
    void setCabacContextModel(CabacContextModel* pcCContextModel)
    {
        m_pcCContextModel->set(pcCContextModel);
    }
    //JVT-X046 }
protected:
    CabacContextModel* m_pcCContextModel;
    const UInt m_uiSizeX;
    const UInt m_uiSizeY;
};

}//  namespace JSVM {

#endif // _CABACCONTEXTMODEL2DBUFFER_H_
