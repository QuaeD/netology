#include <iostream>

int main() {
	int sum{};
	int number{};

	std::cout << "Введите целое число:" << std::endl;
	std::cin >> number;

	while (number != 0) {
		sum += number % 10;
		number /= 10;
	}

	std::cout << "Сумма цифр: " << sum << std::endl;

	return EXIT_SUCCESS;
}