#include "memcpy_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

template <typename T>
void alignedForwardMemcpy(T* destination, const T* source, size_t num){
	while (num >= sizeof(T)){
		*destination++ = *source++;

		num -= sizeof(T);
	}

	alignedForwardMemcpy<uint8_t>((uint8_t *) destination, (const uint8_t *) source, num);
}

template <typename T>
void alignedBackwardMemcpy(T* end_destination, const T* end_source, size_t num){
	while (num != 0){
		*(--end_destination) = *(--end_source);

		num -= sizeof(T);
	}

	alignedBackwardMemcpy<uint8_t>((uint8_t *) end_destination, (const uint8_t *) end_source, num);
}

template <typename T>
void unalignedForwardMemcpy(uint8_t* destination, const uint8_t* source, size_t num){
	uintptr_t destination_address = (uintptr_t) destination;
	uintptr_t aligment = (-destination_address) & (sizeof(T) - 1);
	size_t num_aligment = num > aligment ? aligment : num;

	if (num_aligment > 0){
		alignedForwardMemcpy<uint8_t>(destination, source, num_aligment);

		destination += num_aligment;
		source += num_aligment;
		num -= num_aligment;
	}

	alignedForwardMemcpy<T>((T *) destination, (const T *) source, num);
}

template <typename T>
void unalignedBackwardMemcpy(uint8_t* end_destination, const uint8_t* end_source, size_t num){
	uintptr_t end_destination_address = (uintptr_t) end_destination;
	uintptr_t aligment = end_destination_address & (sizeof(T) - 1);
	size_t num_aligment = num > aligment ? aligment : num;

	if (num_aligment > 0){
		alignedForwardMemcpy<uint8_t>(end_destination, end_source, num_aligment);

		end_destination -= num_aligment;
		end_source -= num_aligment;
		num -= num_aligment;
	}

	alignedBackwardMemcpy<T>((T *) end_destination, (const T *) end_source, num);
}

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
