#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "quadrangle.h"

class Rectangle : public Quadrangle
{
public:
	Rectangle(int a, int b);
	void check() const override;
private:
	void checkRectangle() const;
};

#endif // !RECTANGLE_H
