#include "stack.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace stack {

template <typename TStackElem>
Stack<TStackElem>::Stack(TStackElem* memory_map, size_t memory_map_elem_count) : stack_start_(memory_map), stack_end_(memory_map), 
					stack_current_elem_count_(0), stack_max_elem_count_(memory_map_elem_count) {
	
}

template <typename TStackElem>
TStackElem& Stack<TStackElem>::top(){
	TStackElem* stack_top = this->stack_end_ - 1;

	return *stack_top;
}

template <typename TStackElem>
void Stack<TStackElem>::push(TStackElem& stack_elem){
	if (this->stack_current_elem_count_ != this->stack_max_elem_count_){
		*this->stack_end_ = stack_elem;

		++this->stack_current_elem_count_;
		++this->stack_end_;
	}
}

template <typename TStackElem>
void Stack<TStackElem>::pop(){
	if (this->stack_current_elem_count_ != 0){		
		--this->stack_current_elem_count_;
		--this->stack_end_;
	}
}

template <typename TStackElem>
size_t Stack<TStackElem>::size(){
	return this->stack_current_elem_count_;
}

template <typename TStackElem>
bool Stack<TStackElem>::empty(){
	return this->stack_current_elem_count_ == 0;
}

}  // namespace stack
}  // namespace containers
}  // namespace utils
}  // namespace hunos
