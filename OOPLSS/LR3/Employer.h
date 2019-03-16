// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

namespace OOPLSS {
	namespace LR3 {
		class Employer
		{
		private:
			std::string fio;
			std::string position;
			std::string date;

		public:
			int departmentNumber;

			Employer(std::string fio, int dep, std::string pos, std::string date)
				:fio(fio), departmentNumber(dep), position(pos), date(date) {

			}
			~Employer() {

			}
			void print() {
				std::cout << "FIO: " << fio << std::endl;
				std::cout << "Department Number: " << departmentNumber << std::endl;
				std::cout << "Position: " << position << std::endl;
				std::cout << "Date: " << date << std::endl << std::endl;
			}
			friend std::ostream& operator<<(std::ostream& os, Employer& employer);
		};
	}
}