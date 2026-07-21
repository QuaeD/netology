#include "bad_figure.h"

#include <string>

BadFigure::BadFigure(const char* message) :
	std::domain_error(std::string{ "Ошибка создания фигуры! Причина: " } + message)
{}
