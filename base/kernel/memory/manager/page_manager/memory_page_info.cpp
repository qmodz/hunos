#include "memory_page_info.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

MemoryPageInfo::MemoryPageInfo() {

}

MemoryPageInfo::MemoryPageInfo(uintptr_t address) : address(address) {

}

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos
