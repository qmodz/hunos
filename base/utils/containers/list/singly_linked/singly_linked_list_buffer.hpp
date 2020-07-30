#ifndef _SINGLY_LINKED_LIST_BUFFER_HPP
#define _SINGLY_LINKED_LIST_BUFFER_HPP

#include "../list_buffer_abstract.hpp"
#include "singly_linked_list.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem>
class SinglyLinkedListBuffer : public ListBufferAbstract<TListElem, SinglyLinkedList<TListElem>> {
	public:
		using ListBufferAbstract<TListElem, SinglyLinkedList<TListElem>>::ListBufferAbstract;
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#endif
