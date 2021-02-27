#ifndef _DECERROR_H_
#define _DECERROR_H_


#if defined (FAULT_TOLERANT)
 #define DECASSERT(x)
#else
 #define DECASSERT(x) ASSERT(x)
#endif


#define DECROF(exp)         \
{                             \
  if(!(exp))              \
  {                           \
    DECASSERT(0);           \
    return ERR_CLASS::m_nERR; \
  }                           \
}

#define DECROT(exp)         \
{                             \
  if((exp))               \
  {                           \
    DECASSERT(0);           \
    return ERR_CLASS::m_nERR; \
  }                           \
}


#define DECROFR(exp, retVal)   \
{                             \
  if(!(exp))              \
  {                           \
    DECASSERT(0);           \
    return retVal;            \
  }                           \
}

#define DECROTR(exp, retVal)   \
{                             \
  if((exp))               \
  {                           \
    DECASSERT(0);           \
    return retVal;            \
  }                           \
}


#define DECROFV(exp)        \
{                             \
  if(!(exp))              \
  {                           \
    DECASSERT(0);           \
    return;                   \
  }                           \
}

#define DECROTV(exp)        \
{                             \
  if((exp))               \
  {                           \
    DECASSERT(0);           \
    return;                   \
  }                           \
}

#if JVT_U125
#define DECRNOK(exp)            \
{                                 \
  const ERR_VAL nMSysRetVal = (exp);   \
  if(ERR_CLASS::m_nOK != nMSysRetVal)  \
  {                               \
    return nMSysRetVal;           \
  }                               \
}
#else
#define DECRNOK(exp)            \
{                                 \
  const ERR_VAL nMSysRetVal = (exp);   \
  if(ERR_CLASS::m_nOK != nMSysRetVal)  \
  {                               \
    DECASSERT(0);               \
    return nMSysRetVal;           \
  }                               \
}
#endif

#define DECRNOKR(exp, retVal)     \
{                                   \
  if(ERR_CLASS::m_nOK != (exp)) \
  {                                 \
    DECASSERT(0);                 \
    return retVal;                  \
  }                                 \
}


#define DECRNOKV(exp)             \
{                                   \
  if(ERR_CLASS::m_nOK != (exp)) \
  {                                 \
    DECASSERT(0);                 \
    return;                         \
  }                                 \
}


#endif //_DECERROR_H_
