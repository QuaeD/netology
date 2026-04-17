#include <iostream>
#include <string>

std::string getNumberAsText(int number) {
	std::string number_str{};
	if (number < 0) {
		number_str = "минус ";
		number = 0 - number;
	}

	if (number == 100) {
		return number_str + "сто";
	}

	if (number > 9 && number < 20) {
		number_str +=
			number == 10 ? "десять" :
			number == 11 ? "одиннадцать" :
			number == 12 ? "двенадцать" :
			number == 13 ? "тринадцать" :
			number == 14 ? "четырнадцать" :
			number == 15 ? "пятнадцать" :
			number == 16 ? "шестнадцать" :
			number == 17 ? "семнадцать" :
			number == 18 ? "восемнадцать" : "девятнадцать";

		return number_str;
	}

	int tens = number / 10;
	int units = number % 10;

	if (tens != 0) {
		number_str +=
			tens == 2 ? "двадцать" :
			tens == 3 ? "тридцать" :
			tens == 4 ? "сорок" :
			tens == 5 ? "пятьдесят" :
			tens == 6 ? "шестьдесят" :
			tens == 7 ? "семьдесят" :
			tens == 8 ? "восемьдесят" : "девяносто";

		if (units != 0) {
			number_str += " ";
		}
	}


	number_str +=
		units == 0 ? "ноль" :
		units == 1 ? "один" :
		units == 2 ? "два" :
		units == 3 ? "три" :
		units == 4 ? "четыре" :
		units == 5 ? "пять" :
		units == 6 ? "шесть" :
		units == 7 ? "семь" :
		units == 8 ? "восемь" : "девять";

	return number_str;
}

int main() {
	int number_1{};
	int number_2{};

	std::cout << "Введите целое число: ";
	std::cin >> number_1;
	std::cout << "Введите целое число: ";
	std::cin >> number_2;

	if (number_1 < -100 || number_1 > 100 || number_2 < -100 || number_2 > 100) {
		std::cout << "Ошибка! Одно из чисел вне диапазона!" << std::endl;
		return EXIT_SUCCESS;
	}

	std::string number_1_str = getNumberAsText(number_1);
	std::string number_2_str = getNumberAsText(number_2);

	if (number_1 < number_2) {
		std::cout << number_1_str << " меньше чем " << number_2_str << std::endl;
	}
	else if (number_1 > number_2) {
		std::cout << number_1_str << " больше чем " << number_2_str << std::endl;
	}
	else {
		std::cout << number_1_str << " равно " << number_2_str << std::endl;
	}


	return EXIT_SUCCESS;
}