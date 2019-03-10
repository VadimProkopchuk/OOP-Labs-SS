// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "LR1Provider.h"
#include "SortedStack.h"
#include "../Utils/ConsoleUtils.h"

namespace OOPLSS {
	namespace LR1 {
		void LR1Provider::printChoices() {
			std::cout << "1. Push values" << std::endl;
			std::cout << "2. Pop value" << std::endl;
			std::cout << "3. Pop all values" << std::endl;
			std::cout << "4. Contains" << std::endl;
			std::cout << "5. View all items" << std::endl;
			std::cout << "6. Exit" << std::endl;
		}

		int LR1Provider::getChoice() {
			return Utils::readValue<int>("Select menu: ");
		}

		void LR1Provider::processOperations(SortedStack<int>* stack, int choice) {
			switch (choice)
			{
			case 1:
				this->pushValues(stack);
				break;
			case 2: 
				this->popValue(stack);
				break;
			case 3: 
				this->popAllValues(stack);
				break;
			case 4: 
				this->contains(stack);
				break;
			case 5: 
				this->viewAllItems(stack);
				break;
			case 6:
				this->exit();
				break;
			default:
				this->defaultOperation();
				break;
			}
		}

		void LR1Provider::pushValues(SortedStack<int>* stack) {
			int count;

			do {
				count = Utils::readValue<int>("Enter count of values: ");

				if (count < 1) {
					std::cout << "Please enter value greather 0. ";
				}
			} while (count < 1);

			for (int i = 0; i < count; i++) {
				stack->push(Utils::readValue<int>("Enter value #" + std::to_string(i) + ": "));
			}
		}

		void LR1Provider::popValue(SortedStack<int>* stack) {
			if (!stack->isEmpty()) {
				std::cout << "Value from stack: " << stack->pop() << std::endl;
			}
			else {
				std::cout << "Denied operation. Stack is empty." << std::endl;
			}
		}

		void LR1Provider::popAllValues(SortedStack<int>* stack) {
			if (!stack->isEmpty()) {
				std::cout << "Values from stack: ";

				while (!stack->isEmpty()) {
					std::cout << stack->pop() << " ";
				}

				std::cout << std::endl;
			}
			else {
				std::cout << "Denied operation. Stack is empty." << std::endl;
			}
		}

		void LR1Provider::contains(SortedStack<int>* stack) {
			if (!stack->isEmpty()) {
				int findValue = Utils::readValue<int>("Enter value for looking: ");

				std::cout << findValue << " in stack? " << (stack->contains(findValue) ? "Yes" : "No") << std::endl;
			}
			else {
				std::cout << "Denied operation. Stack is empty." << std::endl;
			}
		}

		void LR1Provider::viewAllItems(SortedStack<int>* stack) {
			SortedStack<int>::SorterStackIterator* iterator = stack->getIterator();

			std::cout << "Iterable values from stack: ";

			while (iterator->hasValue())
			{
				std::cout << iterator->getValue() << " ";
				iterator->move();
			}

			std::cout << std::endl;
			delete iterator;
		}

		void LR1Provider::exit() {
			std::cout << "Good luck." << std::endl;
		}

		void LR1Provider::defaultOperation() {
			std::cout << "Can't find operation. Please, try select again." << std::endl;
		}

		void LR1Provider::run() {
			int choice;
			SortedStack<int>* stack = new SortedStack<int>();

			this->printChoices();

			do {
				choice = this->getChoice();
				this->processOperations(stack, choice);
			} while (choice != EXIT_CHOICE);

			delete stack;
		}
	}
}