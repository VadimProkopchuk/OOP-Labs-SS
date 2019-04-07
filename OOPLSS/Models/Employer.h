// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

namespace OOPLSS {
	namespace Models {
		class Employer
		{
			private:
				std::string fio;
				std::string position;
				std::string date;

			public:
				int departmentNumber;

				Employer() {

				}

				Employer(std::string fio, int dep, std::string pos, std::string date)
					:fio(fio), departmentNumber(dep), position(pos), date(date) {

				}

				void setFio(std::string newFio) {
					this->fio = newFio;
				}

				void setPosition(std::string newPosition) {
					this->position = newPosition;
				}

				void setDate(std::string newDate) {
					this->date = newDate;
				}

				friend std::ostream& operator<<(std::ostream& outputStream, const Employer& employer) {
					outputStream << "FIO: " << employer.fio << std::endl <<
									"Department Number: " << employer.departmentNumber << std::endl <<
									"Position: " << employer.position << std::endl <<
									"Date: " << employer.date << std::endl <<
									std::endl;

					return outputStream;
				}

				bool operator < (const Employer& employer) {
					return this->departmentNumber < employer.departmentNumber;
				}

				bool operator > (const Employer& employer) {
					return this->departmentNumber > employer.departmentNumber;
				}

				bool operator == (const Employer& employer) {
					return this->departmentNumber == employer.departmentNumber;
				}
		};
	}
}