#include <iostream>

int main() {
	const int SIZE = 10;
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int min = arr[0];
	int max = arr[0];

	std::cout << "Массив: ";

	for (size_t i = 0; i < SIZE; i++) {
		std::cout << arr[i];

		if (min > arr[i]) {
			min = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}

		if (i + 1 != SIZE) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	std::cout << "Минимальный элемент: " << min << std::endl;
	std::cout << "Максимальный элемент: " << max << std::endl;

	return EXIT_SUCCESS;
}