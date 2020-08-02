#ifndef _MEMSET_BASE_HPP
#define _MEMSET_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

void* memset(void* ptr, int value, size_t num);

template <typename T>
void alignedMemset(T* ptr, T value, size_t num);

template <>
void alignedMemset<uint8_t>(uint8_t* ptr, uint8_t value, size_t num);

template <typename T>
void unalignedMemset(uint8_t* ptr, T value, size_t num);

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "memset_base_impl.hpp"

#endif
