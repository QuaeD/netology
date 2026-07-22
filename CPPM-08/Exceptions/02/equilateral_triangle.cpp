#include "bad_figure.h"
#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(int a) : Triangle{ a, a, a, 60, 60, 60, "Равносторонний треугольник" } { checkEquilateralTriangle(); }

void EquilateralTriangle::check() const {
	checkEquilateralTriangle();
}

void EquilateralTriangle::checkEquilateralTriangle() const {
	if ((a != b || a != c) && (A != 60 || B != 60 || C != 60)) {
		throw BadFigure("стороны не равны друг другу, углы не равны 60");
	}
	else if (a != b || a != c) {
		throw BadFigure("стороны не равны друг другу");
	}
	else if (A != 60 || B != 60 || C != 60) {
		throw BadFigure("углы не равны 60");
	}
}
