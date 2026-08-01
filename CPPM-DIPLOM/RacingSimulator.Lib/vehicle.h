#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

static const char* ALL_TERRAIN_BOOTS_NAME_RU = "Ботинки-вездеходы";
static const char* BROOM_NAME_RU = "Метла";
static const char* CAMEL_NAME_RU = "Верблюд";
static const char* CENTAUR_NAME_RU = "Кентавр";
static const char* EAGLE_NAME_RU = "Орёл";
static const char* FAST_CAMEL_NAME_RU = "Верблюд-быстроход";
static const char* MAGIC_CARPET_NAME_RU = "Ковёр-самолёт";

enum class V_Mode {
	GROUND,
	AIR,
};

enum class V_Type {
	ALL_TERRAIN_BOOTS = 1,
	BROOM,
	CAMEL,
	CENTAUR,
	EAGLE,
	FAST_CAMEL,
	MAGIC_CARPET,
};

class Vehicle
{
public:
	Vehicle();
	Vehicle(const V_Type type, const int distance);

	const std::string& getName() const;
	const V_Type getType() const;
	const V_Mode getMode() const;
	const int getSpeed() const;
	const int getTimeToRest() const;
	const int getDistanceReductionCoeff() const;
	const double getFirstRestTime() const;
	const double getSecondRestTime() const;
	const double getNextRestTime() const;

	void setFinishTime(const int time);
	const int getFinishTime() const;

private:
	V_Mode mode{};
	V_Type type{};
	int speed{ 0 };
	int time_to_rest{ 0 };
	int distance_reduction_coeff{ 0 };
	int finish_time{ 0 };
	double first_rest_time{ 0.0 };
	double second_rest_time{ 0.0 };
	double next_rest_time{ 0.0 };
	std::string name{};
};

#endif // !VEHICLE_H
