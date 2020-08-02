#ifndef _OUTPUT_DRIVER_STUB_HPP
#define _OUTPUT_DRIVER_STUB_HPP

#include "output_driver_interface.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace output {

class OutputDriverStub : public OutputDriverInterface {
	public:
		size_t write(void* ptr, size_t size_of_elements, size_t number_of_elements);
};

}  // namespace output
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif
