#include "check_utils_tests.h"
#include "naming_utils_tests.h"
#include "print_utils_tests.h"
#include "race_engine_tests.h"
#include "read_utils_tests.h"
#include "vehicle_tests.h"

#include <iostream>

int main() {
	std::cout << "Start tests..." << std::endl;

	VehicleTests::startAllTests();
	CheckUtilsTests::startAllTests();
	NamingUtilsTests::startAllTests();
	PrintUtilsTests::startAllTests();
	ReadUtilsTests::startAllTests();
	RaceEngineTests::startAllTests();

	std::cout << "Tests completed successful" << std::endl;
}