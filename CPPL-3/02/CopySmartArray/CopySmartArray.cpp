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
	int get_size() const {
		return size;
	}
	smart_array(const smart_array& other) : arr(new int[other.size]), index(other.index), size(other.size) {
		for (int i = 0; i < other.index; i++) {
			arr[i] = other.arr[i];
		}
	}

	smart_array& operator=(const smart_array other) {
		if (this == &other) {
			return *this;
		}

		int* new_arr = new int[other.size] {};
		for (int i = 0; i < other.index; i++) {
			new_arr[i] = other.arr[i];
		}
		
		delete[] arr;
		arr = new_arr;
		size = other.size;
		index = other.index;
		return *this;
	}
private:
	int* arr;
	int index{};
	int size{};
};

int main() {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;
	
	return EXIT_SUCCESS;
}