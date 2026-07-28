#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "framework.h"
#include "quadrangle.h"

class FIGURE_API Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B);
};

#endif // !PARALLELOGRAM_H
