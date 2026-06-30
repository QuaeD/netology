#include <iostream>
#include <string>

class Counter
{
public:
	Counter() {
		count = 1;
	}

	Counter(int value) {
		count = value;
	}

	void increase1() {
		count++;
	}

	void decrease1() {
		count--;
	}

	int getValue() {
		return count;
	}

private:
	int count;
};

int main() {
	Counter counter;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string answer{};
	std::cin >> answer;

	if (answer == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		int num{};
		std::cin >> num;
		counter = Counter(num);
	}
	else {
		counter = Counter();
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