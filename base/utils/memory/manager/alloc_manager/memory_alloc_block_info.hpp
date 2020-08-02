#ifndef _MEMORY_ALLOC_BLOCK_INFO_HPP
#define _MEMORY_ALLOC_BLOCK_INFO_HPP

#include "system/typedefs.hpp"

#include "utils/containers/list/list.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

enum MemoryAllocBlockStatus {
	kFree = 0,
	kReserved = 1
};

struct MemoryAllocBlockInfo : public utils::DoublyLinkedListElem {
	bool isFree();
	bool isReserved();
	void setFree();
	void setReserved();

	size_t block_size;
	size_t prev_physical_block_size;
	MemoryAllocBlockStatus status;
	
	MemoryAllocBlockInfo* next;
	MemoryAllocBlockInfo* prev;
};

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos

#endif
