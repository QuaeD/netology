#include <iostream>
#include <fstream>

void dfs(bool** graph, int size, int vertex, bool* visited, int* order, int& order_index) {
	visited[vertex] = true;

	for (int v = 0; v < size; v++) {
		if (graph[vertex][v] == true && !visited[v]) {
			dfs(graph, size, v, visited, order, order_index);
		}
	}

	order[order_index++] = vertex;
}

int* topological_sort(bool** graph, int size) {
	bool* visited = new bool[size] {};

	int* order = new int[size] {};
	int order_index = 0;

	for (int v = 0; v < size; v++) {
		if (!visited[v]) {
			dfs(graph, size, v, visited, order, order_index);
		}
	}

	delete[] visited;

	return order;
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

	int* order = topological_sort(graph, n);

	std::cout << "Топологический порядок вершин: ";
	for (int i = n - 1; i >= 0; i--) {
		std::cout << (order[i] + 1) << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;
	delete[] order;

	return EXIT_SUCCESS;
}
