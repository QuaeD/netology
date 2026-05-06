#include <iostream>

int main() {
	int a_int{};
	short a_short{};
	long a_long{};
	long long a_long_long{};
	float a_float{};
	double a_double{};
	long double a_long_double{};
	bool a_bool{};

	std::cout << "short: " << &a_short << " " << sizeof(a_short) << '\n';
	std::cout << "int: " << &a_int << " " << sizeof(a_int) << '\n';
	std::cout << "long: " << &a_long << " " << sizeof(a_long) << '\n';
	std::cout << "long long: " << &a_long_long << " " << sizeof(a_long_long) << '\n';
	std::cout << "float: " << &a_float << " " << sizeof(a_float) << '\n';
	std::cout << "double: " << &a_double << " " << sizeof(a_double) << '\n';
	std::cout << "long double: " << &a_long_double << " " << sizeof(a_long_double) << '\n';
	std::cout << "bool: " << &a_bool << " " << sizeof(a_bool) << '\n';

	return EXIT_SUCCESS;
}