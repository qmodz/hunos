#ifndef _PARITY_BASE_HPP
#define _PARITY_BASE_HPP

#include "register.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {
inline namespace operations {

template <typename T>
bool parity(T value);

}  // namespace operations
}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "parity_base_impl.hpp"

#endif
