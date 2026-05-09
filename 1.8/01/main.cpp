#include <iostream>

void counting_function() {
	static int count{};
	++count;
	std::cout << "Количество вызовов функции counting_function(): " << count << '\n';
}

int main() {
	for (int i = 0; i < 15; i++)
	{
		counting_function();
	}

	return EXIT_SUCCESS;
}