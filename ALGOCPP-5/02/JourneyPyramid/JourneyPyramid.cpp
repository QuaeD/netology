#include <iostream>
#include <string>

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

int get_parent_index(const int current_index) {
	if (current_index == 0) {
		return -1;
	}
	return (current_index - 1) / 2;
}

int get_left_child_index(const int current_index, const int size) {
	int left_index = 2 * current_index + 1;
	if (left_index >= size) {
		return -1;
	}
	return left_index;
}

int get_right_child_index(const int current_index, const int size) {
	int right_index = 2 * current_index + 2;
	if (right_index >= size) {
		return -1;
	}
	return right_index;
}

void start_journey(const int* arr, const int size) {
	if (size <= 0 || arr == nullptr) {
		return;
	}

	int current_index = 0;
	std::string command;

	do {
		std::cout << "Вы находитесь здесь: ";
		print_element(arr, current_index);

		std::cout << "Введите команду: ";
		std::cin >> command;

		if (command == "exit") {
			break;
		}
		else if (command == "up") {
			int parent_index = get_parent_index(current_index);
			if (parent_index == -1) {
				std::cout << "Ошибка! Отсутствует родитель" << std::endl;
			}
			else {
				current_index = parent_index;
				std::cout << "Ок" << std::endl;
			}
		}
		else if (command == "left") {
			int left_child_index = get_left_child_index(current_index, size);
			if (left_child_index == -1) {
				std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
			}
			else {
				current_index = left_child_index;
				std::cout << "Ок" << std::endl;
			}
		}
		else if (command == "right") {
			int right_index = get_right_child_index(current_index, size);
			if (right_index == -1) {
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
			}
			else {
				current_index = right_index;
				std::cout << "Ок" << std::endl;
			}
		}
		else {
			std::cout << "Ошибка! Неизвестная команда" << std::endl;
		}
	} while (true);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int size1 = 6;
	print_pyramid(arr1, size1);
	start_journey(arr1, size1);

	return EXIT_SUCCESS;
}
