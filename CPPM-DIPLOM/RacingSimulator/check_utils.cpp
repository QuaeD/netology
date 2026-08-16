#include "check_utils.h"

const bool CheckUtils::isDuplicate(Vehicle*& vehicles, const int v_count, const V_Type type) {
	for (int i = 0; i < v_count; i++) {
		if (vehicles[i].getType() == type) {
			return true;
		}
	}
	return false;
}

const bool CheckUtils::isVehicleModeWrong(const V_Type type, const int race_type) {
	if (race_type == 1) {
		if (type == V_Type::MAGIC_CARPET ||
			type == V_Type::EAGLE ||
			type == V_Type::BROOM) {
			return true;
		}
	}
	else if (race_type == 2) {
		if (type == V_Type::CAMEL ||
			type == V_Type::FAST_CAMEL ||
			type == V_Type::CENTAUR ||
			type == V_Type::ALL_TERRAIN_BOOTS) {
			return true;
		}
	}
	return false;
}
