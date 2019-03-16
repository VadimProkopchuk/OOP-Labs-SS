// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#include "stdafx.h"
#include "Employer.h"
#include "string"

std::ostream & OOPLSS::LR3::operator<<(std::ostream & os, Employer & employer)
{
	os << "FIO: " << employer.fio << std::endl;
	os << "Department Number: " << employer.departmentNumber << std::endl;
	os << "Position: " << employer.position << std::endl;
	os << "Date: " << employer.date << std::endl << std::endl;

	return os;
}