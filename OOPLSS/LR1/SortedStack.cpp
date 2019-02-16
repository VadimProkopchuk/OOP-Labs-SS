// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include "stdexcept"
#include "SortedStack.h"

template<class T>
inline bool OOPLSS::LR1::SortedStack<T>::pushRecursive(T val, Item*& head) {
	if (head != nullptr && head->value > val) {
		if (head->prev != nullptr) {
			this->pushRecursiveWithCheckHead(val, head->prev);
		}
		else {
			head->prev = new Item(val);
		}
	}
	else {
		return false;
	}

	return true;
}

template<class T>
inline void OOPLSS::LR1::SortedStack<T>::pushRecursiveWithCheckHead(T val, Item*& head) {
	if (!this->pushRecursive(val, head)) {
		this->pushHead(val, head);
	}
}

template<class T>
inline void OOPLSS::LR1::SortedStack<T>::pushHead(T val, Item*& head) {
	Item* current = new Item(val);

	current->prev = head;
	head = current;
}

template<class T>
inline void OOPLSS::LR1::SortedStack<T>::push(T val) {
	if (this->isEmpty()) {
		_head = new Item(val);
	}
	else {
		this->pushRecursiveWithCheckHead(val, this->_head);
	}
}

template<class T>
inline T OOPLSS::LR1::SortedStack<T>::pop() {
	if (isEmpty()) {
		throw std::out_of_range("Stack is empty.");
	}

	Item* buffer = this->_head;
	T value = buffer->value;

	if (buffer->prev != nullptr) {
		this->_head = buffer->prev;
		buffer->prev = nullptr;
		delete buffer;
	}
	else {
		delete buffer;
		this->_head = nullptr;
	}

	return value;
}

template<class T>
inline bool OOPLSS::LR1::SortedStack<T>::contains(T val) {
	Item* head = this->_head;

	while (head != nullptr) {
		if (head->value == val) {
			return true;
		}

		head = head->prev;
	}

	return false;
}

template<class T>
inline bool OOPLSS::LR1::SortedStack<T>::isEmpty() {
	return this->_head == nullptr;
}