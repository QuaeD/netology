#include "bad_figure.h"
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
	std::cout << figure->getName() << " ";

	if (Triangle* triangle = dynamic_cast<Triangle*>(figure)) {
		std::cout << "(стороны: " <<
			triangle->get_a() << ", " <<
			triangle->get_b() << ", " <<
			triangle->get_c() << "; ";


		std::cout << "углы: " <<
			triangle->get_A() << ", " <<
			triangle->get_B() << ", " <<
			triangle->get_C() << ")";
	}

	else if (Quadrangle* quadrangle = dynamic_cast<Quadrangle*>(figure)) {
		std::cout << "(стороны: " <<
			quadrangle->get_a() << ", " <<
			quadrangle->get_b() << ", " <<
			quadrangle->get_c() << ", " <<
			quadrangle->get_d() << "; ";


		std::cout << "углы: " <<
			quadrangle->get_A() << ", " <<
			quadrangle->get_B() << ", " <<
			quadrangle->get_C() << ", " <<
			quadrangle->get_D() << ")";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		Figure figure {};
		printInfo(&figure);
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Triangle triangle{ 10, 20, 30, 50, 60, 70 };
		printInfo(&triangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;


	try {
		RightTriangle right_triangle{ 10, 20, 30, 50, 60 };
		printInfo(&right_triangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		IsoscelesTriangle isosceles_triangle{ 10, 20, 50, 60 };
		printInfo(&isosceles_triangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		EquilateralTriangle equilateral_triangle{ 30 };
		printInfo(&equilateral_triangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
		printInfo(&quadrangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Rectangle rectangle{ 10, 20 };
		printInfo(&rectangle);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Square square{ 20 };
		printInfo(&square);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Parallelogram parallelogram{ 20, 30, 30, 40 };
		printInfo(&parallelogram);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}

	std::cout << std::endl << std::endl;

	try {
		Rhombus rhombus{ 30, 30, 40 };
		printInfo(&rhombus);
		std::cout << " cоздан";
	}
	catch (const BadFigure& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}