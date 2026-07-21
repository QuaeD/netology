#ifndef BAD_FIGURE_H
#define BAD_FIGURE_H

#include <stdexcept>

class BadFigure : public std::domain_error
{
public:
	BadFigure(const char* message);
};

#endif // !BAD_FIGURE_H
