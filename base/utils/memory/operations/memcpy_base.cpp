#include "memcpy_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace memory {
inline namespace operations {

template <>
void alignedForwardMemcpy<uint8_t>(uint8_t* destination, const uint8_t* source, size_t num){
	while (num != 0){
		*destination++ = *source++;

		--num;
	}
}

template <>
void alignedBackwardMemcpy<uint8_t>(uint8_t* end_destination, const uint8_t* end_source, size_t num){
	while (num != 0){
		*(--end_destination) = *(--end_source);

		--num;
	}
}

void* memcpy(void* destination, const void* source, size_t num){
	return forwardMemcpy(destination, source, num);
} 

void* forwardMemcpy(void* destination, const void* source, size_t num){
	uintptr_t destination_address = (uintptr_t) destination;
	uintptr_t source_address = (uintptr_t) source;

	if ((destination_address & 3) == (source_address & 3)){
		unalignedForwardMemcpy<uint32_t>((uint8_t *) destination, (const uint8_t *) source, num);
	} else if ((destination_address & 1) == (source_address & 1)){
		unalignedForwardMemcpy<uint16_t>((uint8_t *) destination, (const uint8_t *) source, num);
	} else {
		alignedForwardMemcpy<uint8_t>((uint8_t *) destination, (const uint8_t *) source, num);
	}

	return destination;
}

void* backwardMemcpy(void* destination, const void* source, size_t num){
	uintptr_t end_destination_address = (uintptr_t) destination + num;
	uintptr_t end_source_address = (uintptr_t) source + num;

	void* end_destination = (void *) end_destination_address;
	const void* end_source = (const void *) end_source_address;

	if ((end_destination_address & 3) == (end_source_address & 3)){
		unalignedBackwardMemcpy<uint32_t>((uint8_t *) end_destination, (const uint8_t *) end_source, num);
	} else if ((end_destination_address & 1) == (end_source_address & 1)){
		unalignedBackwardMemcpy<uint16_t>((uint8_t *) end_destination, (const uint8_t *) end_source, num);
	} else {
		alignedBackwardMemcpy<uint8_t>((uint8_t *) end_destination, (const uint8_t *) end_source, num);
	}

	return destination;
}

}  // namespace operations
}  // namespace memory
}  // namespace utils
}  // namespace base
}  // namespace hunos
