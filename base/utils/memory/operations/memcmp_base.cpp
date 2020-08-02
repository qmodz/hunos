#include "memcmp_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

template <>
int alignedMemcmp<uint8_t>(const uint8_t* ptr1, const uint8_t* ptr2, size_t num){
	while (num != 0 && *ptr1 == *ptr2){
		++ptr1;
		++ptr2;

		--num;
	}

	if (num == 0){
		return 0;
	} else if (*ptr1 < *ptr2) {
		return -1;
	} else {
		return 1;
	}
}

int memcmp(const void* ptr1, const void* ptr2, size_t num){
	uintptr_t ptr1_address = (uintptr_t) ptr1;
	uintptr_t ptr2_address = (uintptr_t) ptr2;

	if ((ptr1_address & 3) == (ptr2_address & 3)){
		return unalignedMemcmp<uint32_t>((const uint8_t *) ptr1, (const uint8_t *) ptr2, num);
	} else if ((ptr1_address & 1) == (ptr2_address & 1)){
		return unalignedMemcmp<uint16_t>((const uint8_t *) ptr1, (const uint8_t *) ptr2, num);
	} else {
		return alignedMemcmp<uint8_t>((const uint8_t *) ptr1, (const uint8_t *) ptr2, num);
	}
}

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
