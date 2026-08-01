#include "print_utils_tests.h"
#include "print_utils.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

void PrintUtilsTests::startAllTests() {
	printRaceInfoTest();
	printRegisteredVehiclesTest();
	printVehicleMenuTest();
	printResultsTest();
	printRegistrationResultTest();
}

void PrintUtilsTests::printRaceInfoTest() {
	std::streambuf* original_buffer = std::cout.rdbuf();
	std::stringstream test_output;
	std::cout.rdbuf(test_output.rdbuf());

	PrintUtils::printRaceInfo(1, 1000);
	assert(test_output.str() == (std::string(GROUND_RACE_STR) + ". Расстояние: 1000\n"));
	test_output.str("");
	test_output.clear();

	PrintUtils::printRaceInfo(2, 1000);
	assert(test_output.str() == (std::string(AIR_RACE_STR) + ". Расстояние: 1000\n"));
	test_output.str("");
	test_output.clear();

	PrintUtils::printRaceInfo(3, 1000);
	assert(test_output.str() == (std::string(GROUND_AIR_RACE_STR) + ". Расстояние: 1000\n"));
	test_output.str("");
	test_output.clear();

	PrintUtils::printRaceInfo(4, 1000);
	assert(test_output.str().empty());

	std::cout.rdbuf(original_buffer);
}

void PrintUtilsTests::printRegisteredVehiclesTest() {
	Vehicle* vehicles = new Vehicle[7]{
		{ V_Type::BROOM, 1000},
		{ V_Type::ALL_TERRAIN_BOOTS, 1000},
		{ V_Type::CAMEL, 1000},
		{ V_Type::CENTAUR, 1000},
		{ V_Type::EAGLE, 1000},
		{ V_Type::FAST_CAMEL, 1000},
		{ V_Type::MAGIC_CARPET, 1000}
	};

	std::streambuf* original_buffer = std::cout.rdbuf();
	std::stringstream test_output;
	std::cout.rdbuf(test_output.rdbuf());

	PrintUtils::printRegisteredVehicles(vehicles, 0);
	assert(test_output.str().empty());
	test_output.str("");
	test_output.clear();

	PrintUtils::printRegisteredVehicles(vehicles, 7);
	std::string result = 
		std::string("Зарегистрированные транспортные средства: ") +
		BROOM_NAME_RU + ", " +
		ALL_TERRAIN_BOOTS_NAME_RU + ", " +
		CAMEL_NAME_RU + ", " +
		CENTAUR_NAME_RU + ", " +
		EAGLE_NAME_RU + ", " +
		FAST_CAMEL_NAME_RU + ", " +
		MAGIC_CARPET_NAME_RU + "\n";

	assert(test_output.str() == result);

	delete[] vehicles;

	std::cout.rdbuf(original_buffer);
}

void PrintUtilsTests::printVehicleMenuTest() {
	std::streambuf* original_buffer = std::cout.rdbuf();
	std::stringstream test_output;
	std::cout.rdbuf(test_output.rdbuf());

	PrintUtils::printVehicleMenu();
	std::string result =
		std::string("1. ") + ALL_TERRAIN_BOOTS_NAME_RU + "\n" +
		"2. " + BROOM_NAME_RU + "\n" +
		"3. " + CAMEL_NAME_RU + "\n" +
		"4. " + CENTAUR_NAME_RU + "\n" +
		"5. " + EAGLE_NAME_RU + "\n" +
		"6. " + FAST_CAMEL_NAME_RU + "\n" +
		"7. " + MAGIC_CARPET_NAME_RU + "\n" +
		"0. Закончить регистрацию\n";

	assert(test_output.str() == result);

	std::cout.rdbuf(original_buffer);
}

void PrintUtilsTests::printResultsTest() {
	std::streambuf* original_buffer = std::cout.rdbuf();
	std::stringstream test_output;
	std::cout.rdbuf(test_output.rdbuf());

	int v_count = 7;

	Vehicle* vehicles = new Vehicle[v_count]{
		{ V_Type::BROOM, 1000},
		{ V_Type::ALL_TERRAIN_BOOTS, 1000},
		{ V_Type::CAMEL, 1000},
		{ V_Type::CENTAUR, 1000},
		{ V_Type::EAGLE, 1000},
		{ V_Type::FAST_CAMEL, 1000},
		{ V_Type::MAGIC_CARPET, 1000}
	};

	double* times = new double[v_count] {
		4.0, 
		2.0, 
		50.0, 
		20.0, 
		77.5, 
		1.0,
		5.7
		};

	PrintUtils::printResults(vehicles, v_count, times);

	std::string result =
		std::string("Результаты гонки:\n") +
		"1. " + BROOM_NAME_RU + ". Время: 4\n" +
		"2. " + ALL_TERRAIN_BOOTS_NAME_RU + ". Время: 2\n" +
		"3. " + CAMEL_NAME_RU + ". Время: 50\n" +
		"4. " + CENTAUR_NAME_RU + ". Время: 20\n" +
		"5. " + EAGLE_NAME_RU + ". Время: 77.5\n" +
		"6. " + FAST_CAMEL_NAME_RU + ". Время: 1\n" +
		"7. " + MAGIC_CARPET_NAME_RU + ". Время: 5.7\n\n";

	assert(test_output.str() == result);

	delete[] vehicles;

	std::cout.rdbuf(original_buffer);
}

void PrintUtilsTests::printRegistrationResultTest() {
	std::streambuf* original_buffer = std::cout.rdbuf();
	std::stringstream test_output;
	std::cout.rdbuf(test_output.rdbuf());

	PrintUtils::printRegistartionResult(-1, V_Type::CAMEL);
	assert(test_output.str().empty());
	test_output.str("");
	test_output.clear();

	PrintUtils::printRegistartionResult(0, V_Type::CAMEL);
	assert(test_output.str() == std::string(CAMEL_NAME_RU) + " успешно зарегистрирован!\n");
	test_output.str("");
	test_output.clear();

	PrintUtils::printRegistartionResult(0, V_Type::CAMEL);
	assert(test_output.str() == std::string(CAMEL_NAME_RU) + " успешно зарегистрирован!\n");
	test_output.str("");
	test_output.clear();

	PrintUtils::printRegistartionResult(1, V_Type::CAMEL);
	assert(test_output.str() == std::string(CAMEL_NAME_RU) + " уже зарегистрирован!\n");
	test_output.str("");
	test_output.clear();

	PrintUtils::printRegistartionResult(2, V_Type::CAMEL);
	assert(test_output.str() == std::string("Попытка зарегистрировать неправильный тип транспортного средства!\n"));
	test_output.str("");
	test_output.clear();

	bool is_exception_throw = false;
	try {
		PrintUtils::printRegistartionResult(3, V_Type::CAMEL);
	}
	catch (const std::invalid_argument& ex) {
		is_exception_throw = true;
	}
	assert(is_exception_throw == true);

	std::cout.rdbuf(original_buffer);
}