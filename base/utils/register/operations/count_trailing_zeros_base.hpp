#ifndef _COUNT_TRAILING_ZEROS_BASE_HPP
#define _COUNT_TRAILING_ZEROS_BASE_HPP

#include "register.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {
inline namespace operations {

template <typename T>
uint8_t countTrailingZeros(T value);

}  // namespace operations
}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "count_trailing_zeros_base_impl.hpp"

#endif
