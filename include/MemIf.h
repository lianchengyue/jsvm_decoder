#ifndef _MEMIF_H_
#define _MEMIF_H_

#include <string.h>

enum MemType
{
    MEM_CONT = 0,
    MEM_LIST = 1
};

template<class T>  class MemIf
{
public:
    MemIf() {}
    virtual ~MemIf() {}

public:
    virtual MemType getMemType() const = 0;

    virtual Void set (MemIf< T >& rcMemIf) = 0;
    virtual Void set (T* pcT, UInt uiSize, T* pcDeleteT=NULL, UInt uiUsableSize=0) = 0;

    virtual Void release (T*& rpcT, UInt& ruiSize) = 0;
    virtual Void release (T*& rpcT, UInt& ruiSize, T*& rpcDeleteT, UInt& ruiUsableSize) = 0;

    virtual Void deleteData() = 0;

    virtual UInt size() const = 0;
    virtual UInt byteSize() const = 0;
};


#endif //_MEMIF_H_
