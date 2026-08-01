#include "race_engine_tests.h"
#include "vehicle.h"
#include "race_engine.h"

#include <cassert>

void RaceEngineTests::startAllTests() {
	registerVehicleTest();
	startRaceTest();
}

void RaceEngineTests::registerVehicleTest() {
	int v_max_count = 7;
	int v_count{ 0 };
	Vehicle* vehicles = new Vehicle[v_max_count]{};
	assert(RaceEngine::registerVehicle(vehicles, v_count, V_Type::CAMEL, 1000, 1) == 0);
	assert(v_count == 1);
	assert(vehicles[0].getType() == V_Type::CAMEL);

	assert(RaceEngine::registerVehicle(vehicles, v_count, V_Type::CAMEL, 1000, 1) == 1);
	assert(v_count == 1);
	assert(vehicles[0].getType() == V_Type::CAMEL);

	assert(RaceEngine::registerVehicle(vehicles, v_count, V_Type::BROOM, 1000, 1) == 2);
	assert(v_count == 1);
	assert(vehicles[0].getType() == V_Type::CAMEL);

	assert(RaceEngine::registerVehicle(vehicles, v_count, V_Type::CAMEL, 1000, -1) == -1);
	assert(v_count == 1);
	assert(vehicles[0].getType() == V_Type::CAMEL);

	assert(RaceEngine::registerVehicle(vehicles, v_count, V_Type::FAST_CAMEL, 1000, 1) == 0);
	assert(v_count == 2);
	assert(vehicles[0].getType() == V_Type::CAMEL);
	assert(vehicles[1].getType() == V_Type::FAST_CAMEL);

	delete[] vehicles;
}

void RaceEngineTests::startRaceTest() {
	int v_count = 3;
	Vehicle* vehicles = new Vehicle[v_count]{
		{V_Type::CAMEL, 4500},
		{V_Type::CENTAUR, 4500},
		{V_Type::ALL_TERRAIN_BOOTS, 4500}
	};

	double* times = new double[v_count] {};

	RaceEngine::startRace(vehicles, v_count, 4500, times);

	assert(times[0] == 374.0);
	assert(times[1] == 559.0);
	assert(times[2] == 815.0);

	assert(vehicles[0].getType() == V_Type::CENTAUR);
	assert(vehicles[1].getType() == V_Type::CAMEL);
	assert(vehicles[2].getType() == V_Type::ALL_TERRAIN_BOOTS);

	delete[] times;
	delete[] vehicles;
}
