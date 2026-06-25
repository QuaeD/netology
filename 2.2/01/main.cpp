#include <iostream>

enum class Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
};

int main() {
	int month_num = -1;

	while (month_num != 0) {
		std::cout << "Введите номер месяца: ";
		std::cin >> month_num;

		if (month_num == 0) {
			std::cout << "До свидания" << std::endl;
			break;
		}

		if (month_num < 1 || month_num > 12) {
			std::cout << "Неправильный номер!" << std::endl;
			continue;
		}

		Month month = static_cast<Month>(month_num);

		switch (month)
		{
		case Month::JANUARY:
			std::cout << "Январь" << std::endl;
			break;

		case Month::FEBRUARY:
			std::cout << "Февраль" << std::endl;
			break;

		case Month::MARCH:
			std::cout << "Март" << std::endl;
			break;

		case Month::APRIL:
			std::cout << "Апрель" << std::endl;
			break;

		case Month::MAY:
			std::cout << "Май" << std::endl;
			break;

		case Month::JUNE:
			std::cout << "Июнь" << std::endl;
			break;

		case Month::JULY:
			std::cout << "Июль" << std::endl;
			break;

		case Month::AUGUST:
			std::cout << "Август" << std::endl;
			break;

		case Month::SEPTEMBER:
			std::cout << "Сентябрь" << std::endl;
			break;

		case Month::OCTOBER:
			std::cout << "Октябрь" << std::endl;
			break;

		case Month::NOVEMBER:
			std::cout << "Ноябрь" << std::endl;
			break;

		case Month::DECEMBER:
			std::cout << "Декабрь" << std::endl;
			break;

		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}