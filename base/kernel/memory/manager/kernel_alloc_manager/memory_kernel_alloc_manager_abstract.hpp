#ifndef _MEMORY_KERNEL_ALLOC_MANGER_ABSTRACT_HPP
#define _MEMORY_KERNEL_ALLOC_MANGER_ABSTRACT_HPP

#include "utils/memory/manager/cache_alloc_manager/memory_cache_alloc_manager_abstract.hpp"

#include "../page_manager/memory_page_manager.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

class MemoryKernelAllocManagerAbstract : public utils::memory::manager::MemoryCacheAllocManagerAbstract {
	public:
		MemoryKernelAllocManagerAbstract(MemoryPageManager* page_manager, uintptr_t alloc_start_address);

	protected:
		MemoryPageManager* page_manager_;
};

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos

#endif
