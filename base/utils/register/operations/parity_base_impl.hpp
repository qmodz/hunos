#include "parity_base.hpp"
#include "count_ones_base.hpp"

namespace hunos {
namespace base {
namespace utils {
inline namespace reg {
inline namespace operations {

template <typename T>
bool parity(T value){
	uint8_t ones = countOnes<T>(value);

	return (bool) (ones & 1);
}

}  // namespace operations
}  // namespace reg
}  // namespace utils
}  // namespace base
}  // namespace hunos
