#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B);
	void check() const override;
private:
	void checkParallelogram() const;
};

#endif // !PARALLELOGRAM_H
