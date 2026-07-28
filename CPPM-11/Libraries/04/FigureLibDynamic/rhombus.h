#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "framework.h"
#include "quadrangle.h"

class FIGURE_API Rhombus : public Quadrangle
{
public:
	Rhombus(int a, int A, int B);
};

#endif // !RHOMBUS_H
