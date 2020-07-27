#include "list_buffer_abstract.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem, typename TListContainer>
ListBufferAbstract<TListElem, TListContainer>::ListBufferAbstract(TListElem* memory_map, size_t memory_map_elem_count) : memory_map_(memory_map), 
									memory_map_elem_count_(memory_map_elem_count) {
	this->prepareFreeElemList();
}

template <typename TListElem, typename TListContainer>
void ListBufferAbstract<TListElem, TListContainer>::prepareFreeElemList(){
	TListElem* elem = this->memory_map_;

	for (size_t i = 0; i < this->memory_map_elem_count_; ++i){
		this->free_elem_list_.pushBack(elem++);
	}
}

template <typename TListElem, typename TListContainer>
TListElem& ListBufferAbstract<TListElem, TListContainer>::front(){
	return *this->reserved_elem_list_.front();
}

template <typename TListElem, typename TListContainer>
TListElem& ListBufferAbstract<TListElem, TListContainer>::back(){
	return *this->reserved_elem_list_.back();
}

template <typename TListElem, typename TListContainer>
void ListBufferAbstract<TListElem, TListContainer>::popFront(){
	TListElem* front = this->reserved_elem_list_.front();

	if (front != nullptr){
		this->reserved_elem_list_.popFront();
		this->free_elem_list_.pushBack(front);
	}
}

template <typename TListElem, typename TListContainer>
void ListBufferAbstract<TListElem, TListContainer>::popBack(){
	TListElem* back = this->reserved_elem_list_.back();

	if (back != nullptr){
		this->reserved_elem_list_.popBack();
		this->free_elem_list_.pushBack(back);
	}
}

template <typename TListElem, typename TListContainer>
void ListBufferAbstract<TListElem, TListContainer>::pushFront(TListElem& list_elem){
	TListElem* free_elem = this->free_elem_list_.front();

	if (free_elem != nullptr){
		this->free_elem_list_.popFront();

		*free_elem = list_elem;
		this->reserved_elem_list_.pushFront(free_elem);
	}
}

template <typename TListElem, typename TListContainer>
void ListBufferAbstract<TListElem, TListContainer>::pushBack(TListElem& list_elem){
	TListElem* free_elem = this->free_elem_list_.front();

	if (free_elem != nullptr){
		this->free_elem_list_.popFront();

		*free_elem = list_elem;
		this->reserved_elem_list_.pushBack(free_elem);
	}
}

template <typename TListElem, typename TListContainer>
size_t ListBufferAbstract<TListElem, TListContainer>::size(){
	return this->reserved_elem_list_.size();
}

template <typename TListElem, typename TListContainer>
bool ListBufferAbstract<TListElem, TListContainer>::empty(){
	return this->reserved_elem_list_.empty();
}

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos
