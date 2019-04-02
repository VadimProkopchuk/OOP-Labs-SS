// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "pch.h"
#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

#include "../Utils/ConsoleUtils.h"
#include "../Models/Employer.h"
#include "../Models/LrStack.h"

namespace OOPLSS {
	namespace LR4 {
		using namespace Models;
		using namespace Utils;

		LrStack<Employer>* readFromFile(std::string path) {
			std::ifstream file;
			LrStack<Employer>* stack = new LrStack<Employer>();
			file.open(path, std::ios::binary | std::ios::in);

			while (!file.eof()) {
				Employer* obj = new Employer();

				file.read((char*)&(*obj), sizeof(Employer));

				if (file.eof()) break;

				stack->push(*obj);
			}
			file.close();

			return stack;
		}

		void saveToFile(LrStack<Employer>* stack, std::string path) {
			std::ofstream file;
			auto iterator = stack->getIterator();

			file.open(path, std::ios::binary | std::ios::out);

			while (iterator->hasValue())
			{
				Employer* value = iterator->getValue();

				file.write((char*)&(*value), sizeof(Employer));
				iterator->move();
			}
			file.close();
		}

		void printMenu() {
			std::cout << "1. Show All Items" << std::endl
					  << "2. Show All Items Sorted by Department Number (ASC)" << std::endl
					  << "3. Show All Items Sorted by Department Number (DESC)." << std::endl
					  << "4. Edit Value" << std::endl
					  << "5. Exit" << std::endl;
		}

		void showStackValues(LrStack<Employer>* stack) {
			auto iterator = stack->getIterator();

			while (iterator->hasValue())
			{
				std::cout << *iterator->getValue() << std::endl;
				iterator->move();
			}
		}

		std::list<Employer>* getList(LrStack<Employer>* stack) {
			auto list = new std::list<Employer>();
			auto iterator = stack->getIterator();

			while (iterator->hasValue())
			{
				list->push_back(*iterator->getValue());
				iterator->move();
			}

			return list;
		}

		void runLr4() {
			std::string fileName = "employers.bin";
			int choice = -1;

			while (choice != 5) {
				printMenu();
				choice = readWithCheck<int>("Enter menu value:  ", 1);
				system("cls");

				LrStack<Employer>* employers = readFromFile(fileName);

				switch (choice)
				{
					case 1: {
						showStackValues(employers);
						break;
						}
					case 2: {
						auto list = getList(employers);
						list->sort([](const Employer& a, const Employer& b) { return a.departmentNumber > b.departmentNumber; });

						for (auto item : *list) {
							std::cout << item << std::endl;
						}
						break;
					}
					case 3: {
						auto list = getList(employers);
						list->sort([](const Employer& a, const Employer& b) { return a.departmentNumber < b.departmentNumber; });

						for (auto item : *list) {
							std::cout << item << std::endl;
						}
						break;
					}
					case 4: {
						int department = readWithCheck<int>("Enter Department: ", 1);
						Employer* editableEmployer = nullptr;
						auto iterator = employers->getIterator();

						while (iterator->hasValue())
						{
							auto employer = iterator->getValue();

							if (employer->departmentNumber == department) {
								editableEmployer = employer;
								break;
							}
							iterator->move();
						}

						if (editableEmployer != nullptr) {
							editableEmployer->setFio(readString("Enter fio: "));
							editableEmployer->setPosition(readString("Enter position: "));
							editableEmployer->setDate(readString("Enter date: "));
							saveToFile(employers, fileName);
						}
						else {
							std::cout << "Can't find Employer by department number";
						}
						break;
					}
				}

				delete employers;
			}
		}
	}
}

int main()
{
	try {
		OOPLSS::LR4::runLr4();
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