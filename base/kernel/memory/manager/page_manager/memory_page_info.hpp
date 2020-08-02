#ifndef _MEMORY_PAGE_INFO_HPP
#define _MEMORY_PAGE_INFO_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

struct MemoryPageInfo {
	MemoryPageInfo();
	MemoryPageInfo(uintptr_t address);

	uintptr_t address;
}; 

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos

#endif
