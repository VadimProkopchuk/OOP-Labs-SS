// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once
#include <string>

namespace OOPLSS {
	namespace LR2 {
		class WildAnimal
		{
			private:
				std::string name;
				int age;
				int width;
				int height;
				int weight;
				std::string color;
				std::string type;

			public:
				WildAnimal() {}
				~WildAnimal() {}
				void readFromConsole();
				void writeToConsole();
				friend std::ostream& operator<<(std::ostream& os, WildAnimal& animal);
				friend std::istream& operator>>(std::istream& os, WildAnimal& animal);
			};
	}
}