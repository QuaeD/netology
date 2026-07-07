#include <iostream>
#include <string>

const char* CORRECT_FIGURE = "Правильная";
const char* INCORRECT_FIGURE = "Неправильная";

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
	virtual bool check() const {
		return getSidesCount() == 0 ? true : false;
	}

	virtual void printInfo() const {
		std::cout << getName() << ":" << std::endl;
		std::cout << (check() ? CORRECT_FIGURE : INCORRECT_FIGURE) << std::endl;
		std::cout << "Количество сторон: " << getSidesCount() << std::endl;
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

	bool check() const override {
		return ((getSidesCount() == 3) && (get_A() + get_B() + get_C() == 180)) ? true : false;
	}

	void printInfo() const override {
		Figure::printInfo();
		std::cout << "Стороны: " <<
			"a=" << get_a() << " " <<
			"b=" << get_b() << " " <<
			"c=" << get_c() << std::endl;

		std::cout << "Углы: " <<
			"A=" << get_A() << " " <<
			"B=" << get_B() << " " <<
			"C=" << get_C() << std::endl;
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

	bool check() const override {
		return (getSidesCount() == 4) && ((get_A() + get_B() + get_C() + get_D() == 360)) ? true : false;
	}

	void printInfo() const override {
		Figure::printInfo();
		std::cout << "Стороны: " <<
			"a=" << get_a() << " " <<
			"b=" << get_b() << " " <<
			"c=" << get_c() << " " <<
			"d=" << get_d() << std::endl;

		std::cout << "Углы: " <<
			"A=" << get_A() << " " <<
			"B=" << get_B() << " " <<
			"C=" << get_C() << " " <<
			"D=" << get_D() << std::endl;
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

	bool check() const override {
		return (Triangle::check() &&
			get_C() == 90) ? true : false;
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle{ a, b, a, A, B, A, "Равнобедренный треугольник" } {}

	bool check() const override {
		return (Triangle::check() &&
			get_a() == get_c() &&
			get_A() == get_C()) ? true : false;
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a) : Triangle{ a, a, a, 60, 60, 60, "Равносторонний треугольник" } {}

	bool check() const override {
		return (Triangle::check() &&
			get_a() == get_b() &&
			get_a() == get_c() &&
			get_A() == get_B() &&
			get_A() == get_C()) ? true : false;
	}
};

class Rectangle : public Quadrangle
{
public:
	Rectangle(int a, int b) : Quadrangle{ a, b, a, b, 90, 90, 90, 90, "Прямоугольник" } {}

	bool check() const override {
		return (Quadrangle::check() &&
			get_a() == get_c() &&
			get_b() == get_d() &&
			get_A() == get_B() &&
			get_A() == get_C() &&
			get_A() == get_D() &&
			get_A() == 90) ? true : false;
	}
};

class Square : public Quadrangle
{
public:
	Square(int a) : Quadrangle{ a, a, a, a, 90, 90, 90, 90, "Квадрат" } {}

	bool check() const override {
		return (Quadrangle::check() &&
			get_a() == get_b() &&
			get_a() == get_c() &&
			get_a() == get_d() &&
			get_A() == get_B() &&
			get_A() == get_C() &&
			get_A() == get_D() &&
			get_A() == 90) ? true : false;
	}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle{ a, b, a, b, A, B, A, B, "Параллелограмм" } {}

	bool check() const override {
		return (Quadrangle::check() &&
			get_a() == get_c() &&
			get_b() == get_d() &&
			get_A() == get_C() &&
			get_B() == get_D()) ? true : false;
	}
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(int a, int A, int B) : Quadrangle{ a, a, a, a, A, B, A, B, "Ромб" } {}

	bool check() const override {
		return (Quadrangle::check() &&
			get_a() == get_b() &&
			get_a() == get_c() &&
			get_a() == get_d() &&
			get_A() == get_C() &&
			get_B() == get_D()) ? true : false;
	}
};

int main() {
	Figure figure;
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	RightTriangle right_triangle_1{ 10, 20, 30, 50, 60 };
	RightTriangle right_triangle_2{ 10, 20, 30, 50, 40 };
	IsoscelesTriangle isosceles_triangle{ 10, 20, 50, 60 };
	EquilateralTriangle equilateral_triangle{ 30 };
	Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
	Rectangle rectangle{ 10, 20 };
	Square square{ 20 };
	Parallelogram parallelogram{ 20, 30, 30, 40 };
	Rhombus rhombus{ 30, 30, 40 };

	figure.printInfo();
	std::cout << std::endl;

	triangle.printInfo();
	std::cout << std::endl;

	right_triangle_1.printInfo();
	std::cout << std::endl;

	right_triangle_2.printInfo();
	std::cout << std::endl;

	isosceles_triangle.printInfo();
	std::cout << std::endl;

	equilateral_triangle.printInfo();
	std::cout << std::endl;

	quadrangle.printInfo();
	std::cout << std::endl;

	rectangle.printInfo();
	std::cout << std::endl;

	square.printInfo();
	std::cout << std::endl;

	parallelogram.printInfo();
	std::cout << std::endl;

	rhombus.printInfo();

	return EXIT_SUCCESS;
}