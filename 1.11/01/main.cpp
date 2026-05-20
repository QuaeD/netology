#include <iostream>
#include <string>

int main() {
	std::cout << "Введите имя: ";
	std::string name{};
	std::cin >> name;

	std::cout << "Введите фамилию: ";
	std::string surname{};
	std::cin >> surname;

	std::string name_surname = name + " " + surname;

	std::cout << "Здравствуйте, " << name_surname << "!" << std::endl;
	return EXIT_SUCCESS;
}
