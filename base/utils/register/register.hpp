#ifndef _UTILS_REGISTER_HPP
#define _UTILS_REGISTER_HPP

#include "system/typedefs.hpp"

#define BIT_SIZEOF(a) (sizeof(a) << 3)

namespace hunos {
namespace utils {
inline namespace reg {

template <typename T>
inline T clearBit(const register T value, const register uint8_t bit);

template <typename T>
inline T setBit(const register T val, const register uint8_t bit);

template <typename T>
inline T generateLeadingMask(const register uint8_t start_bit);

template <typename T>
inline T generateTrailingMask(const register uint8_t end_bit);

template <typename T>
inline uint8_t countLeadingZeros(const register T value);

template <>
inline uint8_t countLeadingZeros<uint32_t>(const register uint32_t value);

template <>
inline uint8_t countLeadingZeros<uint64_t>(const register uint64_t value);

template <typename T>
inline uint8_t countTrailingZeros(const register T value);

template <>
inline uint8_t countTrailingZeros<uint32_t>(const register uint32_t value);

template <>
inline uint8_t countTrailingZeros<uint64_t>(const register uint64_t value);

template <typename T>
inline uint8_t countLeadingOnes(const register T value);

template <typename T>
inline uint8_t countTrailingOnes(const register T value);

template <typename T>
inline uint8_t mostSignificantSetBit(const register T value);

template <typename T>
inline uint8_t leastSignificantSetBit(const register T value);

template <typename T>
inline uint8_t countOnes(const register T value);

template <>
inline uint8_t countOnes<uint32_t>(const register uint32_t value);

template <>
inline uint8_t countOnes<uint64_t>(const register uint64_t value);

template <typename T>
inline uint8_t countZeros(const register T value);

template <typename T>
inline uint8_t populationCount(const register T value);

template <typename T>
inline uint8_t popCount(const register T value);

template <typename T>
inline bool parity(const register T value);

template <>
inline bool parity<uint32_t>(const register uint32_t value);

template <>
inline bool parity<uint64_t>(const register uint64_t value);

}  // namespace reg
}  // namespace utils
}  // namespace hunos

#include "register_impl.hpp"

#endif
