#include "fraction.h"
#include "tests.h"

#include <cassert>
#include <iostream>
#include <numeric>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите числитель дроби 1: ";
	int numerator_1{};
	std::cin >> numerator_1;

	std::cout << "Введите знаменатель дроби 1: ";
	int denominator_1{};
	std::cin >> denominator_1;

	std::cout << "Введите числитель дроби 2: ";
	int numerator_2{};
	std::cin >> numerator_2;

	std::cout << "Введите знаменатель дроби 2: ";
	int denominator_2{};
	std::cin >> denominator_2;

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);

	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
	std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
	std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;
	std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	std::cout << f1 << "--" << " * " << f2 << " = " << (f1-- * f2) << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;

	Tests tests{};
	tests.start();

	return EXIT_SUCCESS;
}