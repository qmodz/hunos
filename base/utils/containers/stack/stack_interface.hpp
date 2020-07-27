#ifndef _STACK_INTERFACE_HPP
#define _STACK_INTERFACE_HPP

#include "system/typedefs.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace stack {

template <typename TStackElem>
class StackInterface {
	public:
		virtual TStackElem& top() = 0;
		virtual void push(TStackElem& stack_elem) = 0;
		virtual void pop() = 0;
		virtual size_t size() = 0;
		virtual bool empty() = 0;
};

}  // namespace stack
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#endif
