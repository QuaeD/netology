#include <iostream>

// Сложность по времени: O(n)
// Сложность по памяти: O(n)
unsigned long long fibonacci(int number, unsigned long long* memory) {
	if (memory[number] != 0) {
		return memory[number];
	}

	if (number == 0) {
		memory[0] = 0;
		return 0;
	}
	if (number == 1) {
		memory[1] = 1;
		return 1;
	}

	memory[number] = fibonacci(number - 1, memory) + fibonacci(number - 2, memory);
	return memory[number];
}

int main() {
	setlocale(LC_ALL, "Russian");

	int count{};
	std::cout << "Введите число: ";
	std::cin >> count;

	unsigned long long* memory = new unsigned long long[count]{};

	std::cout << "Числа Фибоначчи: ";

	for (int i = 0; i < count; i++) {
		std::cout << fibonacci(i, memory);
		if (i < count - 1) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	delete[] memory;

	return EXIT_SUCCESS;
}