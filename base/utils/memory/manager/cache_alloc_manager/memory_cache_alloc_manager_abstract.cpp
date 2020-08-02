#include "memory_cache_alloc_manager_abstract.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

MemoryCacheAllocManagerAbstract::MemoryCacheAllocManagerAbstract(uintptr_t alloc_start_address) : MemoryAllocManagerAbstract(alloc_start_address), 
													real_alloc_size_(0), current_alloc_size_(0) {

}

void* MemoryCacheAllocManagerAbstract::sbrk(intptr_t increment){
	if (increment >= 0){
		return sbrk_allocate((size_t) increment);
	} else {
		return sbrk_deallocate((size_t) -increment);
	}
}

void* MemoryCacheAllocManagerAbstract::sbrk_allocate(size_t increment){
	size_t new_current_alloc_size = this->current_alloc_size_ + increment;

	if (new_current_alloc_size > this->real_alloc_size_){
		size_t new_real_alloc_size = new_current_alloc_size << 1;
		size_t needed_size = new_real_alloc_size - this->real_alloc_size_;
		void* ptr = this->allocate(needed_size);

		this->real_alloc_size_ = ptr != nullptr ? new_real_alloc_size : this->real_alloc_size_;
		this->current_alloc_size_ = ptr != nullptr ? new_current_alloc_size : this->current_alloc_size_;

		return ptr;
	} else {
		this->current_alloc_size_ = new_current_alloc_size;
		return (void *) (this->alloc_start_address_ + this->current_alloc_size_);
	}
}

void* MemoryCacheAllocManagerAbstract::sbrk_deallocate(size_t decrement){
	size_t new_current_alloc_size = this->current_alloc_size_ > decrement ? this->current_alloc_size_ - decrement : 0;
	size_t new_real_alloc_size = this->real_alloc_size_ >> 1;
	size_t new_real_alloc_size_treshold = this->real_alloc_size_ >> 2;

	if (new_current_alloc_size <= new_real_alloc_size_treshold){
		size_t real_decrement = this->real_alloc_size_ - new_real_alloc_size;
		void* ptr = this->deallocate(real_decrement);

		this->real_alloc_size_ = ptr != nullptr ? new_real_alloc_size : this->real_alloc_size_;
		this->current_alloc_size_ = ptr != nullptr ? new_current_alloc_size : this->current_alloc_size_;

		return ptr;
	} else {
		this->current_alloc_size_ = new_current_alloc_size;
		return (void *) (this->alloc_start_address_ + this->current_alloc_size_);
	}
}

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos
