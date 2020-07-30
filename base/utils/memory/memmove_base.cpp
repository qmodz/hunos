#include "memmove_base.hpp"
#include "memcpy_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

void* memmove(void* destination, const void* source, size_t num){
	uintptr_t dest_address = (uintptr_t) destination;
	uintptr_t src_address = (uintptr_t) source;

	if (dest_address < src_address){
		forwardMemcpy(destination, source, num);
	} else if (dest_address > src_address){
		backwardMemcpy(destination, source, num);
	}

	return destination;
}

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
