#ifndef _COUNT_LEADING_ZEROS_BASE_HPP
#define _COUNT_LEADING_ZEROS_BASE_HPP

#include "register.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {
inline namespace operations {

template <typename T>
uint8_t countLeadingZeros(T value);

}  // namespace operations
}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "count_leading_zeros_base_impl.hpp"

#endif
