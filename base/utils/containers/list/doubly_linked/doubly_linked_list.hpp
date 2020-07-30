#ifndef _DOUBLY_LINKED_LIST_HPP
#define _DOUBLY_LINKED_LIST_HPP

#include "../list_interface.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem>
class DoublyLinkedList : public ListInterface<TListElem> {
	public:
		DoublyLinkedList<TListElem>();
		virtual TListElem* front();
		virtual TListElem* back();
		virtual void popFront();
		virtual void popBack();
		virtual void pushFront(TListElem* list_elem);
		virtual void pushBack(TListElem* list_elem);
		virtual void removeElement(TListElem* list_elem);
		virtual size_t size();
		virtual bool empty();
	
	protected:
		TListElem* findPrevElement(TListElem* list_elem);

		TListElem* front_;
		TListElem* back_;
		size_t size_;
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#include "doubly_linked_list_impl.hpp"

#endif
