#include <iostream>
#include <string>

int simple_string_hash(const std::string& s) {
	int hash = 0;

	for (size_t i = 0; i < s.length(); i++) {
		hash += static_cast<int>(s[i]);
	}

	return hash;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	std::string str{};

	do {
		std::cout << "Введите строку: ";
		std::cin >> str;
		int hash = simple_string_hash(str);
		std::cout << "Наивный хэш строки " << str << " = " << hash << std::endl;
	} while (str != "exit");

	return EXIT_SUCCESS;
}
