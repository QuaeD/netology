#include "check_utils_tests.h"
#include "vehicle.h"
#include "check_utils.h"

#include <cassert>

void CheckUtilsTests::startAllTests() {
	duplicateTest();
	vModeWrongTest();
}

void CheckUtilsTests::duplicateTest() {
	Vehicle* vehicles = new Vehicle[2]{
		{ V_Type::CAMEL, 1000 },
		{ V_Type::BROOM, 1000 }
	};

	assert(CheckUtils::isDuplicate(vehicles, 2, V_Type::CAMEL) == true);
	assert(CheckUtils::isDuplicate(vehicles, 2, V_Type::MAGIC_CARPET) == false);

	delete[] vehicles;
}

void CheckUtilsTests::vModeWrongTest() {
	assert(CheckUtils::isVehicleModeWrong(V_Type::CAMEL, 1) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::CAMEL, 2) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::CAMEL, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::FAST_CAMEL, 1) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::FAST_CAMEL, 2) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::FAST_CAMEL, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::CENTAUR, 1) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::CENTAUR, 2) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::CENTAUR, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::ALL_TERRAIN_BOOTS, 1) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::ALL_TERRAIN_BOOTS, 2) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::ALL_TERRAIN_BOOTS, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::MAGIC_CARPET, 1) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::MAGIC_CARPET, 2) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::MAGIC_CARPET, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::EAGLE, 1) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::EAGLE, 2) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::EAGLE, 3) == false);

	assert(CheckUtils::isVehicleModeWrong(V_Type::BROOM, 1) == true);
	assert(CheckUtils::isVehicleModeWrong(V_Type::BROOM, 2) == false);
	assert(CheckUtils::isVehicleModeWrong(V_Type::BROOM, 3) == false);
}
