#include "preprocessor_directives.h"

#include <iostream>

#define MODE 1

void PreprocessorDirectives::start()
{
#ifndef MODE
#error "MODE" is not defined!!!
#endif // !MODE

#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	std::cout << "Работаю в боевом режиме" << std::endl;

#define add(a, b) ((a) + (b))

	std::cout << "Введите число 1: ";
	int num_1{};
	std::cin >> num_1;

	std::cout << "Введите число 2: ";
	int num_2{};
	std::cin >> num_2;

	std::cout << "Результат сложения: " << add(num_1, num_2) << std::endl;

#else
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;

#endif
}
