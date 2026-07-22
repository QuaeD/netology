#include "bad_figure.h"
#include "rectangle.h"

Rectangle::Rectangle(int a, int b) : Quadrangle{ a, b, a, b, 90, 90, 90, 90, "Прямоугольник" } { checkRectangle(); }

void Rectangle::check() const {
	checkRectangle();
}

void Rectangle::checkRectangle() const {
	if ((a != c || b != d) && (A != 90 || B != 90 || C != 90 || D != 90)) {
		throw BadFigure("стороны a,c и b,d попарно не равны, углы не равны 90");
	}
	else if (a != c || b != d) {
		throw BadFigure("стороны a,c и b,d попарно не равны");
	}
	else if (A != 90 || B != 90 || C != 90 || D != 90) {
		throw BadFigure("углы не равны 90");
	}
}
