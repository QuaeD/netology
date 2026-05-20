#include <iostream>
#include <string>

int main() {
	std::string answer = "малина";
	std::string input{};

	while (input != answer) {
		std::cout << "Угадайте слово: ";
		std::cin >> input;
		if (input == answer) {
			std::cout << "Правильно! Вы победили! Загаданное слово — " << answer << std::endl;
		}
		else {
			std::cout << "Неправильно" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}