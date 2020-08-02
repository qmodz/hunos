#include "memory_alloc_manager_abstract.hpp"

#include "utils/memory/operations/operations.hpp"
#include "utils/register/operations/operations.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

MemoryAllocManagerAbstract::MemoryAllocManagerAbstract(uintptr_t alloc_start_address) : 
	alloc_start_address_(alloc_start_address), alloc_end_address_(alloc_start_address), 
	last_block_size_(0), free_blocks_presence_mask_(0) {
		 
	uint8_t min_block_size_multiplier = this->getFitBlockSizeMultiplier(sizeof(MemoryAllocBlockInfo));
	this->min_block_size_ = (size_t) (1 << min_block_size_multiplier);

	this->min_block_size_mask_ = utils::reg::generateLeadingMask<uint32_t>(min_block_size_multiplier);
}

void* MemoryAllocManagerAbstract::malloc(size_t size) {
	size_t block_size = this->getAlignedBlockSize(size);
	MemoryAllocBlockInfo* memory_block = this->getFitFreeBlock(block_size);

	if (memory_block != nullptr){
		memory_block->setReserved();
		return this->getMemoryBlockDataPtr(memory_block);
	} else {
		return nullptr;
	}
}

void* MemoryAllocManagerAbstract::calloc(size_t size) {
	void* ptr = this->malloc(size);

	if (ptr != nullptr){
		utils::memory::memset(ptr, 0, size);
	}
	
	return ptr;
}

void* MemoryAllocManagerAbstract::realloc(void* ptr, size_t size) {
	MemoryAllocBlockInfo* block = this->getDataPtrMemoryBlock(ptr);
	
	if (ptr == nullptr && size == 0) {
		return nullptr;
	} else if (size == 0) {
		this->freeBlock(block);
		return nullptr;
	} else if (ptr == nullptr) {
		return this->malloc(size);
	} else {		
		size_t new_block_size = this->getAlignedBlockSize(size);
		block = this->resizeBlock(block, new_block_size);
		return block != nullptr ? this->getMemoryBlockDataPtr(block) : nullptr;
	}
}

void MemoryAllocManagerAbstract::free(void* ptr){
	MemoryAllocBlockInfo* block = this->getDataPtrMemoryBlock(ptr);

	this->freeBlock(block);
}

size_t MemoryAllocManagerAbstract::getAlignedBlockSize(size_t size){
	size_t block_size = size + sizeof(MemoryAllocBlockInfo);
	size_t aligned_block_size = block_size & this->min_block_size_mask_;

	if ((block_size & ~this->min_block_size_mask_) != 0){
		aligned_block_size += this->min_block_size_;
	}

	return aligned_block_size;
}

void* MemoryAllocManagerAbstract::getMemoryBlockDataPtr(MemoryAllocBlockInfo* memory_block){
	uintptr_t block_address = (uintptr_t) memory_block;
	uintptr_t data_address = block_address + sizeof(MemoryAllocBlockInfo);

	return (void *) data_address;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::getDataPtrMemoryBlock(void* ptr){
	uintptr_t data_address = (uintptr_t) ptr;
	uintptr_t block_address = data_address - sizeof(MemoryAllocBlockInfo);
	
	return (MemoryAllocBlockInfo *) block_address;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::getLastPhysicalBlock(){
	if (this->alloc_start_address_ != this->alloc_end_address_){
		uintptr_t last_block_address = this->alloc_end_address_ - this->last_block_size_;
		MemoryAllocBlockInfo* last_block = (MemoryAllocBlockInfo *) last_block_address;

		return last_block;
	} else {
		return nullptr;
	}
}

uint8_t MemoryAllocManagerAbstract::getFitBlockSizeMultiplier(size_t size){
	uint8_t fit_block_size_multiplier = utils::reg::mostSignificantSetBit<uint32_t>(size);
	uint32_t fit_block_size = (uint32_t) (1 << fit_block_size_multiplier);

	if (fit_block_size < size){
		++fit_block_size_multiplier;
	}

	return fit_block_size_multiplier;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::getFreeBlockFromCache(uint8_t block_size_multiplier){
	MemoryAllocBlockInfo* memory_free_block = this->free_blocks_cache_[block_size_multiplier].front();
	this->free_blocks_cache_[block_size_multiplier].popFront();

	if (this->free_blocks_cache_[block_size_multiplier].empty()){
		this->free_blocks_presence_mask_ = utils::reg::clearBit<uint32_t>(this->free_blocks_presence_mask_, block_size_multiplier);
	}

	return memory_free_block;
}

void MemoryAllocManagerAbstract::addFreeBlockToCache(MemoryAllocBlockInfo* memory_block){
	uint8_t free_block_size_multiplier = utils::reg::mostSignificantSetBit<uint32_t>(memory_block->block_size);

	this->free_blocks_cache_[free_block_size_multiplier].pushBack(memory_block);
	this->free_blocks_presence_mask_ = utils::reg::setBit<uint32_t>(this->free_blocks_presence_mask_, free_block_size_multiplier);
}

void MemoryAllocManagerAbstract::removeFreeBlockFromCache(MemoryAllocBlockInfo* memory_block){
	uint8_t free_block_size_multiplier = utils::reg::mostSignificantSetBit<uint32_t>(memory_block->block_size);

	this->free_blocks_cache_[free_block_size_multiplier].removeElement(memory_block);

	if (this->free_blocks_cache_[free_block_size_multiplier].empty()){
		this->free_blocks_presence_mask_ = utils::reg::clearBit<uint32_t>(this->free_blocks_presence_mask_, free_block_size_multiplier);
	}
}

void MemoryAllocManagerAbstract::addFreeBlock(MemoryAllocBlockInfo* memory_block){
	uintptr_t block_address = (uintptr_t) memory_block;
	uintptr_t block_end_address = block_address + memory_block->block_size; 

	if (block_end_address >= this->alloc_end_address_){
		this->deallocateLastPhysicalBlock();
	} else {
		this->addFreeBlockToCache(memory_block);
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::getFitFreeBlockFromCache(size_t block_size){
	uint8_t fit_block_multiplier = this->getFitBlockSizeMultiplier(block_size);
	uint32_t blocks_mask = utils::reg::generateLeadingMask<uint32_t>(fit_block_multiplier);
	uint32_t available_blocks_mask = this->free_blocks_presence_mask_ & blocks_mask;

	if (available_blocks_mask != 0){	
		uint8_t found_block_multiplier = utils::reg::leastSignificantSetBit<uint32_t>(available_blocks_mask);
		MemoryAllocBlockInfo* free_block = this->getFreeBlockFromCache(found_block_multiplier);
		MemoryAllocBlockInfo* fit_free_block = this->shrinkBlock(free_block, block_size);

		return fit_free_block;
	} else {
		return nullptr;
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::allocateLastPhysicalBlock(size_t block_size){
	MemoryAllocBlockInfo* block = (MemoryAllocBlockInfo *) sbrk(block_size);

	if (block != nullptr){
		block->prev_physical_block_size = this->last_block_size_;
		block->block_size = block_size;

		this->alloc_end_address_ += block_size;
		this->last_block_size_ = block_size;
	}

	return block;
}

void MemoryAllocManagerAbstract::deallocateLastPhysicalBlock(){
	MemoryAllocBlockInfo* last_block = this->getLastPhysicalBlock();

	this->alloc_end_address_ -= last_block->block_size;
	this->last_block_size_ = last_block->prev_physical_block_size;

	this->sbrk(-last_block->block_size);
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::mergeBlocks(MemoryAllocBlockInfo* block1, MemoryAllocBlockInfo* block2){
	uintptr_t block1_address = (uintptr_t) block1;
	uintptr_t block2_address = (uintptr_t) block2;
	size_t merged_block_size = block1->block_size + block2->block_size;

	MemoryAllocBlockInfo* merged_block = block1_address < block2_address ? block1 : block2;
	uintptr_t merged_block_address = (uintptr_t) merged_block;
	uintptr_t next_block_address = merged_block_address + merged_block_size;
	
	merged_block->block_size = merged_block_size;

	if (next_block_address < this->alloc_end_address_){
		MemoryAllocBlockInfo* next_block = (MemoryAllocBlockInfo *) next_block_address;
		next_block->prev_physical_block_size = merged_block_size;
	}

	return merged_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::checkAndMergeWithFreeBlock(MemoryAllocBlockInfo* merge_block, MemoryAllocBlockInfo* free_block){
	MemoryAllocBlockInfo* merged_block = merge_block;
	
	if (free_block->isFree()){
		this->removeFreeBlockFromCache(free_block);
		merged_block = this->mergeBlocks(merge_block, free_block);
	}
	
	return merged_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::mergeWithNeighboursFreeBlocks(MemoryAllocBlockInfo* free_block){
	uintptr_t block_address = (uintptr_t) free_block;
	uintptr_t prev_block_address = block_address - free_block->prev_physical_block_size;
	uintptr_t next_block_address = block_address + free_block->block_size;

	MemoryAllocBlockInfo* merged_free_block = free_block;
	MemoryAllocBlockInfo* prev_block = (MemoryAllocBlockInfo *) prev_block_address;
	MemoryAllocBlockInfo* next_block = (MemoryAllocBlockInfo *) next_block_address;
	
	if (next_block_address < this->alloc_end_address_){
		merged_free_block = this->checkAndMergeWithFreeBlock(merged_free_block, next_block);
	}

	if (prev_block_address != block_address){
		merged_free_block = this->checkAndMergeWithFreeBlock(merged_free_block, prev_block);
	}

	return merged_free_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::getFitFreeBlock(size_t block_size){
	MemoryAllocBlockInfo* fit_free_block = this->getFitFreeBlockFromCache(block_size);

	if (fit_free_block != nullptr){
		fit_free_block = this->allocateLastPhysicalBlock(block_size);
	}

	return fit_free_block;
}

void MemoryAllocManagerAbstract::freeBlock(MemoryAllocBlockInfo* memory_block){
	uintptr_t block_address = (uintptr_t) memory_block;

	 if (block_address >= this->alloc_start_address_ && block_address < this->alloc_end_address_){
		memory_block->setFree();

		memory_block = this->mergeWithNeighboursFreeBlocks(memory_block);
		this->addFreeBlock(memory_block);
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::resizeBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	if (required_block_size == memory_block->block_size) {
		return memory_block;
	} else if (required_block_size < memory_block->block_size) {
		return this->shrinkBlock(memory_block, required_block_size);
	} else {
		return this->extendBlock(memory_block, required_block_size);
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::shrinkBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	if (memory_block->block_size != required_block_size){
		MemoryAllocBlockInfo* free_block = this->splitBlock(memory_block, required_block_size);
		free_block->setFree();
		this->addFreeBlock(free_block);
	}

	return memory_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::extendBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	uintptr_t block_address = (uintptr_t) memory_block;
	uintptr_t next_block_address = block_address + memory_block->block_size;

	if (next_block_address < this->alloc_end_address_){
		return this->extendBlockWithNextFreeCheck(memory_block, required_block_size);
	} else {
		return this->extendLastPhysicalBlock(required_block_size);
	}

	return memory_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::extendBlockWithNextFreeCheck(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	uintptr_t block_address = (uintptr_t) memory_block;
	uintptr_t next_block_address = block_address + memory_block->block_size;
	MemoryAllocBlockInfo* next_block = (MemoryAllocBlockInfo *) next_block_address;

	size_t needed_size = required_block_size - memory_block->block_size;

	if (next_block->isFree() && needed_size <= next_block->block_size){
		memory_block = this->checkAndMergeWithFreeBlock(memory_block, next_block);
		memory_block = this->shrinkBlock(memory_block, required_block_size);

		return memory_block;
	} else {
		return this->extendBlockWithReallocation(memory_block, required_block_size);
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::extendBlockWithReallocation(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	MemoryAllocBlockInfo* new_memory_block = this->getFitFreeBlock(required_block_size);

	if (new_memory_block != nullptr){
		void* old_data_ptr = this->getMemoryBlockDataPtr(memory_block);
		void* new_data_ptr = this->getMemoryBlockDataPtr(new_memory_block);
		size_t old_data_size = memory_block->block_size - sizeof(MemoryAllocBlockInfo);
	
		new_memory_block->setReserved();

		utils::memory::memcpy(new_data_ptr, old_data_ptr, old_data_size);

		this->freeBlock(memory_block);
	}

	return new_memory_block;
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::extendLastPhysicalBlock(size_t required_block_size) {
	MemoryAllocBlockInfo* last_block = this->getLastPhysicalBlock();

	size_t needed_size = required_block_size - last_block->block_size;

	if (this->sbrk(needed_size) != nullptr){
		last_block->block_size = required_block_size;

		this->alloc_end_address_ += needed_size;
		this->last_block_size_ = required_block_size;

		return last_block;
	} else {
		return nullptr;
	}
}

MemoryAllocBlockInfo* MemoryAllocManagerAbstract::splitBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size) {
	size_t new_block_size = memory_block->block_size - required_block_size;

	uintptr_t block_address = (uintptr_t) memory_block;
	uintptr_t next_block_address = block_address + memory_block->block_size;
	uintptr_t new_block_address = block_address + required_block_size;
	MemoryAllocBlockInfo* next_block = (MemoryAllocBlockInfo *) next_block_address;
	MemoryAllocBlockInfo* new_block = (MemoryAllocBlockInfo *) new_block_address;

	memory_block->block_size = required_block_size;
	new_block->block_size = new_block_size;
	new_block->prev_physical_block_size = required_block_size;

	if (next_block_address < this->alloc_end_address_){
		next_block->prev_physical_block_size = new_block_size;
	}

	return new_block;
}

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos
