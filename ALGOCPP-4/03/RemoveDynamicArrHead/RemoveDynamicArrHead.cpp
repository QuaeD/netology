#include <iostream>
#include <string>

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
	logical_size--;

	if (logical_size > (actual_size / 3)) {
		for (int i = 0; i < logical_size; i++) {
			arr[i] = arr[i + 1];
		}
		return arr;
	}
	if (actual_size > 1) {
		actual_size /= 3;
	}
	int* new_arr = new int[actual_size] {};

	for (int i = 0; i < logical_size; i++) {
		new_arr[i] = arr[i + 1];
	}

	delete[] arr;

	return new_arr;
}

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

	std::string answer{};

	do {
		std::cout << "Удалить первый элемент? ";
		std::cin >> answer;

		if (answer == "нет") {
			std::cout << "Спасибо! Ваш массив: ";
		}
		else {
			if (logical_size == 0) {
				std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
				return EXIT_FAILURE;
			}
			arr = remove_dynamic_array_head(arr, logical_size, actual_size);
			std::cout << "Динамический массив: ";
		}

		print_dynamic_array(arr, logical_size, actual_size);

	} while (answer != "нет");

	delete[] arr;

	return EXIT_SUCCESS;
}
