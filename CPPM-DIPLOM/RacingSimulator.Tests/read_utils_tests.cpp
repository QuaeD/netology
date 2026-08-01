#include "read_utils_tests.h"
#include "read_utils.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

void ReadUtilsTests::startAllTests() {
	tryReadUserNumberTest();
}

void ReadUtilsTests::tryReadUserNumberTest() {
	std::streambuf* original_buffer = std::cin.rdbuf();

	std::stringstream test_input("0");
	std::cin.rdbuf(test_input.rdbuf());

	int result = ReadUtils::tryReadUserNumber(4, 10);
	assert(result == -1);

	test_input.clear();
	test_input.str("5");
	std::cin.rdbuf(test_input.rdbuf());

	result = ReadUtils::tryReadUserNumber(4, 10);
	assert(result == 5);

	test_input.clear();
	test_input.str("test");
	std::cin.rdbuf(test_input.rdbuf());

	result = ReadUtils::tryReadUserNumber(4, 10);
	assert(result == -1);

	test_input.clear();
	test_input.str("10000000000000000000");
	std::cin.rdbuf(test_input.rdbuf());

	result = ReadUtils::tryReadUserNumber(4, 10);
	assert(result == -1);

	test_input.clear();
	test_input.str("test_test_test_test_test");
	std::cin.rdbuf(test_input.rdbuf());

	result = ReadUtils::tryReadUserNumber(4, 10);
	assert(result == -1);

	std::cin.rdbuf(original_buffer);
}
