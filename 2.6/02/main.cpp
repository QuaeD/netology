#include "counter.h"

#include <iostream>
#include <string>


int main() {
	Counter counter{};

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string answer{};
	std::cin >> answer;

	if (answer == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		int num{};
		std::cin >> num;
		counter = Counter(num);
	}

	bool break_flag = false;
	do {
		break_flag = false;
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> answer;

		if (answer == "+") {
			counter.increase1();
		}
		else if (answer == "-") {
			counter.decrease1();
		}
		else if (answer == "=") {
			std::cout << counter.getValue() << std::endl;
		}
		else if (answer == "x" /*eng*/ || answer == "х" /*ru*/) {
			std::cout << "До свидания!" << std::endl;
			break_flag = true;
		}
	} while (!break_flag);

	return EXIT_SUCCESS;
}