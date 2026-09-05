#include <iostream>

void print_element(const int* arr, const int index) {
	int element = arr[index];

	if (index == 0) {
		std::cout << index << " root " << element;
	}

	else {
		int parent_index = (index - 1) / 2;
		int parent_value = arr[parent_index];

		int level = 0;
		int temp = index + 1;
		while (temp > 1) {
			temp /= 2;
			level++;
		}

		if (index % 2 == 1) {
			std::cout << level << " left(" << parent_value << ") " << element;
		}
		else {
			std::cout << level << " right(" << parent_value << ") " << element;
		}
	}

	std::cout << std::endl;
}

void print_pyramid(const int* arr, const int size) {
	if (size <= 0 || arr == nullptr) {
		return;
	}

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i + 1 != size) {
			std::cout << " ";
		}
	}
	std::cout << std::endl << "Пирамида:" << std::endl;

	for (int i = 0; i < size; i++) {
		print_element(arr, i);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int size1 = 6;
	print_pyramid(arr1, size1);
	std::cout << std::endl;

	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int size2 = 8;
	print_pyramid(arr2, size2);
	std::cout << std::endl;

	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int size3 = 10;
	print_pyramid(arr3, size3);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
