#include <iostream>

namespace sum {
	int calc(int x, int y) {
		return x + y;
	}
}

namespace diff {
	int calc(int x, int y) {
		return x - y;
	}
}
namespace mult {
	int calc(int x, int y) {
		return x * y;
	}
}
namespace division {
	int calc(int x, int y) {
		return x / y;
	}
}

int main() {
	int x = 6;
	int y = 9;

	std::cout << "x = " << x << ", y = " << y << '\n';
	std::cout << "Сложение: " << sum::calc(x, y) << '\n';
	std::cout << "Вычитание: " << diff::calc(x, y) << '\n';
	std::cout << "Умножение: " << mult::calc(x, y) << '\n';
	std::cout << "Деление: " << division::calc(x, y) << '\n';

	return EXIT_SUCCESS;
}