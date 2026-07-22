#include "bad_figure.h"
#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : Triangle{ a, b, a, A, B, A, "Равнобедренный треугольник" } { checkIsoscelesTriangle(); }

void IsoscelesTriangle::check() const {
	checkIsoscelesTriangle();
}

void IsoscelesTriangle::checkIsoscelesTriangle() const {
	if (a != c && A != C) {
		throw BadFigure("стороны a и c не равны, углы A и C не равны");
	}
	else if (a != c) {
		throw BadFigure("стороны a и c не равны");
	}
	else if (A != C) {
		throw BadFigure("углы A и C не равны");
	}
}
