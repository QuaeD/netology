#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

#include <string>

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

	void check() const override;

protected:
	int a{};
	int b{};
	int c{};
	int A{};
	int B{};
	int C{};

private:
	void checkTriangle() const;
};
#endif // !TRIANGLE_H
