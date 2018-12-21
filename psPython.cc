#include <picoscopeInterface.h>
#include <ps6000.h>
#include <ps5000a.h>




#include <boost/python.hpp>
using namespace boost::python;


list waveform_wrapper(picoscope::picoscopeBase *p)
{
  list result;
  vector <vector<short> > &data = p->getWaveforms();
  for (auto &w : data) {
    list wv;
    for (int i= 0; i < w.size(); i++) {
      wv.append(w[i]);
    }
    result.append(wv);
  }
  return result; 
}


BOOST_PYTHON_MODULE(pscope)
{


  

  using namespace picoscope;

  enum_<chName>("chName")
    .value("A", chName::A)
    .value("B", chName::B)
    .value("C", chName::C)
    .value("D", chName::D)
    .value("EXT", chName::EXT)
    .value("AUX", chName::AUX);

  enum_<chBandwidth>("chBandwidth")
    .value("BW_FULL", chBandwidth::BW_FULL)
    .value("BW_25MHZ",  chBandwidth::BW_25MHZ)
    .value("BW_20MHZ",  chBandwidth::BW_20MHZ); 

  enum_<chCoupling>("chCoupling")
    .value("DC_50R", chCoupling::DC_50R)
    .value("DC", chCoupling::DC)
    .value("AC", chCoupling::AC);

  enum_<chRange>("chRange")
    .value("PS_10MV", chRange::PS_10MV)
    .value("PS_20MV", chRange::PS_20MV)
    .value("PS_50MV", chRange::PS_50MV)
    .value("PS_100MV", chRange::PS_100MV)
    .value("PS_200MV", chRange::PS_200MV)
    .value("PS_500MV", chRange::PS_500MV)
    .value("PS_1V", chRange::PS_1V)
    .value("PS_2V", chRange::PS_2V)
    .value("PS_5V", chRange::PS_5V)
    .value("PS_10V", chRange::PS_10V)
    .value("PS_20V", chRange::PS_20V)
    .value("PS_50V", chRange::PS_50V);

  enum_<devResolution>("devResolution")
    .value("PS_8BIT", devResolution::PS_8BIT)
    .value("PS_12BIT", devResolution::PS_12BIT)
    .value("PS_14BIT", devResolution::PS_14BIT)
    .value("PS_15BIT", devResolution::PS_15BIT)
    .value("PS_16BIT", devResolution::PS_16BIT);

  enum_<triggerDirection>("triggerDirection")
    .value("trgRising", triggerDirection::trgRising)
    .value("trgFalling", triggerDirection::trgFalling)
    .value("trgAbove", triggerDirection::trgAbove)
    .value("trgBelow", triggerDirection::trgBelow)
    .value("trgAboveLower", triggerDirection::trgAboveLower)
    .value("trgBelowLower", triggerDirection::trgBelowLower)
    .value("trgRisingLower", triggerDirection::trgRisingLower)
    .value("trgFallingLower", triggerDirection::trgFallingLower)
    .value("trgInside", triggerDirection::trgInside)
    .value("trgOutside", triggerDirection::trgOutside)
    .value("trgEnter", triggerDirection::trgEnter)
    .value("trgExit", triggerDirection::trgExit)
    .value("trgEnterOrExit", triggerDirection::trgEnterOrExit)
    .value("trgPositiveRunt", triggerDirection::trgPositiveRunt)
    .value("trgNegativeRunt", triggerDirection::trgNegativeRunt)
    .value("trgNone", triggerDirection::trgNone); 

  enum_<triggerThreshold>("triggerThreshold")
    .value("level", triggerThreshold::level)
    .value("window", triggerThreshold::window);

  enum_<triggerState>("triggerState")
    .value("trgDontCare", triggerState::trgDontCare)
    .value("trgTrue", triggerState::trgTrue)
    .value("trgFalse", triggerState::trgFalse)
    .value("trgMax", triggerState::trgMax); 
  
  class_<picoscopeBase>("picoscopeBase")
    .def("open", &picoscopeBase::open)
    .def("close", &picoscopeBase::close)
    ;


  
  class_<ps6000, bases<picoscopeBase> >("ps6000")
    .def("open", &ps6000::open)
    .def("close", &ps6000::close)
    .def("captureBlocks", &ps6000::captureBlocks)
    .def("setChCoupling", &ps6000::setChCoupling)
    .def("enableChannel", &ps6000::enableChannel)
    .def("setChRange", &ps6000::setChRange)
    .def("setTimebase", &ps6000::setTimebase)
    .def("setSimpleTrigger", &ps6000::setSimpleTrigger)
    .def("setSamples", &ps6000::setSamples)
    .def("setCaptureCount", &ps6000::setCaptureCount)
    .def("setPreTriggerSamples", &ps6000::setPreTriggerSamples)
    .def("setPostTriggerSamples", &ps6000::setPostTriggerSamples)
    .def("prepareBuffers", &ps6000::prepareBuffers)
    .def("captureBlock", &ps6000::captureBlock)
    .def("getWaveforms", waveform_wrapper)
    .def("timebaseNS", &ps6000::timebaseNS); 
    ;

    class_<ps5000a, bases<picoscopeBase> >("ps5000a")
    .def("open", &ps5000a::open)
    .def("close", &ps5000a::close)
    .def("captureBlocks", &ps5000a::captureBlocks)
    .def("setChCoupling", &ps5000a::setChCoupling)
    .def("enableChannel", &ps5000a::enableChannel)
    .def("setChRange", &ps5000a::setChRange)
    .def("setTimebase", &ps5000a::setTimebase)
    .def("setSimpleTrigger", &ps5000a::setSimpleTrigger)
    .def("setSamples", &ps5000a::setSamples)
    .def("setCaptureCount", &ps5000a::setCaptureCount)
    .def("setPreTriggerSamples", &ps5000a::setPreTriggerSamples)
    .def("setPostTriggerSamples", &ps5000a::setPostTriggerSamples)
    .def("prepareBuffers", &ps5000a::prepareBuffers)
    .def("captureBlock", &ps5000a::captureBlock)
    .def("getWaveforms", waveform_wrapper)
    .def("timebaseNS", &ps5000a::timebaseNS); 
    ;

 
}
