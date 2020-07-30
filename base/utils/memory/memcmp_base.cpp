#include "memcmp_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

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

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
