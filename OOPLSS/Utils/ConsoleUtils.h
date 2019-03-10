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
		template<class T>
		T readValue(std::string msg) {
			T value;

			std::cout << msg;

			while ((!(std::cin >> value)) || (std::cin.peek() != '\n')) {
				std::cout << "Entered value is not valid. Please, try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			return value;
		}

		template <class T>
		T readWithCheck(std::string msg, T min) {
			T res = readValue<T>(msg);

			while (res < min)
			{
				std::cout << "Enter value greather " << min << std::endl;
				res = readValue<T>(msg);
			}

			return res;
		}
	}
}