#include "memset_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {

template <>
void alignedMemset<uint8_t>(uint8_t* ptr, uint8_t value, size_t num){
	while (num != 0){
		*ptr++ = value;

		--num;
	}
}

void* memset(void* ptr, int value, size_t num){
	uint8_t uint8_value = (uint8_t) value;
	uint16_t uint16_value = (uint16_t) uint8_value << 8 | uint8_value;
	uint32_t uint32_value = (uint32_t) uint16_value << 16 | uint16_value;

	unalignedMemset<uint32_t>((uint8_t *) ptr, uint32_value, num);

	return ptr;
}

}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
