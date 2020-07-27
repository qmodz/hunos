#ifndef _DOUBLY_LINKED_LIST_BUFFER_HPP
#define _DOUBLY_LINKED_LIST_BUFFER_HPP

#include "../list_buffer_abstract.hpp"
#include "doubly_linked_list.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem>
class DoublyLinkedListBuffer : public ListBufferAbstract<TListElem, DoublyLinkedList<TListElem>> {
	public:
		using ListBufferAbstract<TListElem, DoublyLinkedList<TListElem>>::ListBufferAbstract;
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#endif
