#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("in.txt");

	if (!file.is_open()) {
		std::cout << "Ошибка при открытии файла [in.txt]" << std::endl;
		return EXIT_FAILURE;
	}

	int size{};
	file >> size;

	int* arr_ptr = new int[size];

	for (int i = 0; i < size; i++) {
		file >> arr_ptr[i];
	}

	file.close();

	for (int i = size - 1; i >= 0; i--) {
		std::cout << arr_ptr[i];
		if (i - 1 >= 0) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	delete[] arr_ptr;

	return EXIT_SUCCESS;
}