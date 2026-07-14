#include "preprocessor_directives.h"
#include "sub_macro.h"

#include <iostream>

#define MODE 1

int main() {
	setlocale(LC_ALL, "Russian");

	int num{};

	do {
		std::cout << "Введите номер запускаемого задания (1 или 2). Введите 0 для завершения: " << std::endl;
		std::cin >> num;

		switch (num)
		{
		case 1:
			PreprocessorDirectives hw_1;
			hw_1.start();
			break;
		case 2:
			SubMacro hw_2;
			hw_2.start();
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (num != 0);

	return EXIT_SUCCESS;
}