#include <iostream>

int main() {
	int number{};

	std::cout << "Введите целое число:" << std::endl;
	std::cin >> number;

	for (int i = 1; i <= 10; ++i) {
		std::cout << number << " x " << i << " = " << number * i << std::endl;
	}

	return EXIT_SUCCESS;
}