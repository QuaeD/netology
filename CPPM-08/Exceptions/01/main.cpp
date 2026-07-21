#include <iostream>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length) {
	if (str.length() == static_cast<int>(forbidden_length)) {
		throw std::length_error("Вы ввели слово запретной длины!");
	}
	return static_cast<int>(str.length());
}

int main() {
	std::cout << "Введите запретную длину: ";
	int forbidden_length{};
	std::cin >> forbidden_length;

	while (true)
	{
		std::cout << "Введите слово: ";
		std::string word{};
		std::cin >> word;
		try {
			int length = function(word, forbidden_length);
			std::cout << "Длина слова \"" << word << "\" равна " << length << std::endl;
		}
		catch (const std::length_error& ex) {
			std::cout << ex.what() << " До свидания" << std::endl;
			break;
		}
	}

	return EXIT_SUCCESS;
}