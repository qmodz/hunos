#ifndef _MEMORY_ALLOC_MANAGER_ABSTRACT_HPP
#define _MEMORY_ALLOC_MANAGER_ABSTRACT_HPP

#define MEM_ALLOC_SPECIFIC_FREE_BLOCK_CACHE_SIZE 32

#include "system/typedefs.hpp"
#include "utils/containers/list/list.hpp"

#include "memory_alloc_block_info.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

class MemoryAllocManagerAbstract {
	public:
		MemoryAllocManagerAbstract(uintptr_t alloc_start_address);
		void* malloc(size_t size);
		void* calloc(size_t size);
		void* realloc(void* ptr, size_t size);
		void free(void* ptr);
		virtual void* sbrk(intptr_t increment) = 0;

	protected:
		size_t getAlignedBlockSize(size_t size);
		uint8_t getFitBlockSizeMultiplier(size_t size);

		void* getMemoryBlockDataPtr(MemoryAllocBlockInfo* memory_block);
		MemoryAllocBlockInfo* getDataPtrMemoryBlock(void* ptr);
		MemoryAllocBlockInfo* getLastPhysicalBlock();	

		MemoryAllocBlockInfo* getFitFreeBlock(size_t block_size);
		MemoryAllocBlockInfo* getFitFreeBlockFromCache(size_t block_size);
		MemoryAllocBlockInfo* getFreeBlockFromCache(uint8_t block_size_multiplier);

		void freeBlock(MemoryAllocBlockInfo* memory_block);
		void addFreeBlock(MemoryAllocBlockInfo* memory_block);
		void addFreeBlockToCache(MemoryAllocBlockInfo* memory_block);
		void removeFreeBlockFromCache(MemoryAllocBlockInfo* memory_block);
		
		MemoryAllocBlockInfo* allocateLastPhysicalBlock(size_t block_size);
		void deallocateLastPhysicalBlock();
		
		MemoryAllocBlockInfo* mergeBlocks(MemoryAllocBlockInfo* block1, MemoryAllocBlockInfo* block2);
		MemoryAllocBlockInfo* checkAndMergeWithFreeBlock(MemoryAllocBlockInfo* merge_block, MemoryAllocBlockInfo* free_block);
		MemoryAllocBlockInfo* mergeWithNeighboursFreeBlocks(MemoryAllocBlockInfo* free_block);

		MemoryAllocBlockInfo* splitBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size);
				
		MemoryAllocBlockInfo* resizeBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size);
		MemoryAllocBlockInfo* shrinkBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size);
		MemoryAllocBlockInfo* extendBlock(MemoryAllocBlockInfo* memory_block, size_t required_block_size);
		MemoryAllocBlockInfo* extendLastPhysicalBlock(size_t required_block_size);
		MemoryAllocBlockInfo* extendBlockWithNextFreeCheck(MemoryAllocBlockInfo* memory_block, size_t required_block_size);
		MemoryAllocBlockInfo* extendBlockWithReallocation(MemoryAllocBlockInfo* memory_block, size_t required_block_size);

		uintptr_t alloc_start_address_;
		uintptr_t alloc_end_address_;
		size_t last_block_size_;

		size_t min_block_size_;
		uintptr_t min_block_size_mask_;
		
		utils::SinglyLinkedList<MemoryAllocBlockInfo> free_blocks_cache_[MEM_ALLOC_SPECIFIC_FREE_BLOCK_CACHE_SIZE];
		uint32_t free_blocks_presence_mask_;
};

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos

#endif
