#include "count_leading_zeros_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {

template <typename T>
uint8_t countLeadingZeros(T value){
	const T mask = (T) (1 << (BIT_SIZEOF(T) - 1));
	uint8_t zeros = 0;

	while((value & mask) == 0 && zeros < BIT_SIZEOF(T)){
		value = value << 1;

		++zeros;
	}

	return zeros;
}

}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos
