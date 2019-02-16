// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once
#include "SortedStack.cpp"

namespace OOPLSS {
	namespace LR1 {
		class LR1Provider {
			void printChoices();
			int getChoice();
			void processOperations(SortedStack<int>*, int);
			void pushValues(SortedStack<int>*);
			void popValue(SortedStack<int>*);
			void popAllValues(SortedStack<int>*);
			void contains(SortedStack<int>*);
			void viewAllItems(SortedStack<int>*);
			void exit();
			void defaultOperation();

		public: 
			const int EXIT_CHOICE = 6;
			
			void run();
		};
	}
}