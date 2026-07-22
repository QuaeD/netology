#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "quadrangle.h"

class Rhombus : public Quadrangle
{
public:
	Rhombus(int a, int A, int B);
	void check() const override;
private:
	void checkRhombus() const;
};

#endif // !RHOMBUS_H
