#ifndef _LIST_INTERFACE_HPP
#define _LIST_INTERFACE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem>
class ListInterface {
	public:
		virtual TListElem* front() = 0;
		virtual TListElem* back() = 0;
		virtual void popFront() = 0;
		virtual void popBack() = 0;
		virtual void pushFront(TListElem* list_elem) = 0;
		virtual void pushBack(TListElem* list_elem) = 0;
		virtual void removeElement(TListElem* list_elem) = 0;
		virtual size_t size() = 0;
		virtual bool empty() = 0;
};

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#endif
