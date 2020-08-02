#include "memory_alloc_block_info.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

bool MemoryAllocBlockInfo::isFree(){
	return this->status == MemoryAllocBlockStatus::kFree;
}

bool MemoryAllocBlockInfo::isReserved(){
	return this->status == MemoryAllocBlockStatus::kReserved;
}

void MemoryAllocBlockInfo::setFree(){
	this->status = MemoryAllocBlockStatus::kFree;
}

void MemoryAllocBlockInfo::setReserved(){
	this->status = MemoryAllocBlockStatus::kReserved;
}

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos
