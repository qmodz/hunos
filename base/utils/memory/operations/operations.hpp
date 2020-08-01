#ifndef _UTILS_MEMORY_OPERATION_HPP
#define _UTILS_MEMORY_OPERATIONS_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace operations {

void* memchr(const void* ptr, int value, size_t num);
int memcmp(const void* ptr1, const void* ptr2, size_t num);
void* memcpy(void* destination, const void* source, size_t num);
void* memmove(void* destination, const void* source, size_t num);
void* memset(void* ptr, int value, size_t num);

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace hunos

#endif
