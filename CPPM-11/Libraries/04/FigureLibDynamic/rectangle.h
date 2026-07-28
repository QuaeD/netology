#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "framework.h"
#include "quadrangle.h"

class FIGURE_API Rectangle : public Quadrangle
{
public:
	Rectangle(int a, int b);
};

#endif // !RECTANGLE_H
