#include <iostream>
#include <string>

struct Address
{
	std::string town = "";
	std::string street = "";
	int house_number = 0;
	int apartment_number = 0;
	int postal_code = 0;
};

void printAddress(Address& address) {
	std::cout << "Город: " << address.town << std::endl;
	std::cout << "Улица: " << address.street << std::endl;
	std::cout << "Номер дома: " << address.house_number << std::endl;
	std::cout << "Номер квартиры: " << address.apartment_number << std::endl;
	std::cout << "Индекс: " << address.postal_code << std::endl;
}

int main() {
	Address addr_1{
		.town = "Москва",
		.street = "Арбат",
		.house_number = 12,
		.apartment_number = 8,
		.postal_code = 123456
	};

	Address addr_2{
		.town = "Ижевск",
		.street = "Пушкина",
		.house_number = 59,
		.apartment_number = 143,
		.postal_code = 953769
	};

	printAddress(addr_1);
	std::cout << std::endl;
	printAddress(addr_2);

	return EXIT_SUCCESS;
}