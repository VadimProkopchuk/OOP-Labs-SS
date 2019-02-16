// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

#include <string>
#include <iostream>

namespace OOPLSS {
	namespace Utils {
		class ConsoleUtils {
		public:
			static int readInt(const std::string&);
		};

		inline int ConsoleUtils::readInt(const std::string &msg)
		{
			int value;

			std::cout << msg;

			while ((!(std::cin >> value)) || (std::cin.peek() != '\n')) {
				std::cout << "Entered value is not valid. Please, try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			return value;
		}
	}
}