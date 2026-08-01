#include "naming_utils.h"

#include <stdexcept>

const std::string NamingUtils::getVehicleNameByType(const V_Type type)
{
	if (type == V_Type::CAMEL) {
		return CAMEL_NAME_RU;
	}
	else if (type == V_Type::FAST_CAMEL) {
		return FAST_CAMEL_NAME_RU;
	}
	else if (type == V_Type::CENTAUR) {
		return CENTAUR_NAME_RU;
	}
	else if (type == V_Type::ALL_TERRAIN_BOOTS) {
		return ALL_TERRAIN_BOOTS_NAME_RU;
	}
	else if (type == V_Type::MAGIC_CARPET) {
		return MAGIC_CARPET_NAME_RU;
	}
	else if (type == V_Type::EAGLE) {
		return EAGLE_NAME_RU;
	}
	else if (type == V_Type::BROOM) {
		return BROOM_NAME_RU;
	}
	else {
		throw std::invalid_argument("Неизвестный тип транспорта");
	}
}
