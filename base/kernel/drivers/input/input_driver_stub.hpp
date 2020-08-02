#ifndef _INPUT_DRIVER_STUB_HPP
#define _INPUT_DRIVER_STUB_HPP

#include "input_driver_interface.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace input {

class InputDriverStub : public InputDriverInterface {
	public:
		size_t read(void* ptr, size_t size_of_elements, size_t number_of_elements);
};

}  // namespace input
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif