#include <iostream>
#include <fstream>

bool dfs(bool** graph, int size, int vertex, bool* visited, int prev_vertex) {
	visited[vertex] = true;

	for (int v = 0; v < size; v++) {
		if (graph[vertex][v] == true) {
			if (!visited[v]) {
				if (dfs(graph, size, v, visited, vertex)) {
					return true;
				}
			}
			else if (v != prev_vertex) {
				return true;
			}
		}
	}

	return false;
}

bool is_cyclic(bool** graph, int size) {
	bool* visited = new bool[size] {};

	bool has_cycle = false;

	for (int v = 0; v < size; v++) {
		if (!visited[v]) {
			if (dfs(graph, size, v, visited, -1)) {
				has_cycle = true;
				break;
			}
		}
	}

	delete[] visited;

	return has_cycle;
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

	if (is_cyclic(graph, n)) {
		std::cout << "В графе есть цикл!" << std::endl;
	}
	else {
		std::cout << "В графе нет циклов" << std::endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;

	return EXIT_SUCCESS;
}
