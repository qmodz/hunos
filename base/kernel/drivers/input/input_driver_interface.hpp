#ifndef _INPUT_DRIVER_INTERFACE_HPP
#define _INPUT_DRIVER_INTERFACE_HPP

#include "system/typedefs.hpp"

#include "../driver_interface.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace input {

class InputDriverInterface : public DriverInterface {
	public:
		virtual size_t read(void* ptr, size_t size_of_elements, size_t number_of_elements) = 0;
};

}  // namespace input
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif
