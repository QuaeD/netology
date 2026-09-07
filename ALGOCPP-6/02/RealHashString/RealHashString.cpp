#include <iostream>
#include <string>

uint64_t real_string_hash(const std::string& s, int p, int n) {
	uint64_t hash = 0;
	uint64_t power = 1;

	for (size_t i = 0; i < s.length(); i++) {
		hash += static_cast<uint64_t>(s[i]) * power;
		power *= p;
	}

	return hash % n;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::string str{};

	std::cout << "Введите p: ";
	int p{};
	std::cin >> p;

	std::cout << "Введите n: ";
	int n{};
	std::cin >> n;

	do {
		std::cout << "Введите строку: ";
		std::cin >> str;
		uint64_t hash = real_string_hash(str, p, n);
		std::cout << "Хэш строки " << str << " = " << hash << std::endl;
	} while (str != "exit");

	return EXIT_SUCCESS;
}
