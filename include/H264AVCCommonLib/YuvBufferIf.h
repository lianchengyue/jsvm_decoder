#ifndef _YUVBUFFERRWIF_H_
#define _YUVBUFFERRWIF_H_


namespace JSVM {


class YuvBufferIf
{
protected:
  YuvBufferIf() {}
  virtual ~YuvBufferIf() {}
public:
  virtual const Int getCStride() const  = 0;
  virtual Pel* getLumBlk() = 0;
  virtual Pel* getYBlk(LumaIdx cIdx) = 0;
  virtual Pel* getUBlk(LumaIdx cIdx) = 0;
  virtual Pel* getVBlk(LumaIdx cIdx) = 0;
  virtual const Int getLStride() const = 0;

  virtual Pel* getMbLumAddr() = 0;
  virtual Pel* getMbCbAddr()  = 0;
  virtual Pel* getMbCrAddr()  = 0;

  virtual Void set4x4Block(LumaIdx cIdx) = 0;

  virtual const Int getLWidth() const = 0;
  virtual const Int getLHeight() const = 0;
  virtual const Int getLXMargin() const = 0;
  virtual const Int getLYMargin() const = 0;
  virtual const Int getCWidth() const = 0;
  virtual const Int getCHeight() const = 0;
};

}  //namespace JSVM {

#endif //_YUVBUFFERRWIF_H_
