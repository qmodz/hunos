#ifndef _SINGLY_LINKED_LIST_HPP
#define _SINGLY_LINKED_LIST_HPP

#include "../list_interface.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem>
class SinglyLinkedList : public ListInterface<TListElem> {
	public:
		SinglyLinkedList<TListElem>();
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

#include "singly_linked_list_impl.hpp"

#endif
