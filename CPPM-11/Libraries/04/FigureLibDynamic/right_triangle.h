#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "framework.h"
#include "triangle.h"

class FIGURE_API RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B);
};

#endif // !RIGHT_TRIANGLE_H
