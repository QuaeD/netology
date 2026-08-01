#ifndef RACE_ENGINE_H
#define RACE_ENGINE_H

#include "vehicle.h"

class RaceEngine
{
public:
	static int registerVehicle(Vehicle*& vehicles, int& v_count, const V_Type v_type, const int distance, const int race_type);
	static void startRace(Vehicle*& vehicles, const int v_count, const int distance, double*& times);
private:
	static void sortTimesVehicles(Vehicle*& vehicles, const int v_count, double*& times);
};

#endif // !RACE_ENGINE_H
