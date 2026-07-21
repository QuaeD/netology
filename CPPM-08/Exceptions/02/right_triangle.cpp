#include "bad_figure.h"
#include "right_triangle.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B) : Triangle{ a, b, c, A, B, 90, "Прямоугольный треугольник" } { check(); }

void RightTriangle::check() const {
	if (C != 90) {
		throw BadFigure("угол C не равен 90");
	}
}
