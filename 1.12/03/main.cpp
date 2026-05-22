#include <fstream>
#include <iostream>

int main() {
	std::cout << "Введите размер массива: ";
	int size{};
	std::cin >> size;

	int* arr_ptr = new int[size] {};

	for (int i = 0; i < size; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr_ptr[i];
	}

	std::ofstream file("out.txt");

	file << size << std::endl;

	for (int i = size - 1; i >= 0; i--) {
		file << arr_ptr[i];
		if (i - 1 >= 0) {
			file << " ";
		}
	}

	file.close();
	delete[] arr_ptr;

	return EXIT_SUCCESS;
}