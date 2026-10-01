#include <iostream>
#include <stdexcept>

class smart_array {
public:
	smart_array(const int n) {
		arr = new int[n] {};
		index = 0;
		size = n;
	}
	~smart_array() {
		delete[] arr;
	}
	void add_element(const int el) {
		if (index == size) {
			throw std::length_error("Array is full");
		}
		arr[index++] = el;
	}
	int get_element(const int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return arr[index];
	}

private:
	int* arr;
	int index{};
	int size{};
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}