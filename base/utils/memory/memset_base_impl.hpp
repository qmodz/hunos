#include "memset_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

template <typename T>
void alignedMemset(T* ptr, T value, size_t num){
	while (num >= sizeof(T)){
		*ptr++ = value;

		num -= sizeof(T);
	}

	alignedMemset<uint8_t>((uint8_t *) ptr, (uint8_t) value, num);
}

template <typename T>
void unalignedMemset(uint8_t* ptr, T value, size_t num){
	uint8_t uint8_value = (uint8_t) value;

	uintptr_t ptr_address = (uintptr_t) ptr;
	uintptr_t aligment = (-ptr_address) & (sizeof(T) - 1);
	size_t num_aligment = num > aligment ? aligment : num;

	if (num_aligment > 0){
		alignedMemset<uint8_t>(ptr, uint8_value, num_aligment);

		ptr += num_aligment;
		num -= num_aligment;
	}
	
	alignedMemset<T>((T *) ptr, value, num);
}

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
