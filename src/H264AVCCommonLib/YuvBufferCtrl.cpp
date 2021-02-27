#include "H264AVCCommonLib.h"
#include "H264AVCCommonLib/YuvBufferCtrl.h"

namespace JSVM {

YuvBufferCtrl::YuvBufferCtrl() :
  m_uiChromaSize  (0),
  m_iResolution   (0),
  m_bInitDone     (false)
{
}

YuvBufferCtrl::~YuvBufferCtrl()
{
}

ErrVal YuvBufferCtrl::getChromaSize(UInt& ruiChromaSize)
{
    ROF(m_bInitDone);
    ruiChromaSize = m_uiChromaSize;
    return Err::m_nOK;
}

ErrVal YuvBufferCtrl::create(YuvBufferCtrl*& rpcYuvBufferCtrl)
{
    rpcYuvBufferCtrl = new YuvBufferCtrl;

    ROT(NULL == rpcYuvBufferCtrl);

    return Err::m_nOK;
}

ErrVal YuvBufferCtrl::destroy()
{
    delete this;

    return Err::m_nOK;
}


// NOT_SPECIFIED   = 0x00,
// TOP_FIELD       = 0x01,
// BOT_FIELD       = 0x02,
// FRAME           = 0x03,
// MAX_FRAME_TYPE  = 0x04
ErrVal YuvBufferCtrl::initMb(UInt uiMbY, UInt uiMbX, Bool bMbAff)
{
    ROF(m_bInitDone);

    UInt uiXPos = (uiMbX<<3) << m_iResolution;
    UInt uiYPos = (uiMbY<<3) << m_iResolution;

    if(bMbAff)
    {
        uiMbY >>= 1;
    }

    UInt uiYPosFld  = (uiMbY<<3) << m_iResolution;
    Int  iStride    = m_acBufferParam[FRAME].m_iStride;

    m_acBufferParam[FRAME]    .m_uiCbOffset = m_uiCbBaseOffset + uiXPos + uiYPos    * iStride / 2;
    m_acBufferParam[TOP_FIELD].m_uiCbOffset = m_uiCbBaseOffset + uiXPos + uiYPosFld * iStride;

    m_acBufferParam[FRAME]    .m_uiCrOffset = m_acBufferParam[FRAME]    .m_uiCbOffset + m_uiChromaSize;
    m_acBufferParam[TOP_FIELD].m_uiCrOffset = m_acBufferParam[TOP_FIELD].m_uiCbOffset + m_uiChromaSize;
    uiXPos    <<= 1;
    uiYPos    <<= 1;
    uiYPosFld <<= 1;

    m_acBufferParam[FRAME]    .m_uiLumOffset  = m_uiLumBaseOffset + uiXPos + uiYPos    * iStride;
    m_acBufferParam[TOP_FIELD].m_uiLumOffset  = m_uiLumBaseOffset + uiXPos + uiYPosFld * iStride * 2;

    m_acBufferParam[BOT_FIELD].m_uiLumOffset  = m_acBufferParam[TOP_FIELD].m_uiLumOffset + iStride;
    m_acBufferParam[BOT_FIELD].m_uiCbOffset   = m_acBufferParam[TOP_FIELD].m_uiCbOffset  + iStride / 2;
    m_acBufferParam[BOT_FIELD].m_uiCrOffset   = m_acBufferParam[TOP_FIELD].m_uiCrOffset  + iStride / 2;

    return Err::m_nOK;
}

//initSlice与initSPS完全相同
ErrVal YuvBufferCtrl::initSlice(UInt uiYFrameSize,
                                UInt uiXFrameSize,
                                UInt uiYMarginSize,
                                UInt uiXMarginSize,
                                UInt uiResolution)
{
    ROT(0 ==  uiYFrameSize);
    ROT(0 != (uiYFrameSize&0xf));
    ROT(0 ==  uiXFrameSize);
    ROT(0 != (uiXFrameSize&0xf));
    ROT(2 < uiResolution);
    ROT(1 & uiXMarginSize);

    uiYFrameSize  <<= uiResolution;
    uiXFrameSize  <<= uiResolution;
    uiYMarginSize <<= uiResolution;
    uiXMarginSize <<= uiResolution;

    m_uiXMargin = uiXMarginSize;
    m_uiYMargin = uiYMarginSize/2;

    m_acBufferParam[FRAME].    m_iHeight = uiYFrameSize;
    m_acBufferParam[TOP_FIELD].m_iHeight =
    m_acBufferParam[BOT_FIELD].m_iHeight = uiYFrameSize >> 1;

    m_acBufferParam[FRAME].    m_iStride = uiXFrameSize   + 2*uiXMarginSize;
    m_acBufferParam[TOP_FIELD].m_iStride =
    m_acBufferParam[BOT_FIELD].m_iStride = 2*uiXFrameSize + 4*uiXMarginSize;

    m_acBufferParam[FRAME].    m_iWidth = uiXFrameSize;
    m_acBufferParam[TOP_FIELD].m_iWidth = uiXFrameSize;
    m_acBufferParam[BOT_FIELD].m_iWidth = uiXFrameSize;

    m_acBufferParam[FRAME].    m_iResolution = uiResolution;
    m_acBufferParam[TOP_FIELD].m_iResolution = uiResolution;
    m_acBufferParam[BOT_FIELD].m_iResolution = uiResolution;

    m_iResolution   = uiResolution;
    m_uiChromaSize  = ((uiYFrameSize >> 1) + uiYMarginSize)
                    * ((uiXFrameSize >> 1) + uiXMarginSize);

    m_uiLumBaseOffset = (m_acBufferParam[FRAME].m_iStride) * uiYMarginSize + uiXMarginSize;
    m_uiCbBaseOffset  = (m_acBufferParam[FRAME].m_iStride/2) * uiYMarginSize/2 + uiXMarginSize/2;
    m_uiCbBaseOffset += 4*m_uiChromaSize;
    m_bInitDone = true;

    return Err::m_nOK;
}

//initSlice与initSPS完全相同
ErrVal YuvBufferCtrl::initSPS (UInt uiYFrameSize,
                               UInt uiXFrameSize,
                               UInt uiYMarginSize,
                               UInt uiXMarginSize,
                               UInt uiResolution)
{
    ROT (0 ==  uiYFrameSize);
    ROT (0 != (uiYFrameSize&0xf));
    ROT (0 ==  uiXFrameSize);
    ROT (0 != (uiXFrameSize&0xf));
    ROT (2 < uiResolution);
    ROT (1 & uiXMarginSize);

    //全像素: 1088
    //半像素: 2176
    uiYFrameSize  <<= uiResolution;
    //全像素: 1920
    //半像素: 3849
    uiXFrameSize  <<= uiResolution;
    //全像素: 64
    //半像素: 128
    uiYMarginSize <<= uiResolution;
    //全像素: 32
    //半像素: 64
    uiXMarginSize <<= uiResolution;

    //全像素: 32
    //半像素: 64
    m_uiXMargin = uiXMarginSize;
    //全像素: 32
    //半像素: 64
    m_uiYMargin = uiYMarginSize/2;

    //全像素: 1088
    //半像素: 2176
    m_acBufferParam[FRAME].    m_iHeight = uiYFrameSize;
    //全像素: 544
    //半像素: 1088
    m_acBufferParam[TOP_FIELD].m_iHeight =
    m_acBufferParam[BOT_FIELD].m_iHeight = uiYFrameSize >> 1;

    //步长Stride
    //全像素: 1920 + 2*32 = 1984
    //半像素: 3840 + 2*64 = 3968
    m_acBufferParam[FRAME].    m_iStride = uiXFrameSize   + 2*uiXMarginSize;
    //全像素: 2*1920 + 4*32 = 3968
    //半像素: 2*3840 + 4*64 = 7936
    m_acBufferParam[TOP_FIELD].m_iStride =
    m_acBufferParam[BOT_FIELD].m_iStride = 2*uiXFrameSize + 4*uiXMarginSize;

    //宽度Width
    //全像素: 1920
    //半像素: 3840
    m_acBufferParam[FRAME].    m_iWidth = uiXFrameSize;
    m_acBufferParam[TOP_FIELD].m_iWidth = uiXFrameSize;
    m_acBufferParam[BOT_FIELD].m_iWidth = uiXFrameSize;

    //全像素: 0
    //半像素: 1
    m_acBufferParam[FRAME].    m_iResolution = uiResolution;  //0
    m_acBufferParam[TOP_FIELD].m_iResolution = uiResolution;  //0
    m_acBufferParam[BOT_FIELD].m_iResolution = uiResolution;  //0

    m_iResolution   = uiResolution;

    //思考：加margin的规律
    //全像素: (1088>>1 + 64 ) * (1920>>1 + 32) = 603136
    //半像素: (2176>>1 + 128) * (3840>>1 + 64) = 2412544
    m_uiChromaSize  = ((uiYFrameSize >> 1) + uiYMarginSize)
                    * ((uiXFrameSize >> 1) + uiXMarginSize);

    //全像素: 1984*64 + 32 = 127008
    //半像素:
    m_uiLumBaseOffset = (m_acBufferParam[FRAME].m_iStride) * uiYMarginSize + uiXMarginSize;
    //全像素: 1984/2*64 /2 + 32/2 = 31760
    //半像素: 3968/2*128/2 + 64/2 = 127008
    m_uiCbBaseOffset  = (m_acBufferParam[FRAME].m_iStride/2) * uiYMarginSize/2 + uiXMarginSize/2;
    m_uiCbBaseOffset += 4*m_uiChromaSize;
    m_bInitDone = true;

    return Err::m_nOK;
}


ErrVal YuvBufferCtrl::uninit()
{
    m_bInitDone = false;
    return Err::m_nOK;
}



}  //namespace JSVM {

