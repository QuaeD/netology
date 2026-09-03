#include <iostream>

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i != size - 1) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;
}

void quick_sort(int* arr, int size) {
	if (size <= 1) {
		return;
	}

	int pivot = arr[size / 2];

	int* left = new int[size] {};
	int* right = new int[size] {};
	int* equal = new int[size] {};

	int left_size = 0;
	int right_size = 0;
	int equal_size = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] < pivot) {
			left[left_size++] = arr[i];
		}
		else if (arr[i] > pivot) {
			right[right_size++] = arr[i];
		}
		else {
			equal[equal_size++] = arr[i];
		}
	}

	quick_sort(left, left_size);
	quick_sort(right, right_size);

	int index = 0;
	for (int i = 0; i < left_size; i++) {
		arr[index++] = left[i];
	}
	for (int i = 0; i < equal_size; i++) {
		arr[index++] = equal[i];
	}
	for (int i = 0; i < right_size; i++) {
		arr[index++] = right[i];
	}

	delete[] left;
	delete[] right;
	delete[] equal;
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int SIZE_1 = 10;
	int arr_1[SIZE_1] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };

	std::cout << "Исходный массив: ";
	print(arr_1, SIZE_1);
	quick_sort(arr_1, SIZE_1);
	std::cout << "Отсортированный массив: ";
	print(arr_1, SIZE_1);

	const int SIZE_2 = 15;
	int arr_2[SIZE_2] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };

	std::cout << "Исходный массив: ";
	print(arr_2, SIZE_2);
	quick_sort(arr_2, SIZE_2);
	std::cout << "Отсортированный массив: ";
	print(arr_2, SIZE_2);

	const int SIZE_3 = 18;
	int arr_3[SIZE_3] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив: ";
	print(arr_3, SIZE_3);
	quick_sort(arr_3, SIZE_3);
	std::cout << "Отсортированный массив: ";
	print(arr_3, SIZE_3);

	return EXIT_SUCCESS;
}
