#ifndef _LIST_BUFFER_ABSTRACT_HPP
#define _LIST_BUFFER_ABSTRACT_HPP

#include "list_buffer_interface.hpp"
#include "system/typedefs.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem, typename TListContainer>
class ListBufferAbstract : public ListBufferInterface<TListElem> {
	public:
		ListBufferAbstract(TListElem* memory_map, size_t memory_map_elem_count);
		virtual TListElem& front();
		virtual TListElem& back();
		virtual void popFront();
		virtual void popBack();
		virtual void pushFront(TListElem& list_elem);
		virtual void pushBack(TListElem& list_elem);
		virtual size_t size();
		virtual bool empty();
	
	protected:		
		void prepareFreeElemList();

		TListElem* memory_map_;
		size_t memory_map_elem_count_;

		TListContainer reserved_elem_list_;
		TListContainer free_elem_list_;
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#include "list_buffer_abstract_impl.hpp"

#endif
