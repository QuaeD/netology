#include "vehicle.h"

#include <stdexcept>

Vehicle::Vehicle() = default;

Vehicle::Vehicle(const V_Type type, const int distance) : type{ type } {
	switch (type)
	{
	case V_Type::CAMEL:
		mode = V_Mode::GROUND;
		speed = 10;
		time_to_rest = 30;
		first_rest_time = 5.0;
		second_rest_time = 8.0;
		next_rest_time = 8.0;
		name = CAMEL_NAME_RU;
		break;

	case V_Type::FAST_CAMEL:
		mode = V_Mode::GROUND;
		speed = 40;
		time_to_rest = 10;
		first_rest_time = 5.0;
		second_rest_time = 6.5;
		next_rest_time = 8.0;
		name = FAST_CAMEL_NAME_RU;
		break;

	case V_Type::CENTAUR:
		mode = V_Mode::GROUND;
		speed = 15;
		time_to_rest = 8;
		first_rest_time = 2.0;
		second_rest_time = 2.0;
		next_rest_time = 2.0;
		name = CENTAUR_NAME_RU;
		break;

	case V_Type::ALL_TERRAIN_BOOTS:
		mode = V_Mode::GROUND;
		speed = 6;
		time_to_rest = 60;
		first_rest_time = 10.0;
		second_rest_time = 5.0;
		next_rest_time = 5.0;
		name = ALL_TERRAIN_BOOTS_NAME_RU;
		break;

	case V_Type::MAGIC_CARPET:
		mode = V_Mode::AIR;
		speed = 10;

		if (distance < 1000) {
			distance_reduction_coeff = 0;
		}
		else if (distance < 5000) {
			distance_reduction_coeff = 3;
		}
		else if (distance < 10000) {
			distance_reduction_coeff = 10;
		}
		else {
			distance_reduction_coeff = 5;
		}
		name = MAGIC_CARPET_NAME_RU;
		break;

	case V_Type::EAGLE:
		mode = V_Mode::AIR;
		speed = 8;
		distance_reduction_coeff = 6;
		name = EAGLE_NAME_RU;
		break;

	case V_Type::BROOM:
		mode = V_Mode::AIR;
		speed = 20;
		distance_reduction_coeff = distance / 1000;
		name = BROOM_NAME_RU;
		break;

	default:
		throw std::invalid_argument("Неверный тип транспорта!");
		break;
	}
}

const std::string& Vehicle::getName() const {
	return name;
}

const V_Type Vehicle::getType() const {
	return type;
}

const V_Mode Vehicle::getMode() const {
	return mode;
}

const int Vehicle::getSpeed() const {
	return speed;
}

const int Vehicle::getTimeToRest() const {
	return time_to_rest;
}

const int Vehicle::getDistanceReductionCoeff() const {
	return distance_reduction_coeff;
}

const double Vehicle::getFirstRestTime() const {
	return first_rest_time;
}

const double Vehicle::getSecondRestTime() const {
	return second_rest_time;
}

const double Vehicle::getNextRestTime() const {
	return next_rest_time;
}

void Vehicle::setFinishTime(const int time) {
	finish_time = time;
}

const int Vehicle::getFinishTime() const {
	return finish_time;
}
