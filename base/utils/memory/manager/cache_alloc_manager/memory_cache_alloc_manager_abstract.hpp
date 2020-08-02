#ifndef _MEMORY_ALLOC_CACHE_MANAGER_ABSTRACT_HPP
#define _MEMORY_ALLOC_CACHE_MANAGER_ABSTRACT_HPP

#include "system/typedefs.hpp"

#include "../alloc_manager/memory_alloc_manager_abstract.hpp"

namespace hunos {
namespace utils {
inline namespace memory {
inline namespace manager {

class MemoryCacheAllocManagerAbstract : public MemoryAllocManagerAbstract {
	public:
		MemoryCacheAllocManagerAbstract(uintptr_t alloc_start_address);
		void* sbrk(intptr_t increment);
		virtual void* allocate(size_t increment) = 0;
		virtual void* deallocate(size_t decrement) = 0;

	protected:
		void* sbrk_allocate(size_t increment);
		void* sbrk_deallocate(size_t decrement);

		size_t real_alloc_size_;
		size_t current_alloc_size_;
};

}  // namespace manager
}  // namespace memory
}  // namespace utils
}  // namespace hunos

#endif
