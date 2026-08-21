#include <iostream>

int Foo(const int* arr, const int size, const int point) {
    if (arr == nullptr || size <= 0) return 0;

    int left = 0;
    int right = size - 1;
    int result = size;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= point) {
            left = mid + 1;
        }
        else {
            result = mid;
            right = mid - 1;
        }
    }

    return size - result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Введите точку отсчёта: ";
    int point{};
    std::cin >> point;

    int arr[] = { 14, 16, 19, 32, 32, 32, 54, 69, 72 };

    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << Foo(arr, 9, point) << std::endl;
}
