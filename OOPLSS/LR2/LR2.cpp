// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include "WildAnimal.h"
#include <iostream>

int main()
{
	OOPLSS::LR2::WildAnimal* animal = new OOPLSS::LR2::WildAnimal();

	std::cin >> *animal;
	std::cout << std::endl << *animal;
	system("pause");
	
	return 0;
}