#include <iostream>
#include <fstream>

void print_arr(const int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i + 1 != size) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void dfs(bool** graph, const int size, const int vertex, bool* visited, int* order, int& order_index) {
	visited[vertex] = true;
	order[order_index++] = vertex + 1;
	for (int v = 0; v < size; v++) {
		if (graph[vertex][v]) {
			if (!visited[v]) {
				dfs(graph, size, v, visited, order, order_index);
			}
		}
	}
}

void dfs(bool** graph, const int size, int* order, int order_index) {
	bool* visited = new bool[size] {};
	for (int v = 0; v < size; v++) {
		if (!visited[v]) {
			dfs(graph, size, v, visited, order, order_index);
		}
	}

	delete[] visited;
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

	std::cout << "Порядок обхода вершин: ";

	int* order = new int[n] {};
	int order_index = 0;
	dfs(graph, n, order, order_index);

	print_arr(order, n);

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;
	delete[] order;

	return EXIT_SUCCESS;
}
