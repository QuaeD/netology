#include <iostream>
#include <string>

struct BankAccount
{
	int number = 0;
	double balance = 0.0;
	std::string owner_name = "";
};

void setBalance(BankAccount& account, double new_balance) {
	account.balance = new_balance;
}

int main() {
	BankAccount account{};

	std::cout << "Введите номер счёта: ";
	std::cin >> account.number;

	std::cout << "Введите имя владельца: ";
	std::cin >> account.owner_name;

	std::cout << "Введите баланс: ";
	std::cin >> account.balance;

	double new_balance{};
	std::cout << "Введите новый баланс: ";
	std::cin >> new_balance;

	setBalance(account, new_balance);

	std::cout
		<< "Ваш счёт: "
		<< account.owner_name << ", "
		<< account.number << ", "
		<< account.balance
		<< std::endl;

	return EXIT_SUCCESS;
}