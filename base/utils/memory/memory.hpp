#ifndef _UTILS_MEMORY_HPP
#define _UTILS_MEMORY_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace utils {
inline namespace memory {

void* memchr(const void* ptr, int value, size_t num);
int memcmp(const void* ptr1, const void* ptr2, size_t num);
void* memcpy(void* destination, const void* source, size_t num);

}  // namespace memory
}  // namespace utils
}  // namespace hunos

#endif
