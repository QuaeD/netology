#include <iostream>
#include <fstream>
#include <string>

class Address
{
public:
	Address() = default;

	Address(const std::string_view town, const std::string_view street, const int house_number, const int appartment) : town{ town }, street{ street }, house_number{ house_number }, appartment{ appartment }
	{
	}

	std::string getTown() const {
		return town;
	}

	std::string getStreet() const {
		return street;
	}

	int getHouseNum() const {
		return house_number;
	}

	int getAppartment() const {
		return appartment;
	}

private:
	std::string town{};
	std::string street{};
	int house_number{};
	int appartment{};
};

Address* readFile(std::ifstream& in_file, int& size) {
	in_file >> size;

	Address* addresses = new Address[size];

	for (int i = 0; i < size; i++) {
		std::string town{};
		std::string street{};
		int house_number{};
		int appartment{};

		in_file >> town;
		in_file >> street;
		in_file >> house_number;
		in_file >> appartment;

		Address address = Address(town, street, house_number, appartment);
		addresses[i] = address;
	}

	return addresses;
}

void writeFile(std::ofstream& out_file, const Address addresses[], const int size) {
	out_file << size << std::endl;

	for (int i = size - 1; i >= 0; i--) {
		out_file <<
			addresses[i].getTown() << ", " <<
			addresses[i].getStreet() << ", " <<
			addresses[i].getHouseNum() << ", " <<
			addresses[i].getAppartment();

		if (i != 0) {
			out_file << std::endl;
		}
	}
}

int main() {
	std::ifstream in_file("in.txt");

	if (!in_file.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return EXIT_FAILURE;
	}

	int size{};
	Address* addresses = readFile(in_file, size);
	in_file.close();

	std::ofstream out_file("out.txt");
	if (!out_file.is_open()) {
		std::cout << "Error creating or opening out.txt for writing!" << std::endl;
		return EXIT_FAILURE;
	}

	writeFile(out_file, addresses, size);
	out_file.close();

	delete[] addresses;

	return EXIT_SUCCESS;
}