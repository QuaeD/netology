#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator;
	int denominator;

	void reduce();


public:
	Fraction(int numerator, int denominator);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);

	int getNumerator() const;
	int getDenominator() const;
	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;
	Fraction operator-() const;
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);
	std::string dump() const;
};

#endif // !FRACTION_H
