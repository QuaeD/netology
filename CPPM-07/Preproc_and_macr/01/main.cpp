#include <iostream>

#define MODE 1

#ifndef MODE
#error "MODE" is not defined!!!
#endif // !MODE

#if MODE == 1
#define add(a, b) ((a) + (b))
#endif

int main() {
	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	std::cout << "Работаю в боевом режиме" << std::endl;

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

	return EXIT_SUCCESS;
}