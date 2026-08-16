#include "check_utils.h"
#include "naming_utils.h"
#include "race_engine.h"

#include <iostream>

int RaceEngine::registerVehicle(Vehicle*& vehicles, int& v_count, const V_Type v_type, const int distance, const int race_type)
{
	if (static_cast<int>(v_type) == -1 || race_type == -1) {
		return -1;
	}
	if (CheckUtils::isDuplicate(vehicles, v_count, v_type)) {
		return 1;
	}

	if (CheckUtils::isVehicleModeWrong(v_type, race_type)) {
		return 2;
	}

	vehicles[v_count] = Vehicle{ v_type, distance };
	v_count++;
	return 0;
}

void RaceEngine::startRace(Vehicle*& vehicles, const int v_count, const int distance, double*& times) {
	for (int i = 0; i < v_count; i++) {
		if (vehicles[i].getMode() == V_Mode::GROUND) {
			double travel_time = static_cast<double>(distance) / vehicles[i].getSpeed();
			double total_time = travel_time;

			int rest_count{ 0 };
			if (travel_time > vehicles[i].getTimeToRest()) {
				rest_count = static_cast<int>(travel_time / vehicles[i].getTimeToRest());

				double finish_time = rest_count * vehicles[i].getTimeToRest();
				if (travel_time == finish_time) {
					rest_count--;
				}
			}
			for (int r = 0; r < rest_count; r++) {
				if (r == 0) {
					travel_time += vehicles[i].getFirstRestTime();
				}
				else if (r == 1) {
					travel_time += vehicles[i].getSecondRestTime();
				}
				else {
					travel_time += vehicles[i].getNextRestTime();
				}
			}
			times[i] = travel_time;
		}
		else {
			double corrected_distance = distance * (100.0 - vehicles[i].getDistanceReductionCoeff()) / 100.0;
			double travel_time = corrected_distance / vehicles[i].getSpeed();
			times[i] = travel_time;
		}
	}

	sortTimesVehicles(vehicles, v_count, times);
}

void RaceEngine::sortTimesVehicles(Vehicle*& vehicles, const int v_count, double*& times) {
	for (int i = 0; i < v_count - 1; i++) {
		for (int j = 0; j < v_count - i - 1; j++) {
			if (times[j] > times[j + 1]) {
				double t_temp = times[j];
				times[j] = times[j + 1];
				times[j + 1] = t_temp;

				Vehicle v_temp = vehicles[j];
				vehicles[j] = vehicles[j + 1];
				vehicles[j + 1] = v_temp;
			}
		}
	}
}
