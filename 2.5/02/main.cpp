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
	Triangle(int a, int b, int c, int A, int B, int C) : Figure{ 3, "Треугольник" }, a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}
	Triangle(int a, int b, int c, int A, int B, int C, std::string_view name) : Figure{ 3, name }, a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {}

	int get_a() const {
		return a;
	}
	int get_b() const {
		return b;
	}
	int get_c() const {
		return c;
	}
	int get_A() const {
		return A;
	}
	int get_B() const {
		return B;
	}
	int get_C() const {
		return C;
	}

protected:
	int a{};
	int b{};
	int c{};
	int A{};
	int B{};
	int C{};
};

class Quadrangle : public Figure
{
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure{ 4, "Четырёхугольник" }, a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string_view name) : Figure{ 4, name }, a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {}

	int get_a() const {
		return a;
	}
	int get_b() const {
		return b;
	}
	int get_c() const {
		return c;
	}
	int get_d() const {
		return d;
	}
	int get_A() const {
		return A;
	}
	int get_B() const {
		return B;
	}
	int get_C() const {
		return C;
	}
	int get_D() const {
		return D;
	}

protected:
	int a{};
	int b{};
	int c{};
	int d{};
	int A{};
	int B{};
	int C{};
	int D{};
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle{ a, b, c, A, B, 90, "Прямоугольный треугольник" } {}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle{ a, b, a, A, B, A, "Равнобедренный треугольник" } {}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a) : Triangle{ a, a, a, 60, 60, 60, "Равносторонний треугольник" } {}
};

class Rectangle : public Quadrangle
{
public:
	Rectangle(int a, int b) : Quadrangle{ a, b, a, b, 90, 90, 90, 90, "Прямоугольник" } {}
};

class Square : public Quadrangle
{
public:
	Square(int a) : Quadrangle{ a, a, a, a, 90, 90, 90, 90, "Квадрат" } {}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle{ a, b, a, b, A, B, A, B, "Параллелограмм" } {}
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(int a, int A, int B) : Quadrangle{ a, a, a, a, A, B, A, B, "Ромб" } {}
};

void printInfo(Triangle& triangle) {
	std::cout << triangle.getName() << ":" << std::endl;
	std::cout << "Стороны: " <<
		"a=" << triangle.get_a() << " " <<
		"b=" << triangle.get_b() << " " <<
		"c=" << triangle.get_c() << std::endl;


	std::cout << "Углы: " <<
		"A=" << triangle.get_A() << " " <<
		"B=" << triangle.get_B() << " " <<
		"C=" << triangle.get_C() << std::endl;
}

void printInfo(Quadrangle& quadrangle) {
	std::cout << quadrangle.getName() << ":" << std::endl;
	std::cout << "Стороны: " <<
		"a=" << quadrangle.get_a() << " " <<
		"b=" << quadrangle.get_b() << " " <<
		"c=" << quadrangle.get_c() << " " <<
		"d=" << quadrangle.get_d() << std::endl;


	std::cout << "Углы: " <<
		"A=" << quadrangle.get_A() << " " <<
		"B=" << quadrangle.get_B() << " " <<
		"C=" << quadrangle.get_C() << " " <<
		"D=" << quadrangle.get_D() << std::endl;
}

int main() {
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	RightTriangle right_triangle{ 10, 20, 30, 50, 60 };
	IsoscelesTriangle isosceles_triangle{ 10, 20, 50, 60 };
	EquilateralTriangle equilateral_triangle{ 30 };
	Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
	Rectangle rectangle{ 10, 20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20, 30, 30, 40 };
	Rhombus rhombus{ 30, 30, 40 };

	printInfo(triangle);
	std::cout << std::endl;

	printInfo(right_triangle);
	std::cout << std::endl;

	printInfo(isosceles_triangle);
	std::cout << std::endl;

	printInfo(equilateral_triangle);
	std::cout << std::endl;

	printInfo(quadrangle);
	std::cout << std::endl;

	printInfo(rectangle);
	std::cout << std::endl;

	printInfo(square);
	std::cout << std::endl;

	printInfo(parallelogram);
	std::cout << std::endl;

	printInfo(rhombus);

	return EXIT_SUCCESS;
}