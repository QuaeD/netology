#include "vehicle_tests.h"
#include "vehicle.h"

#include <cassert>

void VehicleTests::startAllTests() {
	testAllTerrainBootsCreate();
	testBroomCreate();
	testCamelCreate();
	testCentaurCreate();
	testEagleCreate();
	testFastCamelCreate();
	testMagicCarpetCreate();

	testAllTerrainBootsSetGetFinishTime();
	testBroomSetGetFinishTime();
	testCamelSetGetFinishTime();
	testCentaurSetGetFinishTime();
	testEagleSetGetFinishTime();
	testFastCamelSetGetFinishTime();
	testMagicCarpetSetGetFinishTime();
}

void VehicleTests::testAllTerrainBootsCreate() {
	Vehicle v_all_terrain_boots{ V_Type::ALL_TERRAIN_BOOTS, 1000 };
	assert(v_all_terrain_boots.getName() == ALL_TERRAIN_BOOTS_NAME_RU);
	assert(v_all_terrain_boots.getType() == V_Type::ALL_TERRAIN_BOOTS);
	assert(v_all_terrain_boots.getMode() == V_Mode::GROUND);
	assert(v_all_terrain_boots.getSpeed() == 6);
	assert(v_all_terrain_boots.getTimeToRest() == 60);
	assert(v_all_terrain_boots.getDistanceReductionCoeff() == 0);
	assert(v_all_terrain_boots.getFirstRestTime() == 10.0);
	assert(v_all_terrain_boots.getSecondRestTime() == 5.0);
	assert(v_all_terrain_boots.getNextRestTime() == 5.0);
}

void VehicleTests::testBroomCreate() {
	Vehicle v_broom{ V_Type::BROOM, 4500 };
	assert(v_broom.getName() == BROOM_NAME_RU);
	assert(v_broom.getType() == V_Type::BROOM);
	assert(v_broom.getMode() == V_Mode::AIR);
	assert(v_broom.getSpeed() == 20);
	assert(v_broom.getTimeToRest() == 0);
	assert(v_broom.getDistanceReductionCoeff() == (4500 / 1000));
	assert(v_broom.getFirstRestTime() == 0.0);
	assert(v_broom.getSecondRestTime() == 0.0);
	assert(v_broom.getNextRestTime() == 0.0);
}

void VehicleTests::testCamelCreate() {
	Vehicle v_camel{ V_Type::CAMEL, 1000 };
	assert(v_camel.getName() == CAMEL_NAME_RU);
	assert(v_camel.getType() == V_Type::CAMEL);
	assert(v_camel.getMode() == V_Mode::GROUND);
	assert(v_camel.getSpeed() == 10);
	assert(v_camel.getTimeToRest() == 30);
	assert(v_camel.getDistanceReductionCoeff() == 0);
	assert(v_camel.getFirstRestTime() == 5.0);
	assert(v_camel.getSecondRestTime() == 8.0);
	assert(v_camel.getNextRestTime() == 8.0);
}

void VehicleTests::testCentaurCreate() {
	Vehicle v_centaur{ V_Type::CENTAUR, 1000 };
	assert(v_centaur.getName() == CENTAUR_NAME_RU);
	assert(v_centaur.getType() == V_Type::CENTAUR);
	assert(v_centaur.getMode() == V_Mode::GROUND);
	assert(v_centaur.getSpeed() == 15);
	assert(v_centaur.getTimeToRest() == 8);
	assert(v_centaur.getDistanceReductionCoeff() == 0);
	assert(v_centaur.getFirstRestTime() == 2.0);
	assert(v_centaur.getSecondRestTime() == 2.0);
	assert(v_centaur.getNextRestTime() == 2.0);
}

void VehicleTests::testEagleCreate() {
	Vehicle v_eagle{ V_Type::EAGLE, 1000 };
	assert(v_eagle.getName() == EAGLE_NAME_RU);
	assert(v_eagle.getType() == V_Type::EAGLE);
	assert(v_eagle.getMode() == V_Mode::AIR);
	assert(v_eagle.getSpeed() == 8);
	assert(v_eagle.getTimeToRest() == 0);
	assert(v_eagle.getDistanceReductionCoeff() == 6);
	assert(v_eagle.getFirstRestTime() == 0.0);
	assert(v_eagle.getSecondRestTime() == 0.0);
	assert(v_eagle.getNextRestTime() == 0.0);
}

void VehicleTests::testFastCamelCreate() {
	Vehicle v_fast_camel{ V_Type::FAST_CAMEL, 1000 };
	assert(v_fast_camel.getName() == FAST_CAMEL_NAME_RU);
	assert(v_fast_camel.getType() == V_Type::FAST_CAMEL);
	assert(v_fast_camel.getMode() == V_Mode::GROUND);
	assert(v_fast_camel.getSpeed() == 40);
	assert(v_fast_camel.getTimeToRest() == 10);
	assert(v_fast_camel.getDistanceReductionCoeff() == 0);
	assert(v_fast_camel.getFirstRestTime() == 5.0);
	assert(v_fast_camel.getSecondRestTime() == 6.5);
	assert(v_fast_camel.getNextRestTime() == 8.0);
}

void VehicleTests::testMagicCarpetCreate() {
	Vehicle v_magic_carpet{ V_Type::MAGIC_CARPET, 1000 };
	assert(v_magic_carpet.getName() == MAGIC_CARPET_NAME_RU);
	assert(v_magic_carpet.getType() == V_Type::MAGIC_CARPET);
	assert(v_magic_carpet.getMode() == V_Mode::AIR);
	assert(v_magic_carpet.getSpeed() == 10);
	assert(v_magic_carpet.getTimeToRest() == 0);
	assert(v_magic_carpet.getFirstRestTime() == 0.0);
	assert(v_magic_carpet.getSecondRestTime() == 0.0);
	assert(v_magic_carpet.getNextRestTime() == 0.0);

	Vehicle v_magic_carpet_900{ V_Type::MAGIC_CARPET, 900 };
	assert(v_magic_carpet_900.getDistanceReductionCoeff() == 0);

	Vehicle v_magic_carpet_2500{ V_Type::MAGIC_CARPET, 2500 };
	assert(v_magic_carpet_2500.getDistanceReductionCoeff() == 3);

	Vehicle v_magic_carpet_7500{ V_Type::MAGIC_CARPET, 7500 };
	assert(v_magic_carpet_7500.getDistanceReductionCoeff() == 10);

	Vehicle v_magic_carpet_12500{ V_Type::MAGIC_CARPET, 12500 };
	assert(v_magic_carpet_12500.getDistanceReductionCoeff() == 5);
}

void VehicleTests::testAllTerrainBootsSetGetFinishTime() {
	Vehicle v_all_terrain_boots{ V_Type::ALL_TERRAIN_BOOTS, 1000 };
	v_all_terrain_boots.setFinishTime(42);
	assert(v_all_terrain_boots.getFinishTime() == 42);
}

void VehicleTests::testBroomSetGetFinishTime() {
	Vehicle v_broom{ V_Type::BROOM, 1000 };
	v_broom.setFinishTime(42);
	assert(v_broom.getFinishTime() == 42);
}

void VehicleTests::testCamelSetGetFinishTime() {
	Vehicle v_camel{ V_Type::CAMEL, 1000 };
	v_camel.setFinishTime(42);
	assert(v_camel.getFinishTime() == 42);
}

void VehicleTests::testCentaurSetGetFinishTime() {
	Vehicle v_centaur{ V_Type::CENTAUR, 1000 };
	v_centaur.setFinishTime(42);
	assert(v_centaur.getFinishTime() == 42);
}

void VehicleTests::testEagleSetGetFinishTime() {
	Vehicle v_eagle{ V_Type::EAGLE, 1000 };
	v_eagle.setFinishTime(42);
	assert(v_eagle.getFinishTime() == 42);
}

void VehicleTests::testFastCamelSetGetFinishTime() {
	Vehicle v_fast_camel{ V_Type::FAST_CAMEL, 1000 };
	v_fast_camel.setFinishTime(42);
	assert(v_fast_camel.getFinishTime() == 42);
}

void VehicleTests::testMagicCarpetSetGetFinishTime() {
	Vehicle v_magic_carpet{ V_Type::MAGIC_CARPET, 1000 };
	v_magic_carpet.setFinishTime(42);
	assert(v_magic_carpet.getFinishTime() == 42);
}

