#include "stdafx.h"
#include <string>
#include <fstream>
#include "../Models/Stack.h"

namespace OOPLSS {
	namespace LR4 {
		template<class T> class StackFileSaver {
		private:
			std::string _path;

		public:
			StackFileSaver(std::string path) :_path(path) {

			}

			void save(Stack<T>* stack) {
				std::ofstream file;
				Stack<T>::StackIterator iterator = stack->getIterator();

				file.open(this->_path, std::ios::binary | std::ios::out);

				while (iterator->hasValue())
				{
					file.write((char*)&(iterator.getValue()), sizeof(T));
					iterator->move();
				}
				file.close();
			}
		};
	}
}