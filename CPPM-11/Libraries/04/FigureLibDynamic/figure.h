#ifndef FIGURE_H
#define FIGURE_H

#include "framework.h"

#include <string>
#include <string_view>

class FIGURE_API Figure
{
public:
	Figure();
	virtual ~Figure();
	
	int getSidesCount() const;
	std::string getName() const;

protected:
	Figure(const int sides_count, const std::string_view name);
	int sides_count{};
	std::string name{};
};

#endif // !FIGURE_H
