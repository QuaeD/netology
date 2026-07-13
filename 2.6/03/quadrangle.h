#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "figure.h"

class Quadrangle : public Figure
{
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string_view name);

	int get_a() const;
	int get_b() const;
	int get_c() const;
	int get_d() const;
	int get_A() const;
	int get_B() const;
	int get_C() const;
	int get_D() const;

protected:
	int a{};
	int b{};
	int c{};
	int d{};
	int A{};
	int B{};
	int C{};
	int D{};
};

#endif // !QUADRANGLE_H
