#include <iostream>

int main() {
	const int SIZE = 10;

	int arr[SIZE] = { 10, 3, 4, 1, 8, 9, 7, 2, 6, 5 };

	std::cout << "Массив до сортировки: ";

	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i];

		if (i + 1 != SIZE) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	int index_j{};
	bool break_flag{};

	do {
		break_flag = true;
		for (int i = SIZE - 1 - index_j; i > 0 && i > index_j; i--) {
			if (arr[index_j] > arr[i]) {
				std::swap(arr[i], arr[index_j]);
				break_flag = false;
			}
		}
		++index_j;
	} while (index_j != SIZE || !break_flag);

	std::cout << "Массив после сортировки: ";

	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i];

		if (i + 1 != SIZE) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}