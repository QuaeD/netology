#include <iostream>

// Сложность по времени: O(2^n)
// Сложность по памяти: O(n)
unsigned long long fibonacci(int number) {
	if (number == 0) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}

	return fibonacci(number - 1) + fibonacci(number - 2);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int count{};
	std::cout << "Введите число: ";
	std::cin >> count;

	std::cout << "Числа Фибоначчи: ";

	for (int i = 0; i < count; i++) {
		std::cout << fibonacci(i);
		if (i < count - 1) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}