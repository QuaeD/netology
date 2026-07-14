#include "sub_macro.h"

#include <iostream>

#define SUB(a, b) ((a) - (b))

void SubMacro::start()
{
	int a = 6;
	int b = 5;
	int c = 2;

	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;
}
