// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "LR1Provider.h"

int main()
{
	OOPLSS::LR1::LR1Provider* provider = new OOPLSS::LR1::LR1Provider();

	try {
		provider->run();
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

    return 0;
}