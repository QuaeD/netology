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

void merge_sort(int* arr, int size) {
	if (size <= 1) {
		return;
	}

	int mid = size / 2;

	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);

	int* temp_arr = new int[mid] {};

	for (int i = 0; i < mid; i++) {
		temp_arr[i] = arr[i];
	}

	int iter_left = 0;
	int iter_right = mid;
	int iter_arr = 0;

	while (iter_left < mid && iter_right < size) {
		if (arr[iter_right] < temp_arr[iter_left]) {
			arr[iter_arr++] = arr[iter_right++];
		}
		else {
			arr[iter_arr++] = temp_arr[iter_left++];
		}
	}

	while (iter_left < mid) {
		arr[iter_arr++] = temp_arr[iter_left++];
	}

	delete[] temp_arr;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	const int SIZE_1 = 10;
	int arr_1[SIZE_1] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };

	std::cout << "Исходный массив: ";
	print(arr_1, SIZE_1);
	merge_sort(arr_1, SIZE_1);
	std::cout << "Отсортированный массив: ";
	print(arr_1, SIZE_1);

	const int SIZE_2 = 15;
	int arr_2[SIZE_2] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };

	std::cout << "Исходный массив: ";
	print(arr_2, SIZE_2);
	merge_sort(arr_2, SIZE_2);
	std::cout << "Отсортированный массив: ";
	print(arr_2, SIZE_2);

	const int SIZE_3 = 18;
	int arr_3[SIZE_3] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив: ";
	print(arr_3, SIZE_3);
	merge_sort(arr_3, SIZE_3);
	std::cout << "Отсортированный массив: ";
	print(arr_3, SIZE_3);

	return EXIT_SUCCESS;
}
