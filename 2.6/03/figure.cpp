#include "figure.h"

Figure::Figure() : sides_count{ 0 }, name{ "Фигура" } {}
Figure::~Figure() = default;
Figure::Figure(const int sides_count, const std::string_view name) : sides_count{ sides_count }, name{ name } {}


int Figure::getSidesCount() const{
	return sides_count;
}

std::string Figure::getName() const{
	return name;
}
