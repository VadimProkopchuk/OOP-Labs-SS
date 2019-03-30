// ======================================
// Copyright © 2018 Vadim Prokopchuk. All rights reserved.
// Contacts: mailvadimprokopchuk@gmail.com
// License:  http://opensource.org/licenses/MIT
// ======================================

#pragma once

#include <string>
#include <fstream>

namespace OOPLSS {
	namespace Utils {
		template <class T>
		class FileSaver
		{
		private:
			std::string path;

		public:
			FileSaver(std::string path) : path(path) {

			}
			~FileSaver() {
			}
			void save(T* obj) {
				std::ofstream file;
				file.open(this->path, std::ios::binary|std::ios::out);
				file.write((char*)&(*obj), sizeof(T));
				file.close();
			}
		};
	}
}