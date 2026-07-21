#include "bad_figure.h"
#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle{ a, b, a, b, A, B, A, B, "Параллелограмм" } { check(); }

void Parallelogram::check() const {
	if ((a != c || b != d) && (A != C || B != D)) {
		throw BadFigure("стороны a,c и b,d попарно не равны, углы A,C и B,D попарно не равны");
	}
	else if (a != c || b != d) {
		throw BadFigure("стороны a,c и b,d попарно не равны");
	}
	else if (A != C || B != D) {
		throw BadFigure("углы A,C и B,D попарно не равны");
	}
}
