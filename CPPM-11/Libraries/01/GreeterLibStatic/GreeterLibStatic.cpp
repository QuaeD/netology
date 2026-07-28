#include "GreeterLibStatic.h"

std::string GreeterLibStatic::Greeter::greet(const std::string& str_value)
{
	return std::string("Здравствуйте, ") + str_value + "!";
}
