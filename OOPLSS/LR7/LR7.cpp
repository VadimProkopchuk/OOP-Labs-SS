// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "pch.h"
#include <list>
#include <iterator>
#include <algorithm>

namespace OOPLSS {
	using namespace Models;
	using namespace Utils;

	namespace LR6 {
		void menu() {
			std::cout 
				<< "1. Push to Front" << std::endl
				<< "2. Push to Back" << std::endl
				<< "3. Iterate Elements to Right" << std::endl
				<< "4. Iterate Elements to Left" << std::endl
				<< "5. Shell Sort by Department Number (Asc)" << std::endl
				<< "6. Shell Sort by Department Number (Desc)" << std::endl
				<< "7. Check Condition for All Items" << std::endl
				<< "8. Get All Items Satisfying the Condition" << std::endl
				<< "9. Exit" << std::endl;
		}

		int readChoice() {
			int choice = readWithCheck<int>("Enter choice: ", 1);
			system("cls");

			return choice;
		}

		std::string read_str(std::string msg) {
			std::string value;
			std::cout << msg;
			std::getline(std::cin, value);

			return value;
		}

		void readEmployer(Employer* employer) {
			std::cin.ignore();

			employer->setFio(read_str("Enter FIO: "));
			employer->setPosition(read_str("Enter position: "));
			employer->setDate(read_str("Enter date: "));

			employer->departmentNumber = readWithCheck<int>("Enter department number: ", 0);
		}

		void lr() {
			int choice = -1;
			std::list<Employer>* list = new std::list<Employer>();
			Employer* buffer;

			while (choice != 9)
			{
				menu();
				choice = readChoice();

				switch (choice)
				{
				case 1: {
					int enter = 1;
					while (enter != 0) {
						buffer = new Employer();
						readEmployer(buffer);
						list->push_front(*buffer);
						enter = readValue<int>("Enter again? 0 - No: ");
					}
					break;
				}
				case 2: {
					int enter = 1;
					while (enter != 0) {
						buffer = new Employer();
						readEmployer(buffer);
						list->push_back(*buffer);
						enter = readValue<int>("Enter again? 0 - No: ");
					}

					break;
				}
				case 3: {
					for (auto iterator = list->begin(); iterator != list->end(); ++iterator)
					{
						std::cout << *iterator << std::endl;
					}
					break;
				}
				case 4: {
					for (auto iterator = list->rbegin(); iterator != list->rend(); ++iterator)
					{
						std::cout << *iterator << std::endl;
					}
					break;
				}
				case 5: {
					list->sort([](Employer& _empl1, Employer& _empl2) {return _empl1 < _empl2;});
					for (auto iterator = list->begin(); iterator != list->end(); ++iterator)
					{
						std::cout << *iterator << std::endl;
					}
					break;
				}
				case 6: {
					list->sort([](Employer& _empl1, Employer& _empl2) {return _empl1 > _empl2;});
					for (auto iterator = list->begin(); iterator != list->end(); ++iterator)
					{
						std::cout << *iterator << std::endl;
					}
					break;
				}
				case 7: {
					bool res = std::all_of(list->begin(), list->end(), [](Employer& employer) -> bool {return employer.departmentNumber >= 3;});

					std::cout << "Condition: All department numbers greather or equal to 3." << std::endl
						<< "Result: " << (res ? "Yes" : "No") << std::endl;

					break;
				}
				case 8: {
					std::cout << "Condition: items with department number equal to 5." << std::endl << "Result: " << std::endl;
					std::list<Employer> condition_items;
					std::copy_if(list->begin(), list->end(), std::back_inserter(condition_items), 
						[](Employer& employer) -> bool {return employer.departmentNumber == 5;});
					
					for (auto iterator = condition_items.begin(); iterator != condition_items.end(); ++iterator)
					{
						std::cout << *iterator << std::endl;
					}
					
					break;
				}
				}
			}
		}
	}
}

int main()
{
	try {
		OOPLSS::LR6::lr();
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