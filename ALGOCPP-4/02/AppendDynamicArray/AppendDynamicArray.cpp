#include <iostream>

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_element) {
	if (logical_size < actual_size) {
		arr[logical_size] = new_element;
		logical_size++;
		return arr;
	}

	actual_size *= 2;
	int* new_arr = new int[actual_size] {};

	for (int i = 0; i < logical_size; i++) {
		new_arr[i] = arr[i];
	}

	delete[] arr;

	new_arr[logical_size] = new_element;
	logical_size++;
	return new_arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << arr[i];
		}
		else {
			std::cout << "_";
		}

		if (i + 1 != actual_size) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите фактический размер массива: ";
	int actual_size{};
	std::cin >> actual_size;

	std::cout << "Введите логический размер массива: ";
	int logical_size{};
	std::cin >> logical_size;

	if (logical_size > actual_size) {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
		return EXIT_FAILURE;
	}

	int* arr = new int[actual_size] {};

	for (int i = 0; i < logical_size; i++) {
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}

	std::cout << "Динамический массив: ";
	print_dynamic_array(arr, logical_size, actual_size);

	int new_element{};
	
	do {
		std::cout << "Введите элемент для добавления: ";
		std::cin >> new_element;


		if (new_element == 0) {
			std::cout << "Спасибо! Ваш массив: ";
		}
		else {
			arr = append_to_dynamic_array(arr, logical_size, actual_size, new_element);
			std::cout << "Динамический массив: ";
		}

		print_dynamic_array(arr, logical_size, actual_size);

	} while (new_element != 0);

	delete[] arr;

	return EXIT_SUCCESS;
}
