#ifndef CHECK_UTILS_H
#define CHECK_UTILS_H

#include "vehicle.h"

class CheckUtils
{
public:
	static const bool isDuplicate(Vehicle*& vehicles, const int v_count, const V_Type type);
	static const bool isVehicleModeWrong(const V_Type type, const int race_type);
};

#endif // !CHECK_UTILS_H
