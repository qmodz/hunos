#include "count_ones_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {

template <typename T>
uint8_t countOnes(T value){
	uint8_t bit = 0;
	uint8_t ones = 0;

	while(bit < BIT_SIZEOF(T)){
		ones += (value & 1);
		++bit;

		value = value >> 1;
	}

	return ones;
}

}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos
