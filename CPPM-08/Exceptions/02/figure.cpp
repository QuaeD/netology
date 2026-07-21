#include "bad_figure.h"
#include "figure.h"

Figure::Figure() : sides_count{ 0 }, name{ "Фигура" } { check(); }
Figure::~Figure() = default;
Figure::Figure(const int sides_count, const std::string_view name) : sides_count{ sides_count }, name{ name } {}


int Figure::getSidesCount() const{
	return sides_count;
}

std::string Figure::getName() const{
	return name;
}

void Figure::check() const {
	throw BadFigure("неопределенная фигура");
}
