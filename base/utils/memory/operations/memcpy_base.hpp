#ifndef _MEMCPY_BASE_HPP
#define _MEMCPY_BASE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

void* memcpy(void* destination, const void* source, size_t num);
void* forwardMemcpy(void* destination, const void* source, size_t num);
void* backwardMemcpy(void* destination, const void* source, size_t num);

template <typename T>
void alignedForwardMemcpy(T* destination, const T* source, size_t num);

template <>
void alignedForwardMemcpy<uint8_t>(uint8_t* destination, const uint8_t* source, size_t num);

template <typename T>
void alignedBackwardMemcpy(T* end_destination, const T* end_source, size_t num);

template <>
void alignedBackwardMemcpy<uint8_t>(uint8_t* end_destination, const uint8_t* end_source, size_t num);

template <typename T>
void unalignedForwardMemcpy(uint8_t* destination, const uint8_t* source, size_t num);

template <typename T>
void unalignedBackwardMemcpy(uint8_t* end_destination, const uint8_t* end_source, size_t num);

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos

#include "memcpy_base_impl.hpp"

#endif
