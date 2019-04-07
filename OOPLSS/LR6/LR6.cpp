// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "pch.h"

namespace OOPLSS {
	using namespace Models;
	using namespace Utils;

	namespace LR6 {
		void menu() {
			std::cout << "1. Push to Front" << std::endl
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
			LinkedList<Employer>* list = new LinkedList<Employer>();
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
					list->toBackIterator()->show();
					break;
				}
				case 4: {
					list->toFrontIterator()->show();
					break;
				}
				case 5: {
					list->sortAsc();
					list->toBackIterator()->show();
					break;
				}
				case 6: {
					list->sortDesc();
					list->toBackIterator()->show();
					break;
				}
				case 7: {
					bool res = list->all([](Employer& employer) -> bool {return employer.departmentNumber >= 3;});

					std::cout << "Condition: All department numbers greather or equal to 3." << std::endl
						<< "Result: " << (res ? "Yes" : "No") << std::endl;

					break;
				}
				case 8: {
					std::cout << "Condition: items with department number equal to 5." << std::endl << "Result: " << std::endl;
					list->where_by_predicate([](Employer& employer) -> bool {return employer.departmentNumber == 5;})->show();
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