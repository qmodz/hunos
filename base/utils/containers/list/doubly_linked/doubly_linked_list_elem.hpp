#ifndef _DOUBLY_LINKED_LIST_ELEM_HPP
#define _DOUBLY_LINKED_LIST_ELEM_HPP

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

struct DoublyLinkedListElem {
	DoublyLinkedListElem* next;
	DoublyLinkedListElem* prev;	
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#endif
