#include <iostream>
#include <string>

int find_substring_light_rabin_karp(const std::string& source, const std::string& substring) {
	for (size_t i = 0; i < source.length(); i++) {
		if (source[i] == substring[0]) {
			for (size_t j = 1; j < substring.length(), i + j < source.length(); j++) {
				if (source[i + j] != substring[j]) {
					break;
				}
				if (j + 1 == substring.length()) {
					return static_cast<int>(i);
				}
			}
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::string source{};
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> source;

	std::string substring{};
	do {
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> substring;
		int index = find_substring_light_rabin_karp(source, substring);
		if (index == -1) {
			std::cout << "Подстрока " << substring << " не найдена" << std::endl;
		}
		else {
			std::cout << "Подстрока " << substring << " найдена по индексу " << index << std::endl;
		}
	} while (substring != "exit");

	return EXIT_SUCCESS;
}
