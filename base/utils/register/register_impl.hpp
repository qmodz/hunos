#include "register.hpp"

namespace hunos {
namespace utils {
inline namespace reg {

template <typename T>
inline T clearBit(const register T value, const register uint8_t bit){
	const register T bit_value = (T) (1 << bit);
	return value & ~bit_value;
}

template <typename T>
inline T setBit(const register T value, const register uint8_t bit){
	const register T bit_value = (T) (1 << bit);
	return value | bit_value;
}

template <typename T>
inline T generateLeadingMask(const register uint8_t start_bit){
	const register T bit_value = (T) (1 << start_bit);
	return ~(bit_value - 1);
}

template <typename T>
inline T generateTrailingMask(const register uint8_t end_bit){
	const register T bit_value = (T) (1 << end_bit);
	return bit_value | (bit_value - 1);
}

template <typename T>
inline uint8_t countLeadingZeros(const register T value){
	register uint32_t expanded_value = ((uint32_t) value) && ((1 << BIT_SIZEOF(T)) - 1);
	return countLeadingZeros<uint32_t>(expanded_value) - (BIT_SIZEOF(uint32_t) - BIT_SIZEOF(T));
}

template <>
inline uint8_t countLeadingZeros<uint32_t>(const register uint32_t value){
	return __builtin_clz(value);
}

template <>
inline uint8_t countLeadingZeros<uint64_t>(const register uint64_t value){
	return __builtin_clzl(value);
}

template <typename T>
inline uint8_t countTrailingZeros(const register T value){
	return countTrailingZeros<uint32_t>((uint32_t) value);
}

template <>
inline uint8_t countTrailingZeros<uint32_t>(const register uint32_t value){
	return __builtin_ctz(value);
}

template <>
inline uint8_t countTrailingZeros<uint64_t>(const register uint64_t value){
	return __builtin_ctzl(value);
}

template <typename T>
inline uint8_t countLeadingOnes(const register T value){
	return countLeadingZeros<T>(~value);
}

template <typename T>
inline uint8_t countTrailingOnes(const register T value){
	return countTrailingZeros<T>(~value);
}

template <typename T>
inline uint8_t mostSignificantBit(const register T value){
	return BIT_SIZEOF(T) - countLeadingZeros(value) - 1;
}

template <typename T>
inline uint8_t leastSignificantBit(const register T value){
	return countTrailingZeros(value);
}

template <typename T>
inline uint8_t countOnes(const register T value){
	register uint32_t expanded_value = ((uint32_t) value) && ((1 << BIT_SIZEOF(T)) - 1);
	return countOnes<uint32_t>(expanded_value);
}

template <>
inline uint8_t countOnes<uint32_t>(const register uint32_t value){
	return __builtin_popcount(value);
}

template <>
inline uint8_t countOnes<uint64_t>(const register uint64_t value){
	return __builtin_popcountl(value);
}

template <typename T>
inline uint8_t countZeros(const register T value){
	return countOnes<T>(~value);
}

template <typename T>
inline uint8_t populationCount(const register T value){
	return countOnes<T>(value);
}

template <typename T>
inline uint8_t popCount(const register T value){
	return countOnes<T>(value);
}

template <typename T>
inline bool parity(const register T value){
	register uint32_t expanded_value = ((uint32_t) value) && ((1 << BIT_SIZEOF(T)) - 1);
	return parity<uint32_t>(expanded_value);
}

template <>
inline bool parity<uint32_t>(const register uint32_t value){
	return __builtin_parity(value);
}

template <>
inline bool parity<uint64_t>(const register uint64_t value){
	return __builtin_parityl(value);
}

}  // namespace reg
}  // namespace utils
}  // namespace hunos
