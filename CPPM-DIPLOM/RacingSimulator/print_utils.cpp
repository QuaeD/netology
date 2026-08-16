#include "naming_utils.h"
#include "print_utils.h"

#include <iostream>
#include <stdexcept>

void PrintUtils::printRaceInfo(const int type, const int length) {
	const char* race_str = nullptr;
	switch (type)
	{
	case 1: race_str = GROUND_RACE_STR; break;
	case 2: race_str = AIR_RACE_STR; break;
	case 3: race_str = GROUND_AIR_RACE_STR; break;
	default: return;
	}
	std::cout << race_str << ". Расстояние: " << length << std::endl;
}

void PrintUtils::printRegisteredVehicles(Vehicle*& vehicles, const int v_count) {
	if (v_count == 0) return;

	std::cout << "Зарегистрированные транспортные средства: ";
	for (int i = 0; i < v_count; i++) {
		std::cout << vehicles[i].getName();
		if (i + 1 != v_count) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void PrintUtils::printVehicleMenu() {
	std::cout << "1. " << ALL_TERRAIN_BOOTS_NAME_RU << std::endl;
	std::cout << "2. " << BROOM_NAME_RU << std::endl;
	std::cout << "3. " << CAMEL_NAME_RU << std::endl;
	std::cout << "4. " << CENTAUR_NAME_RU << std::endl;
	std::cout << "5. " << EAGLE_NAME_RU << std::endl;
	std::cout << "6. " << FAST_CAMEL_NAME_RU << std::endl;
	std::cout << "7. " << MAGIC_CARPET_NAME_RU << std::endl;
	std::cout << "0. Закончить регистрацию" << std::endl;
}

void PrintUtils::printResults(Vehicle*& vehicles, const int v_count, double*& times) {
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < v_count; i++) {
		std::cout << i + 1 << ". " << NamingUtils::getVehicleNameByType(vehicles[i].getType()) << ". Время: " << times[i] << std::endl;
	}
	std::cout << std::endl;
}

void PrintUtils::clearConsole()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif // _WIN32
}

void PrintUtils::printRegistartionResult(int code, V_Type v_type)
{
	if (code == -1 || static_cast<int>(v_type) == -1) return;
	else if (code == 0) {
		std::cout << NamingUtils::getVehicleNameByType(v_type) << " успешно зарегистрирован!" << std::endl;
	}
	else if (code == 1) {
		std::cout << NamingUtils::getVehicleNameByType(v_type) << " уже зарегистрирован!" << std::endl;
	}
	else if (code == 2) {
		std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
	}
	else {
		throw std::invalid_argument("Неверный код ошибки!");
	}
}
