#include "bad_figure.h"
#include "square.h"

Square::Square(int a) : Quadrangle{ a, a, a, a, 90, 90, 90, 90, "Квадрат" } { checkSquare(); }

void Square::check() const {
	checkSquare();
}

void Square::checkSquare() const {
	if ((a != b || a != c || a != d) && (A != 90 || B != 90 || C != 90 || D != 90)) {
		throw BadFigure("стороны не равны, углы не равны 90");
	}
	else if (a != b || a != c || a != d) {
		throw BadFigure("стороны не равны");
	}
	else if (A != 90 || B != 90 || C != 90 || D != 90) {
		throw BadFigure("углы не равны 90");
	}
}
