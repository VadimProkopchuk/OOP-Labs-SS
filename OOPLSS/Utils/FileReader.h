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
		class FileReader
		{
		private:
			std::string path;

		public:
			FileReader(std::string path) : path(path){
			}
			~FileReader() {
			}
			T* read() {
				T* obj = new T();;
				std::ifstream file;

				file.open(this->path, std::ios::in);
				file.read((char*)&(*obj), sizeof(*obj));
				file.close();

				return obj;
			}
		};
	}
}