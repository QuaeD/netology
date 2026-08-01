#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "vehicle.h"

static const char* GROUND_RACE_STR = "Гонка для наземного транспорта";
static const char* AIR_RACE_STR = "Гонка для воздушного транспорта";
static const char* GROUND_AIR_RACE_STR = "Гонка для наземного и воздушного транспорта";

class PrintUtils
{
public:
	static void printRaceInfo(const int type, const int length);
	static void printRegisteredVehicles(Vehicle*& vehicles, const int v_count);
	static void printVehicleMenu();
	static void printResults(Vehicle*& vehicles, const int v_count, double*& times);
	static void clearConsole();
	static void printRegistartionResult(int code, V_Type v_type);
};
#endif // !PRINT_UTILS_H

