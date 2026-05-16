#include <iostream>

int** createTwoDimArray(int rows, int cols) {
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols] {};
	}
	return arr;
}

void fillTwoDimArray(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = (i + 1) * (j + 1);
		}
	}
}

void printTwoDimArray(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j];
			if (j + 1 != cols) {
				std::cout << '\t';
			}
		}
		std::cout << std::endl;
	}
}

void deleteTwoDimArray(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main() {
	std::cout << "Введите количество строк: ";
	int rows{};
	std::cin >> rows;

	std::cout << "Введите количество столбцов: ";
	int cols{};
	std::cin >> cols;

	int** arr_ptr = createTwoDimArray(rows, cols);
	fillTwoDimArray(arr_ptr, rows, cols);

	std::cout << "Таблица умножения:" << std::endl;
	printTwoDimArray(arr_ptr, rows, cols);

	deleteTwoDimArray(arr_ptr, rows, cols);

	return EXIT_SUCCESS;
}