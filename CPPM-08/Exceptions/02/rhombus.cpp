#include "bad_figure.h"
#include "rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Quadrangle{ a, a, a, a, A, B, A, B, "Ромб" } { check(); }

void Rhombus::check() const {
	if ((a != b || a != c || a != d) && (A != C || B != D)) {
		throw BadFigure("стороны не равны, углы A,C и B,D попарно не равны");
	}
	else if (a != b || a != c || a != d) {
		throw BadFigure("стороны не равны");
	}
	else if (A != C || B != D) {
		throw BadFigure("углы A,C и B,D попарно не равны");
	}
}
