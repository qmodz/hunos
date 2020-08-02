#ifndef _MEMORY_PAGE_MANAGER_HPP
#define _MEMORY_PAGE_MANAGER_HPP

#include "system/typedefs.hpp"
#include "utils/containers/stack/stack.hpp"

#include "memory_page_info.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

class MemoryPageManager {
	public:
		MemoryPageManager(utils::Stack<MemoryPageInfo>* free_pages_stack);
		virtual uintptr_t getFreePage();
		virtual void addFreePage(uintptr_t address);

	protected:
		utils::Stack<MemoryPageInfo>* free_pages_;
};

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos

#endif
