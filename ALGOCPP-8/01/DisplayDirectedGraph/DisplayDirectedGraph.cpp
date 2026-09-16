#include <iostream>
#include <fstream>

void print_graph(bool** graph, int size) {
	std::cout << "Текстовый вид орграфа: " << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << (i + 1) << ": ";
		
		bool has_edges = false;

		for (int j = 0; j < size; j++) {
			if (graph[i][j] == 1) {
				std::cout << (j + 1) << " ";
				has_edges = true;
			}
		}

		if (!has_edges) {
			std::cout << "нет";
		}

		std::cout << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::ifstream in_file("input.txt");

	if (!in_file.is_open()) {
		std::cout << "Ошибка при открытии файла!" << std::endl;
		in_file.close();
		return EXIT_FAILURE;
	}

	int n{};
	in_file >> n;

	bool** graph = new bool* [n] {};

	for (int i = 0; i < n; i++) {
		graph[i] = new bool[n] {};
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int value{};
			in_file >> value;
			graph[i][j] = (value == 1);
		}
	}

	in_file.close();

	print_graph(graph, n);

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;

	return EXIT_SUCCESS;
}
