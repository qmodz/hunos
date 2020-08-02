#ifndef _INPUT_OUTPUT_DRIVER_STUB_HPP
#define _INPUT_OUTPUT_DRIVER_STUB_HPP

#include "system/typedefs.hpp"

#include "../input/input_driver_stub.hpp"
#include "../output/output_driver_stub.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace inputoutput {

class InputOutputDriverStub : public InputDriverStub, public OutputDriverStub {
	
};

}  // namespace inputoutput
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif
