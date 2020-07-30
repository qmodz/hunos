#ifndef _MEMCHR_BASE_HPP
#define _MEMCHR_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

void* memchr(const void* ptr, int value, size_t num);

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#endif
