#ifndef _READBITSTREAMIF_H_
#define _READBITSTREAMIF_H_

class ReadBitstreamIf
{
public:
  ReadBitstreamIf()
  {
  }
  virtual ~ReadBitstreamIf()
  {
  }

  virtual ErrVal extractPacket (BinData*& rpcBinData, Bool& rbEOS) = 0;
  virtual ErrVal releasePacket (BinData* pcBinData) = 0;

  virtual ErrVal getPosition(Int& iPos) = 0;
  virtual ErrVal setPosition(Int  iPos) = 0;
  virtual Int64  getFilePos() = 0;

  virtual ErrVal uninit() = 0;
  virtual ErrVal destroy() = 0;

};

#endif //_READBITSTREAMIF_H_
