#include "memory.hpp"
#include "memchr_base.hpp"

namespace hunos {
namespace utils {
inline namespace memory {

void* __attribute__((weak)) memchr(const void* ptr, int value, size_t num){
	return base::utils::memory::memchr(ptr, value, num);
}

}  // namespace memory
}  // namespace utils
}  // namespace hunos
