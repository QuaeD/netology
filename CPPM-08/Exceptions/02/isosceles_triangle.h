#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B);
	void check() const override;
private:
	void checkIsoscelesTriangle() const;
};

#endif // !ISOSCELES_TRIANGLE_H
