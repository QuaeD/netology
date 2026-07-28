#include <iostream>

#include "LeaverLibDynamic.h"

int main() {
	std::cout << "Введите имя: ";

	std::string name{};
	std::cin >> name;

	std::cout << LeaverLibDynamic::Leaver::leave(name) << std::endl;
}
