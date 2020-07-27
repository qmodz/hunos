#include "singly_linked_list.hpp"

namespace hunos {
namespace utils {
inline namespace containers {
inline namespace list {

template <typename TListElem> 
SinglyLinkedList<TListElem>::SinglyLinkedList() : front_(nullptr), back_(nullptr), size_(0) {
	
}

template <typename TListElem> 
TListElem* SinglyLinkedList<TListElem>::front(){
	return this->front_;
}

template <typename TListElem> 
TListElem* SinglyLinkedList<TListElem>::back(){
	return this->back_;
}

template <typename TListElem> 
void SinglyLinkedList<TListElem>::popFront(){
	TListElem* front = this->front_;
	
	this->front_ = front->next;

	if (front == this->back_){
		this->back_ = nullptr;
	}
		
	--this->size_;
}

template <typename TListElem> 
TListElem* SinglyLinkedList<TListElem>::findPrevElement(TListElem* list_elem){
	TListElem* current_elem = this->front_;
	TListElem* prev_elem = nullptr;

	while(current_elem != list_elem){
		prev_elem = current_elem;
		current_elem = current_elem->next;
	}

	return prev_elem;
}

template <typename TListElem> 
void SinglyLinkedList<TListElem>::popBack(){
	TListElem* back_elem = this->back_;
	TListElem* prev_elem = this->findPrevElement(back_elem);

	if (prev_elem != nullptr){
		prev_elem->next = nullptr;
		this->back_ = prev_elem;
	} else {
		this->front_ = nullptr;
		this->back_ = nullptr;
	}
	
	--this->size_;
}

template <typename TListElem> 
void SinglyLinkedList<TListElem>::pushFront(TListElem* list_elem){
	TListElem* front = this->front_;

	if (this->back_ == nullptr){
		this->back_ = list_elem;
	}

	list_elem->next = front;
	this->front_ = list_elem;
	++this->size_;
}

template <typename TListElem> 
void SinglyLinkedList<TListElem>::pushBack(TListElem* list_elem){
	TListElem* back = this->back_;
	list_elem->next = nullptr;

	if (back == nullptr){
		this->front_ = list_elem;
	} else {
		back->next = list_elem;
	}

	this->back_ = list_elem;
	++this->size_;
}

template <typename TListElem> 
void SinglyLinkedList<TListElem>::removeElement(TListElem* list_elem){
	if (list_elem == this->front_){
		this->popFront();
	} else if (list_elem == this->back_){
		this->popBack();
	} else {
		TListElem* prev_elem = this->findPrevElement(list_elem);
		prev_elem->next = list_elem->next;
		--this->size_;
	}
}

template <typename TListElem> 
size_t SinglyLinkedList<TListElem>::size(){
	return this->size_;
}

template <typename TListElem> 
bool SinglyLinkedList<TListElem>::empty(){
	return this->size_ == 0;
}

}  // namespace list
}  // namespace containers
}  // namespace utils
}  // namespace hunos
