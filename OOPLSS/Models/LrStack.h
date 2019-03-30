// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include "stdexcept"

namespace OOPLSS {
	namespace Models {
		template <class T> class LrStack {
		private:
			class Item {
			public:
				Item(T& val) {
					value = val;
					prev = nullptr;
				}

				T value;
				Item* prev;

				~Item() {
					if (this->prev != nullptr) {
						delete this->prev;
					}
				}
			};

			Item* _head;

		public:
			class StackIterator {
			private:
				Item * _head;

			public:
				StackIterator(Item* head) {
					this->_head = head;
				}

				bool hasValue() {
					return _head != nullptr;
				}

				void move() {
					this->_head = this->_head->prev;
				}

				T* getValue() {
					if (!this->hasValue()) {
						throw std::out_of_range("Can't find iterable items.");
					}

					return &(this->_head->value);
				}
			};

			LrStack() {
				this->_head = nullptr;
			}

			void push(T val) {
				Item* buffer = this->_head;

				this->_head = new Item(val);
				this->_head->prev = buffer;
			}

			T pop() {
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

			bool isEmpty() {
				return this->_head == nullptr;
			}

			bool contains(const T& val) {
				Item* buffer = this->_head;

				while (buffer != nullptr) {
					if (buffer->value == val) {
						return true;
					}

					buffer = buffer->prev;
				}

				return false;
			}

			StackIterator* getIterator() {
				return new StackIterator(this->_head);
			}

			~LrStack() {
				delete this->_head;
			}
		};
	}
}