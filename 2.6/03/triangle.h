#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

#include "figure.h"

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	Triangle(int a, int b, int c, int A, int B, int C, std::string_view name);

	int get_a() const;
	int get_b() const;
	int get_c() const;
	int get_A() const;
	int get_B() const;
	int get_C() const;

protected:
	int a{};
	int b{};
	int c{};
	int A{};
	int B{};
	int C{};
};
#endif // !TRIANGLE_H
