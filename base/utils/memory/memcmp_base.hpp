#ifndef _MEMCMP_BASE_HPP
#define _MEMCMP_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

int memcmp(const void* ptr1, const void* ptr2, size_t num);

template <typename T>
int alignedMemcmp(const T* ptr1, const T* ptr2, size_t num);

template <>
int alignedMemcmp<uint8_t>(const uint8_t* ptr1, const uint8_t* ptr2, size_t num);

template <typename T>
int unalignedMemcmp(const uint8_t* ptr1, const uint8_t* ptr2, size_t num);

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "memcmp_base_impl.hpp"

#endif
