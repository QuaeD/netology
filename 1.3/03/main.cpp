#include <iostream>
#include <string>

int main() {
	std::string gender{};
	std::string zodiac{};
	int age{};

	std::cout << "Введите пол: ";
	std::cin >> gender;
	std::cout << "Введите знак зодиака: ";
	std::cin >> zodiac;
	std::cout << "Введите возвраст: ";
	std::cin >> age;

	std::cout << "Ваше предсказание:\n";

	if (age < 40 && gender == "м" && (zodiac == "рак" || zodiac == "скорпион" || zodiac == "рыбы")) {
		std::cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.\n";
	}
	else if (age >= 15 && age <= 30 && gender == "ж" && (zodiac == "телец" || zodiac == "дева" || zodiac == "козерог")) {
		std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.\n";
		std::cout << "Будет не только весело, но и интересно: найдётся дело, которое увлечёт всех.\n";
	}
	else {
		std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)\n";
	}

	return EXIT_SUCCESS;
}