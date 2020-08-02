#include "memory_page_manager.hpp"

namespace hunos {
namespace kernel {
namespace memory {
inline namespace manager {

MemoryPageManager::MemoryPageManager(utils::Stack<MemoryPageInfo>* free_pages_stack) : free_pages_(free_pages_stack) {
	
}

uintptr_t MemoryPageManager::getFreePage(){
	uintptr_t page_address = (uintptr_t) nullptr;

	if (!this->free_pages_->empty()){
		MemoryPageInfo page_info = this->free_pages_->top();
		page_address = page_info.address;

		this->free_pages_->pop();
	}
	
	return page_address;
}

void MemoryPageManager::addFreePage(uintptr_t page_address){
	MemoryPageInfo memory_page_info(page_address);

	this->free_pages_->push(memory_page_info);
}

}  // namespace manager
}  // namespace memory
}  // namespace kernel
}  // namespace hunos
