// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

namespace OOPLSS {
	namespace Models {
		template <class T>
		class LinkedList
		{
		private:
			class Item {
			public:
				Item* next;
				Item* prev;
				T value;

				Item() {
					prev = nullptr;
					next = nullptr;
				}

				~Item() {
					delete next;
					delete prev;
				}
			};

			Item* _head;

			Item* get_last_item() {
				Item* buffer = this->_head;

				if (buffer == nullptr) {
					return buffer;
				}

				while (buffer->next != nullptr)
				{
					buffer = buffer->next;
				}

				return buffer;
			}

			int increment(long inc[], long size) {
				int p1, p2, p3, s;

				p1 = p2 = p3 = 1;
				s = -1;
				do {
					if (++s % 2) {
						inc[s] = 8 * p1 - 6 * p2 + 1;
					}
					else {
						inc[s] = 9 * p1 - 9 * p3 + 1;
						p2 *= 2;
						p3 *= 2;
					}
					p1 *= 2;
				} while (3 * inc[s] < size);

				return s > 0 ? --s : 0;
			}

			int get_size() {
				long size = 0;
				Item* head = this->_head;

				while (head != nullptr) {
					size++;
					head = head->next;
				}

				return size;
			}

			T* to_array(long size) {
				T* arr = new T[size];
				long index = 0;
				Item* head = this->_head;

				while (head != nullptr) {
					arr[index] = head->value;
					head = head->next;
					index++;
				}

				return arr;
			}

			void shell_sort(T* a, long size, bool(*compare)(T&, T&)) {
				long inc, i, j, seq[40];
				int s;

				s = increment(seq, size);
				while (s >= 0) {
					inc = seq[s--];

					for (i = inc; i < size; i++) {
						T temp = a[i];
						for (j = i - inc; (j >= 0) && compare(a[j], temp); j -= inc)
							a[j + inc] = a[j];
						a[j + inc] = temp;
					}
				}
			}

			void sort(bool(*compare)(T&, T&)) {
				long size = this->get_size();
				T* arr = to_array(size);

				shell_sort(arr, size, compare);
				this->_head = nullptr;

				for (long i = 0; i < size; i++) {
					this->push_back(arr[i]);
				}
			}

		public:
			class Iterator {
			private:
				Item * _head;
				Item*(*_moveNext)(Item*);

			public:
				Iterator(Item* head, Item* (*moveNext)(Item*)) {
					this->_head = head;
					this->_moveNext = moveNext;
				}

				bool hasValue() {
					return _head != nullptr;
				}

				void moveNext() {
					this->_head = this->_moveNext(this->_head);
				}

				T* getValue() {
					if (!this->hasValue()) {
						throw std::out_of_range("Can't find iterable items.");
					}

					return &(this->_head->value);
				}

				void set_value(T& val) {
					this->_head->value = val;
				}

				void show() {
					if (this->_head == nullptr) {
						std::cout << "Sequence does not contain iterable items." << std::endl;
						return;
					}

					while (this->hasValue())
					{
						std::cout << *this->getValue();

						this->moveNext();
					}
				}
			};

			LinkedList() {
				this->_head = nullptr;
			}

			~LinkedList() {
				delete _head;
			}

			void push_back(T val) {
				if (this->_head == nullptr) {
					this->_head = new Item();
					this->_head->value = val;
				}
				else {
					Item* buffer = this->get_last_item();

					buffer->next = new Item();
					buffer->next->value = val;
					buffer->next->prev = buffer;
				}
			}

			void push_front(T val) {
				if (this->_head == nullptr) {
					this->_head = new Item();
					this->_head->value = val;
				}
				else {
					Item* buffer = this->_head;
					Item* head = new Item();

					this->_head = head;
					buffer->prev = head;

					head->next = buffer;
					head->value = val;
				}
			}

			Iterator* toBackIterator() {
				return new Iterator(this->_head, [](Item* head) -> Item* { return head->next; });
			}

			Iterator* toFrontIterator() {
				return new Iterator(this->get_last_item(), [](Item* head) -> Item* { return head->prev; });
			}

			void sortAsc() {
				this->sort([](T& val1, T& val2) -> bool {return val1 > val2;});
			}

			void sortDesc() {
				this->sort([](T& val1, T& val2) -> bool {return val1 < val2;});
			}

			// lr6
			//Iterator* compare_list(LinkedList<T>* list) {
			//	Item* head = this->_head;
			//	Iterator* iterator = list->toBackIterator();

			//	while (head != nullptr) {
			//		if (iterator->hasValue() && !(*iterator->getValue() == head->value)) {
			//			break;
			//		}

			//		head = head->next;
			//		iterator->moveNext();
			//	}

			//	return new Iterator(head, [](Item* head) -> Item* { return head->next; });
			//}

			//void set_value_by_predicate(T& val, bool(*where)(T&)) {
			//	Iterator* iterator = this->toBackIterator();

			//	while (iterator->hasValue()) {
			//		if (where(*iterator->getValue())) {
			//			iterator->set_value(val);
			//		}

			//		iterator->moveNext();
			//	}
			//}
		};
	}
}