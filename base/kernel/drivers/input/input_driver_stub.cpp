#include "input_driver_stub.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace input {

size_t InputDriverStub::read(void* ptr, size_t size_of_elements, size_t number_of_elements){
	return 0;
}

}  // namespace input
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos
