// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <list>

namespace OOPLSS {
	namespace LR3 {
		void fillFakeData(std::stack<Employer>* stack) {
			stack->push(Employer("fio1", 1, "pos1", "14.03.2019"));
			stack->push(Employer("fio3", 3, "pos3", "10.2019"));
			stack->push(Employer("fio2", 2, "pos2", "17.03.2019"));
			stack->push(Employer("fio5", 5, "pos5", "9.03.2019"));
			stack->push(Employer("fio4", 4, "pos4", "9.03.2019"));
		}

		void runLr3() {
			std::string fileName = "employers.bin";

			remove(fileName.c_str());

			std::stack<Employer>* stack = new std::stack<Employer>();
			Utils::FileSaver<std::stack<Employer>>* saver = new Utils::FileSaver<std::stack<Employer>>(fileName);
			Utils::FileReader<std::stack<Employer>>* reader = new Utils::FileReader<std::stack<Employer>>(fileName);

			fillFakeData(stack);
			saver->save(stack);

			std::stack<Employer>* employers = reader->read();
			std::list<Employer>* list = new std::list<Employer>();

			while (!employers->empty()) {
				list->push_back(employers->top());
				employers->pop();
			}

			list->sort([](const Employer& a, const Employer& b) { return a.departmentNumber > b.departmentNumber; });

			for (auto item : *list) {
				std::cout << item << std::endl;
			}

			delete stack;
			delete saver;
			delete reader;
			delete list;
		}
	}
}

int main()
{
	try {
		OOPLSS::LR3::runLr3();
	}
	catch (const std::bad_alloc & ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Sorry :(" << std::endl << "Unknown exception. Please, contact us to resolve the error." << std::endl;
	}

	system("pause");
	return 0;
}