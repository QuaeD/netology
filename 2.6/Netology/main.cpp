#include "counter.h"
#include "equilateral_triangle.h"
#include "figure.h"
#include "isosceles_triangle.h"
#include "my_math.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "right_triangle.h"
#include "rhombus.h"
#include "square.h"
#include "triangle.h"
#include "quadrangle.h"

#include <iostream>
#include <stdexcept>
#include <string>

void printInfo(Figure* figure) {
	std::cout << figure->getName() << ":" << std::endl;

	if (Triangle* triangle = dynamic_cast<Triangle*>(figure)) {
		std::cout << "Стороны: " <<
			"a=" << triangle->get_a() << " " <<
			"b=" << triangle->get_b() << " " <<
			"c=" << triangle->get_c() << std::endl;


		std::cout << "Углы: " <<
			"A=" << triangle->get_A() << " " <<
			"B=" << triangle->get_B() << " " <<
			"C=" << triangle->get_C() << std::endl;
	}

	else if (Quadrangle* quadrangle = dynamic_cast<Quadrangle*>(figure)) {
		std::cout << "Стороны: " <<
			"a=" << quadrangle->get_a() << " " <<
			"b=" << quadrangle->get_b() << " " <<
			"c=" << quadrangle->get_c() << " " <<
			"d=" << quadrangle->get_d() << std::endl;


		std::cout << "Углы: " <<
			"A=" << quadrangle->get_A() << " " <<
			"B=" << quadrangle->get_B() << " " <<
			"C=" << quadrangle->get_C() << " " <<
			"D=" << quadrangle->get_D() << std::endl;
	}
}

void startHW1() {
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
}

void startHW2() {
	Counter counter{};

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string answer{};
	std::cin >> answer;

	if (answer == "да" || answer == "д" || answer == "yes" || answer == "y") {
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
}

void startHW3() {
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	RightTriangle right_triangle{ 10, 20, 30, 50, 60 };
	IsoscelesTriangle isosceles_triangle{ 10, 20, 50, 60 };
	EquilateralTriangle equilateral_triangle{ 30 };
	Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
	Rectangle rectangle{ 10, 20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20, 30, 30, 40 };
	Rhombus rhombus{ 30, 30, 40 };

	printInfo(&triangle);
	std::cout << std::endl;

	printInfo(&right_triangle);
	std::cout << std::endl;

	printInfo(&isosceles_triangle);
	std::cout << std::endl;

	printInfo(&equilateral_triangle);
	std::cout << std::endl;

	printInfo(&quadrangle);
	std::cout << std::endl;

	printInfo(&rectangle);
	std::cout << std::endl;

	printInfo(&square);
	std::cout << std::endl;

	printInfo(&parallelogram);
	std::cout << std::endl;

	printInfo(&rhombus);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int num{};

	do {
		std::cout << "Введите номер запускаемого задания (1, 2 или 3). Введите 0 для завершения: " << std::endl;
		std::cin >> num;

		switch (num)
		{
		case 1:
			startHW1();
			break;
		case 2:
			startHW2();
			break;
		case 3:
			startHW3();
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (num != 0);

	return EXIT_SUCCESS;
}