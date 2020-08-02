#include "output_driver_stub.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace output {

size_t OutputDriverStub::write(void* ptr, size_t size_of_elements, size_t number_of_elements){
	return 0;
}

}  // namespace output
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos
