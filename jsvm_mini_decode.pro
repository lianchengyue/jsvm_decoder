QT += core
QT -= gui

CONFIG += c++11

TARGET = jsvm_mini_decode
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


DEFINES += \
    MSYS_LINUX \
    MSYS_UNIX_LARGEFILE \
#
#    SHARP_AVC_REWRITE_OUTPUT \
#下
#    DOWN_CONVERT_STATIC \
#trace
    DECODER_TRACE \

HEADERS += \
#Include
    include/CodingParameter.h \
    include/CreaterH264AVCDecoder.h \
    include/CreaterH264AVCEncoder.h \
    include/DownConvert.h \
    include/H264AVCCommonIf.h \
    include/H264AVCCommonLib.h \
    include/H264AVCDecoderLib.h \
    include/H264AVCEncoderLib.h \
    include/H264AVCVideoIoLib.h \
    include/H264AVCVideoLib.h \
    include/LargeFile.h \
    include/Macros.h \
    include/MemAccessor.h \
    include/MemCont.h \
    include/MemIf.h \
    include/MemList.h \
    include/RateCtlBase.h \
    include/RateCtlQuadratic.h \
    include/ReadBitstreamFile.h \
    include/ReadBitstreamIf.h \
    include/ReadPEStream.h \
    include/ReadYuvFile.h \
    include/ResizeParameters.h \
    include/Typedefs.h \
    include/WriteBitstreamIf.h \
    include/WriteBitstreamToFile.h \
    include/WriteYuvIf.h \
    include/WriteYuvToFile.h \
    include/H264AVCCommonLib/CabacContextModel.h \
    include/H264AVCCommonLib/CabacContextModel2DBuffer.h \
    include/H264AVCCommonLib/CabacTables.h \
    include/H264AVCCommonLib/CFMO.h \
    include/H264AVCCommonLib/CommonBuffers.h \
    include/H264AVCCommonLib/CommonDefs.h \
    include/H264AVCCommonLib/CommonTypes.h \
    include/H264AVCCommonLib/ContextTables.h \
    include/H264AVCCommonLib/ControlMngIf.h \
    include/H264AVCCommonLib/Frame.h \
    include/H264AVCCommonLib/GlobalFunctions.h \
    include/H264AVCCommonLib/HeaderSymbolReadIf.h \
    include/H264AVCCommonLib/HeaderSymbolWriteIf.h \
    include/H264AVCCommonLib/Hrd.h \
    include/H264AVCCommonLib/IntraPrediction.h \
    include/H264AVCCommonLib/LoopFilter.h \
    include/H264AVCCommonLib/Macros.h \
    include/H264AVCCommonLib/MbData.h \
    include/H264AVCCommonLib/MbDataAccess.h \
    include/H264AVCCommonLib/MbDataCtrl.h \
    include/H264AVCCommonLib/MbDataStruct.h \
    include/H264AVCCommonLib/MbMvData.h \
    include/H264AVCCommonLib/MbTransformCoeffs.h \
    include/H264AVCCommonLib/MotionCompensation.h \
    include/H264AVCCommonLib/MotionVectorCalculation.h \
    include/H264AVCCommonLib/Mv.h \
    include/H264AVCCommonLib/ParameterSetMng.h \
    include/H264AVCCommonLib/PictureParameterSet.h \
    include/H264AVCCommonLib/PocCalculator.h \
    include/H264AVCCommonLib/Quantizer.h \
    include/H264AVCCommonLib/QuarterPelFilter.h \
    include/H264AVCCommonLib/ReconstructionBypass.h \
    include/H264AVCCommonLib/SampleWeighting.h \
    include/H264AVCCommonLib/ScalingMatrix.h \
    include/H264AVCCommonLib/Sei.h \
    include/H264AVCCommonLib/SequenceParameterSet.h \
    include/H264AVCCommonLib/SliceHeader.h \
    include/H264AVCCommonLib/SliceHeaderBase.h \
    include/H264AVCCommonLib/Tables.h \
    include/H264AVCCommonLib/TraceFile.h \
    include/H264AVCCommonLib/Transform.h \
    include/H264AVCCommonLib/Vui.h \
    include/H264AVCCommonLib/YuvBufferCtrl.h \
    include/H264AVCCommonLib/YuvBufferIf.h \
    include/H264AVCCommonLib/YuvMbBuffer.h \
    include/H264AVCCommonLib/YuvPicBuffer.h \
#Common
    src/H264AVCCommonLib/resource.h \
#Decoder
    src/H264AVCDecoderLib/BitReadBuffer.h \
    src/H264AVCDecoderLib/CabacReader.h \
    src/H264AVCDecoderLib/CabaDecoder.h \
    src/H264AVCDecoderLib/ControlMngH264AVCDecoder.h \
    src/H264AVCDecoderLib/DecError.h \
    src/H264AVCDecoderLib/GOPDecoder.h \
    src/H264AVCDecoderLib/H264AVCDecoder.h \
    src/H264AVCDecoderLib/MbDecoder.h \
    src/H264AVCDecoderLib/MbParser.h \
    src/H264AVCDecoderLib/MbSymbolReadIf.h \
    src/H264AVCDecoderLib/NalUnitParser.h \
    src/H264AVCDecoderLib/resource.h \
    src/H264AVCDecoderLib/SliceDecoder.h \
    src/H264AVCDecoderLib/SliceReader.h \
    src/H264AVCDecoderLib/UvlcReader.h \
#Video
    src/H264AVCVideoIoLib/resource.h \
    src/H264AVCVideoIoLib/WriteYuvaToRgb.h \
##DecoderTest, H264AVCDecoderLibTest
    main/H264AVCDecoderLibTest/DecoderParameter.h \
    main/H264AVCDecoderLibTest/H264AVCDecoderLibTest.h \
    main/H264AVCDecoderLibTest/H264AVCDecoderTest.h \

SOURCES += \
#Common
    src/H264AVCCommonLib/CabacContextModel.cpp \
    src/H264AVCCommonLib/CabacContextModel2DBuffer.cpp \
    src/H264AVCCommonLib/CFMO.cpp \
    src/H264AVCCommonLib/DownConvert.cpp \
    src/H264AVCCommonLib/Frame.cpp \
    src/H264AVCCommonLib/H264AVCCommonLib.cpp \
    src/H264AVCCommonLib/Hrd.cpp \
    src/H264AVCCommonLib/IntraPrediction.cpp \
    src/H264AVCCommonLib/LoopFilter.cpp \
    src/H264AVCCommonLib/MbData.cpp \
    src/H264AVCCommonLib/MbDataAccess.cpp \
    src/H264AVCCommonLib/MbDataCtrl.cpp \
    src/H264AVCCommonLib/MbDataStruct.cpp \
    src/H264AVCCommonLib/MbMvData.cpp \
    src/H264AVCCommonLib/MbTransformCoeffs.cpp \
    src/H264AVCCommonLib/MotionCompensation.cpp \
    src/H264AVCCommonLib/MotionVectorCalculation.cpp \
    src/H264AVCCommonLib/Mv.cpp \
    src/H264AVCCommonLib/ParameterSetMng.cpp \
    src/H264AVCCommonLib/PictureParameterSet.cpp \
    src/H264AVCCommonLib/PocCalculator.cpp \
    src/H264AVCCommonLib/Quantizer.cpp \
    src/H264AVCCommonLib/QuarterPelFilter.cpp \
    src/H264AVCCommonLib/ReconstructionBypass.cpp \
    src/H264AVCCommonLib/ResizeParameters.cpp \
    src/H264AVCCommonLib/SampleWeighting.cpp \
    src/H264AVCCommonLib/ScalingMatrix.cpp \
    src/H264AVCCommonLib/Sei.cpp \
    src/H264AVCCommonLib/SequenceParameterSet.cpp \
    src/H264AVCCommonLib/SliceHeader.cpp \
    src/H264AVCCommonLib/SliceHeaderBase.cpp \
    src/H264AVCCommonLib/Tables.cpp \
    src/H264AVCCommonLib/TraceFile.cpp \
    src/H264AVCCommonLib/Transform.cpp \
    src/H264AVCCommonLib/Vui.cpp \
    src/H264AVCCommonLib/YuvBufferCtrl.cpp \
    src/H264AVCCommonLib/YuvMbBuffer.cpp \
    src/H264AVCCommonLib/YuvPicBuffer.cpp \
#Decoder
    src/H264AVCDecoderLib/BitReadBuffer.cpp \
    src/H264AVCDecoderLib/CabacReader.cpp \
    src/H264AVCDecoderLib/CabaDecoder.cpp \
    src/H264AVCDecoderLib/ControlMngH264AVCDecoder.cpp \
    src/H264AVCDecoderLib/CreaterH264AVCDecoder.cpp \
    src/H264AVCDecoderLib/GOPDecoder.cpp \
    src/H264AVCDecoderLib/H264AVCDecoder.cpp \
    src/H264AVCDecoderLib/H264AVCDecoderLib.cpp \
    src/H264AVCDecoderLib/MbDecoder.cpp \
    src/H264AVCDecoderLib/MbParser.cpp \
    src/H264AVCDecoderLib/NalUnitParser.cpp \
    src/H264AVCDecoderLib/SliceDecoder.cpp \
    src/H264AVCDecoderLib/SliceReader.cpp \
    src/H264AVCDecoderLib/UvlcReader.cpp \
#Video
    src/H264AVCVideoIoLib/H264AVCVideoIoLib.cpp \
    src/H264AVCVideoIoLib/LargeFile.cpp \
    src/H264AVCVideoIoLib/ReadBitstreamFile.cpp \
    src/H264AVCVideoIoLib/ReadYuvFile.cpp \
    src/H264AVCVideoIoLib/WriteBitstreamToFile.cpp \
    src/H264AVCVideoIoLib/WriteYuvaToRgb.cpp \
    src/H264AVCVideoIoLib/WriteYuvToFile.cpp \
##DecoderTest, H264AVCDecoderLibTest
    main/H264AVCDecoderLibTest/DecoderParameter.cpp \
    main/H264AVCDecoderLibTest/H264AVCDecoderLibTest.cpp \
    main/H264AVCDecoderLibTest/H264AVCDecoderTest.cpp \

INCLUDEPATH += \
    include \
    src/lib \
#Common
    src/H264AVCCommonLib \
#Decoder
    src/H264AVCDecoderLib \
#Video
    src/H264AVCVideoIoLib \
