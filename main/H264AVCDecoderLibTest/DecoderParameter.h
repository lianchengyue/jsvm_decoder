#ifndef _DECODERPARAMETER_H_
#define _DECODERPARAMETER_H_

class DecoderParameter
{
public:
    DecoderParameter();
    virtual ~DecoderParameter();

    ErrVal init(Int argc, Char** argv);

    std::string  cBitstreamFile;
    std::string  cYuvFile;
    Int          nResult;
    UInt         nFrames;
    UInt         uiMaxPocDiff;
    UInt         uiErrorConceal;
protected:
    ErrVal xPrintUsage(Char** argv);
};

#endif //_DECODERPARAMETER_H_
