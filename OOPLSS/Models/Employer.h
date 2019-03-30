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

				Employer(std::string fio, int dep, std::string pos, std::string date)
					:fio(fio), departmentNumber(dep), position(pos), date(date) {

				}
				~Employer() {
					this->fio.clear();
					this->position.clear();
					this->date.clear();
				}

				friend std::ostream& operator<<(std::ostream& outputStream, Employer& employer) {
					outputStream << "FIO: " << employer.fio << std::endl <<
									"Department Number: " << employer.departmentNumber << std::endl <<
									"Position: " << employer.position << std::endl <<
									"Date: " << employer.date << std::endl <<
									std::endl;

					return outputStream;
				}
		};
	}
}