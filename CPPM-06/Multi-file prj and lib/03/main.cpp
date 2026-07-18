#include "equilateral_triangle.h"
#include "figure.h"
#include "isosceles_triangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "right_triangle.h"
#include "rhombus.h"
#include "square.h"
#include "triangle.h"
#include "quadrangle.h"

#include <iostream>
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

int main() {
	setlocale(LC_ALL, "Russian");

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

	return EXIT_SUCCESS;
}