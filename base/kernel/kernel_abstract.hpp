#ifndef _KERNEL_ABSTRACT_HPP
#define _KERNEL_ABSTRACT_HPP

#include "memory/manager/kernel_alloc_manager/memory_kernel_alloc_manager_abstract.hpp"

namespace hunos {
namespace kernel {

class KernelAbstract {
	public:
		KernelAbstract(memory::manager::MemoryKernelAllocManagerAbstract* kernel_alloc_manager);

		memory::manager::MemoryKernelAllocManagerAbstract* kernel_alloc_manager();

	protected:
		memory::manager::MemoryKernelAllocManagerAbstract* kernel_alloc_manager_;
};

}  // namespace kernel
}  // namespace hunos

#endif
