#include "count_trailing_zeros_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {
inline namespace operations {

template <typename T>
uint8_t countTrailingZeros(T value){
	uint8_t zeros = 0;

	while((value & 1) == 0 && zeros < BIT_SIZEOF(T)){
		value = value >> 1;

		++zeros;
	}

	return zeros;
}

}  // namespace operations
}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos
