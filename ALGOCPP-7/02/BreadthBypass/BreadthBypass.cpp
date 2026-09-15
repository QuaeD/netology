#include <iostream>
#include <fstream>

void bfs(bool** graph, const int size, int start_vertex) {
	bool* visited = new bool[size] {};

	int* queue = new int[size] {};
	int queue_head = 0;
	int queue_tail = 0;

	queue[queue_tail++] = start_vertex;
	visited[start_vertex] = true;

	while (queue_head < queue_tail) {
		int vertex = queue[queue_head++];

		std::cout << (vertex + 1) << " ";

		for (int i = 0; i < size; i++) {
			if (graph[vertex][i] == true && !visited[i]) {
				queue[queue_tail++] = i;
				visited[i] = true;
			}
		}
	}

	std::cout << std::endl;

	delete[] visited;
	delete[] queue;
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

	std::cout << "В графе 7 вершин. Введите номер вершины, с которой начнётся обход: ";
	int start_vertex{};
	std::cin >> start_vertex;

	bfs(graph, n, start_vertex - 1);

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}

	delete[] graph;

	return EXIT_SUCCESS;
}
