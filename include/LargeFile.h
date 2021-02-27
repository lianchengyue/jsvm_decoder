#ifndef _LARGEFILE_H_
#define _LARGEFILE_H_

#include "Typedefs.h"

class LargeFile
{
public:
    enum OpenMode
    {
        OM_READONLY,
        OM_WRITEONLY,
        OM_APPEND,
        OM_READWRITE
    };

public:
    LargeFile();
    ~LargeFile();

    ErrVal open(const std::string& rcFilename, enum OpenMode eOpenMode, int iPermMode=0777);

    bool is_open() const
    {
        return -1 != m_iFileHandle;
    }

    ErrVal close();
    ErrVal seek(Int64 iOffset, int iOrigin);
    Int64 tell();

    ErrVal read(Void *pvBuffer, UInt32 uiCount, UInt32& ruiBytesRead);
    ErrVal write(const Void *pvBuffer, UInt32 uiCount);

    Int getFileHandle()
    {
        return m_iFileHandle;
    }

private:
    Int m_iFileHandle;
};



#endif //_LARGEFILE_H_
