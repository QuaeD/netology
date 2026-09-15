#include <iostream>
#include <fstream>

void dfs(bool** graph, int size, int vertex, int* cids, int cid) {
	cids[vertex] = cid;

	for (int v = 0; v < size; v++) {
		if (graph[vertex][v] == true && cids[v] == 0) {
			dfs(graph, size, v, cids, cid);
		}
	}
}

int find_components(bool** graph, int size, int* cids) {
	int cid = 1;

	for (int v = 0; v < size; v++) {
		if (cids[v] == 0) {
			dfs(graph, size, v, cids, cid);
			cid++;
		}
	}

	return cid - 1;
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

	int* cids = new int[n] {};

	int components_count = find_components(graph, n, cids);

	std::cout << "Принадлежность вершин компонентам связности : " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << (i + 1) << " - " << cids[i] << std::endl;
	}

	std::cout << "Количество компонентов связности в графе: " << components_count << std::endl;

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;

	return EXIT_SUCCESS;
}
