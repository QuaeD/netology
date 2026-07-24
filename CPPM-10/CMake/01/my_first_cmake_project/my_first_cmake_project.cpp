// my_first_cmake_project.cpp: определяет точку входа для приложения.
#include <iostream>
#include <string>

int main()
{
	std::cout << "Введите имя: ";
	
	std::string name{};
	std::cin >> name;

	std::cout << "Здравствуйте, " << name << "!" << std::endl;
	return EXIT_SUCCESS;
}
