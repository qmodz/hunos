#ifndef _COUNT_ONES_BASE_HPP
#define _COUNT_ONES_BASE_HPP

#include "register.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {

template <typename T>
uint8_t countOnes(T value);

}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "count_ones_base_impl.hpp"

#endif
