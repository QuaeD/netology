#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("in.txt");

	if (!file.is_open()) {
		std::cout << "Ошибка при открытии файла [in.txt]" << std::endl;
		return EXIT_FAILURE;
	}

	int rows{};
	file >> rows;
	int cols{};
	file >> cols;

	int** arr_ptr = new int* [rows] {};

	for (int i = 0; i < rows; i++) {
		arr_ptr[i] = new int[cols] {};
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			file >> arr_ptr[i][j];
		}
	}

	file.close();

	for (int i = 0; i < rows; i++) {
		for (int j = cols - 1; j >= 0; j--) {
			std::cout << arr_ptr[i][j];
			if (j - 1 >= 0) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] arr_ptr[i];
	}

	delete[] arr_ptr;

	return EXIT_SUCCESS;
}