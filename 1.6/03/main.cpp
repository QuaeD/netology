#include <iostream>

// variant 1
int fibonacciRecursion(int number) {
	if (number == 0) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}

	return fibonacciRecursion(number - 1) + fibonacciRecursion(number - 2);
}

// variant 2
unsigned long long fibbonacci(int number) {
	if (number == 0) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}

	unsigned long long previous_number = 0;
	unsigned long long current_number = 1;
	unsigned long long next_number{};

	for (int i = 2; i <= number; i++) {
		next_number = previous_number + current_number;
		previous_number = current_number;
		current_number = next_number;
	}

	return current_number;
}

int main() {
	int count{};
	std::cout << "Введите число: ";
	std::cin >> count;

	std::cout << "Числа Фибоначчи: ";

	for (int i = 0; i < count; i++) {
		std::cout << fibbonacci(i);
		if (i < count - 1) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}