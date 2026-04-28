#include <iostream>

void powerAndPrint(int value, int power, int result) {
	for (int i = 0; i < power; i++) {
		result *= value;
	}

	std::cout << value << " в степени " << power << " = " << result << std::endl;
}

int main() {
	int value = 5;
	int power = 2; 
	int result = 1;
	
	powerAndPrint(value, power, result);

	value = 3;
	power = 3;
	result = 1;
	
	powerAndPrint(value, power, result);

	value = 4;
	power = 4;
	result = 1;

	powerAndPrint(value, power, result);

	return EXIT_SUCCESS;
}