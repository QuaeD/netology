#include <windows.h>

#include <iostream>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string word{};
	std::cout << "Введите слово:" << std::endl;
	std::cin >> word;
	std::cout << "Вы ввели:\n" << word << std::endl;

	return EXIT_SUCCESS;
}