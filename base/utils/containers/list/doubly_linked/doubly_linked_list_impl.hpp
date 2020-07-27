#include "doubly_linked_list.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem> 
DoublyLinkedList<TListElem>::DoublyLinkedList() : front_(nullptr), back_(nullptr), size_(0) {

}

template <typename TListElem> 
TListElem* DoublyLinkedList<TListElem>::front(){
	return this->front_;
}

template <typename TListElem> 
TListElem* DoublyLinkedList<TListElem>::back(){
	return this->back_;
}

template <typename TListElem> 
void DoublyLinkedList<TListElem>::popFront(){
	TListElem* front_elem = this->front_;

	if (front_elem != this->back_){
		TListElem* next_elem = front_elem->next;

		next_elem->prev = nullptr;
		this->front_ = next_elem;
	} else {
		this->front_ = nullptr;
		this->back_ = nullptr;
	}

	--this->size_;
}

template <typename TListElem> 
void DoublyLinkedList<TListElem>::popBack(){
	TListElem* back_elem = this->back_;
	
	if (back_elem != this->front_){
		TListElem* prev_elem = back_elem->prev;

		prev_elem->next = nullptr;
		this->back_ = prev_elem;
	} else {
		this->front_ = nullptr;
		this->back_ = nullptr;
	}

	--this->size_;
}

template <typename TListElem> 
void DoublyLinkedList<TListElem>::pushFront(TListElem* list_elem){
	TListElem* front_elem = this->front_;

	if (this->back_ == nullptr){
		this->back_ = list_elem;
	}

	list_elem->next = front_elem;
	list_elem->prev = nullptr;

	if (front_elem != nullptr){
		front_elem->prev = list_elem;
	}

	this->front_ = list_elem;
	++this->size_;
}

template <typename TListElem> 
void DoublyLinkedList<TListElem>::pushBack(TListElem* list_elem){
	TListElem* back_elem = this->back_;
	list_elem->next = nullptr;

	if (back_elem == nullptr){
		this->front_ = list_elem;
		list_elem->prev = nullptr;
	} else {
		back_elem->next = list_elem;
		list_elem->prev = back_elem;
	}

	this->back_ = list_elem;
	++this->size_;
}

template <typename TListElem> 
void DoublyLinkedList<TListElem>::removeElement(TListElem* list_elem){
	if (list_elem == this->front_){
		this->popFront();
	} else if (list_elem == this->back_){
		this->popBack();
	} else {
		TListElem* prev_elem = list_elem->prev;
		prev_elem->next = list_elem->next;
		--this->size_;
	}
}

template <typename TListElem> 
size_t DoublyLinkedList<TListElem>::size(){
	return this->size_;
}

template <typename TListElem> 
bool DoublyLinkedList<TListElem>::empty(){
	return this->size_ == 0;
}

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos
