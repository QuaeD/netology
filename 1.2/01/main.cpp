#include <windows.h>

#include <iostream>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int number{};
	std::cout << "Введите число:" << std::endl;
	std::cin >> number;
	std::cout << "Вы ввели:\n" << number << std::endl;

	return EXIT_SUCCESS;
}