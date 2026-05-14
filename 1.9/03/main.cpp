#include <iostream>

void reverse(int arr[], const int size) {
	for (int i = 0; i < size / 2; i++) {
		std::swap(arr[i], arr[size - 1 - i]);
	}
}

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
	const int size = 9;
	int arr[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "До функции reverce: ";
	print(arr, size);

	reverse(arr, size);

	std::cout << "\nПосле функции reverce: ";
	print(arr, size);

	return EXIT_SUCCESS;
}