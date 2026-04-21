#include <iostream>

int main() {
	int sum{};
	int number{};

	do {
		std::cout << "Введите целое число или число '0', чтобы закончить:" << std::endl;
		std::cin >> number;
		sum += number;
	} while (number != 0);

	std::cout << "Сумма: " << sum << std::endl;

	return EXIT_SUCCESS;
}