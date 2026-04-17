#include <iostream>
#include <string>

int main() {
	std::cout << std::boolalpha;
	std::cout << "Оператор: ||\n";
	std::cout << true << '\t' << true << '\t' << (true || true) << std::endl;
	std::cout << false << '\t' << true << '\t' << (false || true) << std::endl;
	std::cout << true << '\t' << false << '\t' << (true || false) << std::endl;
	std::cout << false << '\t' << false << '\t' << (false || false) << std::endl;

	std::cout << "\nОператор: &&\n";
	std::cout << true << '\t' << true << '\t' << (true && true) << std::endl;
	std::cout << false << '\t' << true << '\t' << (false && true) << std::endl;
	std::cout << true << '\t' << false << '\t' << (true && false) << std::endl;
	std::cout << false << '\t' << false << '\t' << (false && false) << std::endl;

	return EXIT_SUCCESS;
}