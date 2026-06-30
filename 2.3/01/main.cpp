#include <iostream>

class Calculator
{
public:
	double add() {
		return num1 + num2;
	}

	double multiply() {
		return num1 * num2;
	}

	double substract_1_2() {
		return num1 - num2;
	}

	double substract_2_1() {
		return num2 - num1;
	}

	double divide_1_2() {
		return num1 / num2;
	}

	double divide_2_1() {
		return num2 / num1;
	}

	bool set_num1(double num1) {
		if (num1 == 0) {
			return false;
		}
		this->num1 = num1;
		return true;
	}

	bool set_num2(double num2) {
		if (num2 == 0) {
			return false;
		}
		this->num2 = num2;
		return true;
	}

private:
	double num1{};
	double num2{};
};

void printCalculator(Calculator& calculator) {
	std::cout << "num1 + num2 = " << calculator.add() << std::endl;
	std::cout << "num1 - num2 = " << calculator.substract_1_2() << std::endl;
	std::cout << "num2 - num1 = " << calculator.substract_2_1() << std::endl;
	std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
	std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
	std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
}

int main() {
	Calculator calculator{};
	double num{};

	while (true)
	{
		do {
			std::cout << "Введите num1: ";
			std::cin >> num;
			if (calculator.set_num1(num)) {
				break;
			}
			else {
				std::cout << "Неверный ввод!" << std::endl;
			}
		} while (true);

		do {
			std::cout << "Введите num2: ";
			std::cin >> num;
			if (calculator.set_num2(num)) {
				break;
			}
			else {
				std::cout << "Неверный ввод!" << std::endl;
			}
		} while (true);

		printCalculator(calculator);
	}

	return EXIT_SUCCESS;
}