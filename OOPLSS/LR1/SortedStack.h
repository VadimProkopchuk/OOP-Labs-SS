// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

namespace OOPLSS {
	namespace LR1 {
		template <class T> class SortedStack {
		private:
			class Item {
			public:
				Item(T val) {
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
			bool pushRecursive(T, Item*&);
			void pushRecursiveWithCheckHead(T, Item*&);
			void pushHead(T, Item*&);

		public:
			class SorterStackIterator {
			private:
				Item * _head;

			public:
				SorterStackIterator(Item* head) {
					this->_head = head;
				}

				bool hasValue() {
					return _head != nullptr;
				}

				void move() {
					this->_head = this->_head->prev;
				}

				T getValue() {
					if (!this->hasValue()) {
						throw std::out_of_range("Can't find iterable items.");
					}

					return this->_head->value;
				}
			};

			SortedStack() {
				this->_head = nullptr;
			}

			void push(T);
			T pop();
			bool isEmpty();
			bool contains(T);

			SorterStackIterator* getIterator() {
				return new SorterStackIterator(this->_head);
			}

			~SortedStack() {
				delete this->_head;
			}
		};
	}
}