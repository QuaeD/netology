#ifndef SQUARE_H
#define SQUARE_H

#include "quadrangle.h"

class Square : public Quadrangle
{
public:
	Square(int a);
	void check() const override;
};

#endif // !SQUARE_H
