#include "memchr_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

void* memchr(const void* ptr, int value, size_t num){
	const char* char_ptr = (const char *) ptr;
	unsigned char c = (unsigned char) value;

	while (num-- != 0){
		if (*char_ptr == c){
			return (void *) char_ptr;
		}
		
		++char_ptr;
	}

	return nullptr;
}

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
