#include <algorithm>
#include <iostream>
#include <tuple>

void swap(int& a, int& b) {
	// через 3 переменную
	int c = a;
	a = b;
	b = c;
}

void swapArithmetic(int& a, int& b) {
	// может случиться переполнение, если a и b слишком большие
	a = a + b;
	b = a - b;
	a = a - b;
}

void swapXor(int& a, int& b) {
	// a и b должны указывать на разные переменные иначе 0
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void swapTuple(int& a, int& b) {
	// можно через кортеж, правда в C# это удобнее реализовано
	std::tie(a, b) = std::make_tuple(b, a);
}

void swapAlgorithm(int& a, int& b) {
	// как мне кажется - это самый эффективный вариант
	std::swap(a, b);
}

int main() {
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swapArithmetic(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swapXor(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swapTuple(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swapAlgorithm(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	return EXIT_SUCCESS;
}