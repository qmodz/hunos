#ifndef _INPUT_OUTPUT_DRIVER_INTERFACE_HPP
#define _INPUT_OUTPUT_DRIVER_INTERFACE_HPP

#include "system/typedefs.hpp"

#include "../input/input_driver_interface.hpp"
#include "../output/output_driver_interface.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace inputoutput {

class InputOutputDriverInterface : public InputDriverInterface, public OutputDriverInterface {
	
};

}  // namespace inputoutput
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif
