#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "triangle.h"

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a);
	void check() const override;
private:
	void checkEquilateralTriangle() const;
};

#endif // !EQUILATERAL_TRIANGLE_H
