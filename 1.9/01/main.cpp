#include <iostream>

void print(const int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i + 1 != size) {
			std::cout << " ";
		}
	}
	std::cout << '\n';
}


int main() {
	const int size_1 = 9;
	int arr_1[size_1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(arr_1, size_1);

	const int size_2 = 4;
	int arr_2[size_2] = { 6, 5, 4, 8 };
	print(arr_2, size_2);

	const int size_3 = 5;
	int arr_3[size_3] = { 1, 4, 3, 7, 5 };
	print(arr_3, size_3);

	return EXIT_SUCCESS;
}