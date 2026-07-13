#include "my_math.h"

#include <stdexcept>

int MyMath::sum(const int x, const int y) {
	return x + y;
}

int MyMath::diff(const int x, const int y) {
	return x - y;
}

int MyMath::mult(const int x, const int y) {
	return x * y;
}

double MyMath::division(const int x, const int y) {
	if (y == 0) {
		throw std::invalid_argument("Деление на 0 запрещено!");
	}
	return static_cast<double>(x) / y;
}

double MyMath::pow(const int x, const int exp) {
	if (exp == 0) {
		return 1;
	}

	if (exp == 1) {
		return x;
	}

	double result = x;
	int exp_positive = exp < 0 ? -exp : exp;

	for (int i = 1; i < exp_positive; i++) {
		result *= x;
	}

	if (exp < 0) {
		result = 1.0 / result;
	}

	return result;
}
