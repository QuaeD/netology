#include "my_math.h"

#include <iostream>
#include <stdexcept>

int main() {
	std::cout << "Введите первое число: ";
	int x{};
	std::cin >> x;

	std::cout << "Введите второе число: ";
	int y{};
	std::cin >> y;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	int op{};
	std::cin >> op;

	switch (op)
	{
	case 1:
		std::cout << x << " + " << y << " = " << MyMath::sum(x, y) << std::endl;
		break;
	case 2:
		std::cout << x << " - " << y << " = " << MyMath::diff(x, y) << std::endl;
		break;
	case 3:
		std::cout << x << " * " << y << " = " << MyMath::mult(x, y) << std::endl;
		break;
	case 4:
		try {
			std::cout << x << " / " << y << " = " << MyMath::division(x, y) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cout << x << " / " << y << " = " << e.what() << std::endl;
		}
		break;
	case 5:
		std::cout << x << " в степени " << y << " = " << MyMath::pow(x, y) << std::endl;
		break;
	default:
		break;
	}

	return EXIT_SUCCESS;
}