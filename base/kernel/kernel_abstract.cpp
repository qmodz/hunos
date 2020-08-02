#include "kernel_abstract.hpp"

namespace hunos {
namespace kernel {

KernelAbstract::KernelAbstract(memory::manager::MemoryKernelAllocManagerAbstract* kernel_alloc_manager) : kernel_alloc_manager_(kernel_alloc_manager) {

}

memory::manager::MemoryKernelAllocManagerAbstract* KernelAbstract::kernel_alloc_manager(){
	return this->kernel_alloc_manager_;
}

}  // namespace kernel
}  // namespace hunos
