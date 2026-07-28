#include <iostream>

#include "GreeterLibStatic.h"

int main(){
	std::cout << "Введите имя: ";
	
	std::string name{};
	std::cin >> name;

	std::cout << GreeterLibStatic::Greeter::greet(name) << std::endl;

	return EXIT_SUCCESS;
}
