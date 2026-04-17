#include <iostream>

int main() {
	int a{};
	int b{};
	int c{};

	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Введите третье число: ";
	std::cin >> c;

	int max{};
	int mid{};
	int min{};

	max = a > b ? a : b;
	max = max > c ? max : c;

	min = a < b ? a : b;
	min = min < c ? min : c;

	mid = a != min && a != max ? a :
		b != min && b != max ? b :
		c != min && c != max ? c :
		a == b && b == c ? a :
		a == b ? a :
		a == c ? a : b;

	std::cout << "Результат: " << max << " " << mid << " " << min << std::endl;

	return EXIT_SUCCESS;
}