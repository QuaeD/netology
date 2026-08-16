#include "check_utils.h"
#include "naming_utils.h"
#include "print_utils.h"
#include "race_engine.h"
#include "read_utils.h"
#include "vehicle.h"

#include <iostream>
#include <limits>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");

	Vehicle* vehicles = new Vehicle[7]{};

	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

	int next_action{ -1 };
	do {
		int race_type{ -1 };

		do {
			std::cout << "1. " << GROUND_RACE_STR << std::endl;
			std::cout << "2. " << AIR_RACE_STR << std::endl;
			std::cout << "3. " << GROUND_AIR_RACE_STR << std::endl;
			std::cout << "Выберите тип гонки: ";

			race_type = ReadUtils::tryReadUserNumber(1, 3);

			if (race_type == -1) {
				PrintUtils::clearConsole();
				std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
			}
		} while (race_type == -1);

		PrintUtils::clearConsole();

		int distance{ -1 };
		do {
			std::cout << "Укажите длину дистанции (должна быть положительна): ";
			distance = ReadUtils::tryReadUserNumber(1, std::numeric_limits<int>::max());
			if (distance == -1) {
				PrintUtils::clearConsole();
				std::cout << "Неверная длина дистанции!!!" << std::endl;
			}
		} while (distance <= 0);

		PrintUtils::clearConsole();

		int action{ -1 };
		int v_count{ 0 };

		do {
			if (v_count < 2) {
				PrintUtils::clearConsole();
				std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
			}
			std::cout << "1. Зарегистрировать транспорт" << std::endl;
			if (v_count >= 2) {
				std::cout << "2. Начать гонку" << std::endl;
			}

			std::cout << "Выберите действие: ";

			if (v_count < 2) {
				action = ReadUtils::tryReadUserNumber(1, 1);
			}
			else {
				action = ReadUtils::tryReadUserNumber(1, 2);
			}

			if (action == -1 || (action == 2 && v_count < 2)) {
				PrintUtils::clearConsole();
				continue;
			}
			else if (action == 2 && v_count >= 2) {
				break;
			}

			int vehicle_type{ -1 };
			int reg_code{ -1 };
			do {
				PrintUtils::clearConsole();
				PrintUtils::printRegistartionResult(reg_code, static_cast<V_Type>(vehicle_type));
				PrintUtils::printRaceInfo(race_type, distance);
				PrintUtils::printRegisteredVehicles(vehicles, v_count);
				PrintUtils::printVehicleMenu();

				std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

				vehicle_type = ReadUtils::tryReadUserNumber(0, 7);

				if (vehicle_type == -1) {
					continue;
				}

				if (vehicle_type == 0) {
					break;
				}

				reg_code = RaceEngine::registerVehicle(vehicles, v_count, static_cast<V_Type>(vehicle_type), distance, race_type);

			} while (v_count != 7);
			PrintUtils::clearConsole();
		} while (true);

		PrintUtils::clearConsole();

		double* times = new double[v_count] {};
		RaceEngine::startRace(vehicles, v_count, distance, times);
		PrintUtils::printResults(vehicles, v_count, times);

		delete[] times;
		v_count = 0;

		do {
			std::cout << "1. Провести еще одну гонку" << std::endl;
			std::cout << "2. Выйти" << std::endl;
			std::cout << "Выберите действие: ";
			next_action = ReadUtils::tryReadUserNumber(1, 2);
			if (next_action == -1) {
				PrintUtils::clearConsole();
			}
		} while (next_action != 1 && next_action != 2);
		PrintUtils::clearConsole();
	} while (next_action != 2);

	delete[] vehicles;

	return EXIT_SUCCESS;
}