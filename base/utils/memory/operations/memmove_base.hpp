#ifndef _MEMMOVE_BASE_HPP
#define _MEMMOVE_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

void* memmove(void* destination, const void* source, size_t num);

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#endif
