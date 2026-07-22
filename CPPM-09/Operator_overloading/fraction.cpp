#include "fraction.h"

#include <numeric>
#include <stdexcept>


Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
	reduce();
}

void Fraction::reduce()
{
	if (denominator == 0) return;

	int gcd = std::gcd(numerator, denominator);

	numerator /= gcd;
	denominator /= gcd;

	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}

int Fraction::getNumerator() const {
	return numerator;
}

int Fraction::getDenominator() const {
	return denominator;
}

bool Fraction::operator==(const Fraction& other) const {
	return (numerator * other.denominator) == (other.numerator * denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
	return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
	return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>(const Fraction& other) const {
	return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
	return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
	return !(*this < other);
}

Fraction Fraction::operator+(const Fraction& other) const {
	return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
	return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
	return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
	if (other.denominator == 0) {
		throw std::runtime_error("Деление на 0!");
	}
	return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::operator-() const {
	return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator++() {
	numerator += denominator;
	reduce();
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;

	numerator += denominator;
	reduce();

	return temp;
}

Fraction& Fraction::operator--() {
	numerator -= denominator;
	reduce();
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;

	numerator -= denominator;
	reduce();

	return temp;
}

std::string Fraction::dump() const {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
	os << frac.getNumerator() << "/" << frac.getDenominator();
	return os;
}