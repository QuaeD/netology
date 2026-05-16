#include <iostream>

double* createArray(int size) {
	return new double[size] {};
}

int main() {
	std::cout << "Введите размер массива: ";
	int size{};
	std::cin >> size;

	double* arr_ptr = createArray(size);

	std::cout << "Массив: ";

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