#include <iostream>

int main() {
	std::cout << "Введите размер массива: ";
	int size{};
	std::cin >> size;

	int* arr_ptr = new int[size];

	for (int i = 0; i < size; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr_ptr[i];
	}

	std::cout << "Введённый массив: ";

	for (int i = 0; i < size; i++) {
		std::cout << arr_ptr[i];
		if (i + 1 != size) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	delete[] arr_ptr;

	return EXIT_SUCCESS;
}