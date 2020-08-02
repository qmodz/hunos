#ifndef _OUTPUT_DRIVER_INTERFACE_HPP
#define _OUTPUT_DRIVER_INTERFACE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace kernel {
namespace drivers {
inline namespace output {

class OutputDriverInterface {
	public:
		virtual size_t write(void* ptr, size_t size_of_elements, size_t number_of_elements) = 0;
};

}  // namespace output
}  // namespace drivers
}  // namespace kernel
}  // namespace hunos

#endif
