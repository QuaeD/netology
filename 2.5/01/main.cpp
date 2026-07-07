#include <iostream>
#include <string>

class Figure
{
public:
	Figure() : sides_count{ 0 }, name{ "Фигура" } {}

	int getSidesCount() const {
		return sides_count;
	}

	std::string getName() const {
		return name;
	}

protected:
	Figure(const int sides_count, const std::string_view name) : sides_count{ sides_count }, name{ name } {}
	int sides_count{};
	std::string name{};
};

class Triangle : public Figure
{
public:
	Triangle() : Figure{ 3, "Треугольник" } {}
};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure{ 4, "Четырёхугольник" } {}
};

int main() {
	std::cout << "Количество сторон:" << std::endl;

	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << figure.getName() << ": " << figure.getSidesCount() << std::endl;
	std::cout << triangle.getName() << ": " << triangle.getSidesCount() << std::endl;
	std::cout << quadrangle.getName() << ": " << quadrangle.getSidesCount() << std::endl;

	return EXIT_SUCCESS;
}