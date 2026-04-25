#include <iostream>

int main() {
	const int SIZE_I = 3;
	const int SIZE_J = 6;

	int arr[SIZE_I][SIZE_J] = {
		{ 1, 2, 3, 4, 5, 6 },
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18}
	};

	int index_min[2] = { 0, 0 };
	int index_max[2] = { 0, 0 };
	int min = arr[0][0];
	int max = arr[0][0];

	std::cout << "Массив:" << std::endl;

	for (int i = 0; i < SIZE_I; ++i) {
		for (int j = 0; j < SIZE_J; ++j) {
			std::cout << arr[i][j];

			if (j + 1 != SIZE_J) {
				std::cout << '\t';
			}

			if (min > arr[i][j]) {
				min = arr[i][j];
				index_min[0] = i;
				index_min[1] = j;
			}

			if (max < arr[i][j]) {
				max = arr[i][j];
				index_max[0] = i;
				index_max[1] = j;
			}
		}
		std::cout << std::endl;
	}

	std::cout << "Индекс минимального элемента: " << index_min[0] << " " << index_min[1] << std::endl;
	std::cout << "Индекс максимального элемента: " << index_max[0] << " " << index_max[1] << std::endl;

	return EXIT_SUCCESS;
}