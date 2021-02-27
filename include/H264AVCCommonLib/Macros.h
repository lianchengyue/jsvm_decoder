#ifndef _COMMON_MACROS_H_
#define _COMMON_MACROS_H_


#define H264AVC_DELETE(x)        {if(NULL != x){ delete [] x; x = NULL;}}
#define H264AVC_DELETE_CLASS(x)  {if(NULL != x){ delete    x; x = NULL;}}

#endif //_COMMON_MACROS_H_
