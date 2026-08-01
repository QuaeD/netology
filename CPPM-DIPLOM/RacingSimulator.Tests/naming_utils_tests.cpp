#include "naming_utils_tests.h"
#include "vehicle.h"
#include "naming_utils.h"

#include <cassert>
#include <stdexcept>

void NamingUtilsTests::startAllTests() {
	vehicleNameByTypeTest();
}

void NamingUtilsTests::vehicleNameByTypeTest() {
	assert(NamingUtils::getVehicleNameByType(V_Type::CAMEL) == CAMEL_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::FAST_CAMEL) == FAST_CAMEL_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::CENTAUR) == CENTAUR_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::ALL_TERRAIN_BOOTS) == ALL_TERRAIN_BOOTS_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::MAGIC_CARPET) == MAGIC_CARPET_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::EAGLE) == EAGLE_NAME_RU);
	assert(NamingUtils::getVehicleNameByType(V_Type::BROOM) == BROOM_NAME_RU);

	bool is_exception_throw = false;
	try {
		NamingUtils::getVehicleNameByType(static_cast<V_Type>(100));
	}
	catch (const std::invalid_argument& ex) {
		is_exception_throw = true;
	}
	assert(is_exception_throw == true);
}

