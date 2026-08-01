#ifndef NAMING_UTILS_H
#define NAMING_UTILS_H

#include "vehicle.h"
#include <string>

class NamingUtils
{
public:
	static const std::string getVehicleNameByType(const V_Type type);
};

#endif // !NAMING_UTILS_H
