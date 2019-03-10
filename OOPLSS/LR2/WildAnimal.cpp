// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include "WildAnimal.h"
#include "string.h"
#include <iostream>
#include "../Utils/ConsoleUtils.h"

namespace OOPLSS {
	namespace LR2 {
		void WildAnimal::readFromConsole()
		{
			this->name = Utils::readValue<std::string>("Enter name: ");
			this->age = Utils::readWithCheck<int>("Enter age: ", 0);
			this->width = Utils::readWithCheck<int>("Enter approximated width: ", 0);
			this->height = Utils::readWithCheck<int>("Enter approximated height: ", 0);
			this->weight = Utils::readWithCheck<int>("Enter approximated weight: ", 0);
			this->color = Utils::readValue<std::string>("Enter color: ");
			this->type = Utils::readValue<std::string>("Enter type: ");
		}

		void WildAnimal::writeToConsole()
		{
			std::cout << std::endl;
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
			std::cout << "Width: " << this->width << std::endl;
			std::cout << "Height: " << this->height << std::endl;
			std::cout << "Weight: " << this->weight << std::endl;
			std::cout << "Color: " << this->color << std::endl;
			std::cout << "Type: " << this->type << std::endl;
			std::cout << std::endl;
		}

		std::ostream & operator<<(std::ostream & os, WildAnimal & animal)
		{
			animal.writeToConsole();
			return os;
		}

		std::istream & operator>>(std::istream & is, WildAnimal & animal)
		{
			animal.readFromConsole();
			return is;
		}
	}
}