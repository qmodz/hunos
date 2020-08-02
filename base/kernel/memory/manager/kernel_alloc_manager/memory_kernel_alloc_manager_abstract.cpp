#include "memory_kernel_alloc_manager_abstract.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

MemoryKernelAllocManagerAbstract::MemoryKernelAllocManagerAbstract(MemoryPageManager* page_manager, uintptr_t alloc_start_address) :
								utils::memory::manager::MemoryCacheAllocManagerAbstract(alloc_start_address),
								page_manager_(page_manager){

}

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos
