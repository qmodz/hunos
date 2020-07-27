#ifndef _STACK_HPP
#define _STACK_HPP

#include "stack_interface.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace stack {

template <typename TStackElem>
class Stack : public StackInterface<TStackElem> {
	public:
		Stack(TStackElem* memory_map, size_t memory_map_elem_count);
		virtual TStackElem& top();
		virtual void push(TStackElem& stack_elem);
		virtual void pop();
		virtual size_t size();
		virtual bool empty();

	protected:
		TStackElem* stack_start_;
		TStackElem* stack_end_;
		size_t stack_current_elem_count_;
		size_t stack_max_elem_count_;
};

}  // namespace stack
}  // namespace containers
}  // namespace utils
}  // namespace hunos

#include "stack_impl.hpp"

#endif
