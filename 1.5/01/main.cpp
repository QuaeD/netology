#include <iostream>

int main() {
	const int SIZE = 10;
	int arr[SIZE] ={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	for (size_t i = 0; i < SIZE; i++) {
		std::cout << arr[i];
		if (i + 1 != SIZE) {
			std::cout << ", ";
		}
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}