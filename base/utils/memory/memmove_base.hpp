#ifndef _MEMMOVE_BASE_HPP
#define _MEMMOVE_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

void* memmove(void* destination, const void* source, size_t num);

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#endif
