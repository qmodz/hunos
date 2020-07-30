#include "memcmp_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

template <typename T>
static int alignMemcmp(const uint8_t** ptr1, const uint8_t** ptr2, size_t* num);

template <typename T>
int alignedMemcmp(const T* ptr1, const T* ptr2, size_t num){
	while (num >= sizeof(T) && *ptr1 == *ptr2){
		++ptr1;
		++ptr2;

		num -= sizeof(T);
	}

	return alignedMemcmp<uint8_t>((const uint8_t *) ptr1, (const uint8_t *) ptr2, num);
}

template <typename T>
int unalignedMemcmp(const uint8_t* ptr1, const uint8_t* ptr2, size_t num){
	int cmp_result = alignMemcmp<T>(&ptr1, &ptr2, &num);
	if (cmp_result == 0){
		cmp_result = alignedMemcmp<T>((const T *) ptr1, (const T *) ptr2, num);
	}
		
	return cmp_result;
}

template <typename T>
static int alignMemcmp(const uint8_t** ptr1, const uint8_t** ptr2, size_t* num){
	uintptr_t ptr1_address = (uintptr_t) *ptr1;
	uintptr_t aligment = (-ptr1_address) & (sizeof(T) - 1);
	size_t num_aligment = *num > aligment ? aligment : *num;

	if (num_aligment == 0){
		return 0;
	}

	int cmp_result = alignedMemcmp<uint8_t>(*ptr1, *ptr2, num_aligment);
	
	*ptr1 += num_aligment;
	*ptr2 += num_aligment;
	*num -= num_aligment;

	return cmp_result;
}

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
