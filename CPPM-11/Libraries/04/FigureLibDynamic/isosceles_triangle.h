#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "framework.h"
#include "triangle.h"

class FIGURE_API IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B);
};

#endif // !ISOSCELES_TRIANGLE_H
