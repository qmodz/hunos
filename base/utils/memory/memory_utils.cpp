#include "memory.hpp"
#include "memchr_base.hpp"
#include "memcmp_base.hpp"
#include "memcpy_base.hpp"
#include "memmove_base.hpp"
#include "memset_base.hpp"

namespace hunos {
namespace utils {
inline namespace memory {

void* __attribute__((weak)) memchr(const void* ptr, int value, size_t num){
	return base::utils::memory::memchr(ptr, value, num);
}

int __attribute__((weak)) memcmp(const void* ptr1, const void* ptr2, size_t num){
	return base::utils::memory::memcmp(ptr1, ptr2, num);
}

void* __attribute__((weak)) memcpy(void* destination, const void* source, size_t num){
	return base::utils::memory::memcpy(destination, source, num);
} 

void* __attribute__((weak)) memmove(void* destination, const void* source, size_t num){
	return base::utils::memory::memmove(destination, source, num);
}

void* __attribute__((weak)) memset(void* ptr, int value, size_t num){
	return base::utils::memory::memset(ptr, value, num);
}

}  // namespace memory
}  // namespace utils
}  // namespace hunos