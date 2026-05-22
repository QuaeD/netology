#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream file("in.txt");

	if (!file.is_open()) {
		std::cout << "Ошибка при открытии файла [in.txt]" << std::endl;
		return EXIT_FAILURE;
	}

	std::string str{};

	while (!(file >> str).eof()) {
		std::cout << str << std::endl;
	}

	file.close();

	return EXIT_SUCCESS;
}