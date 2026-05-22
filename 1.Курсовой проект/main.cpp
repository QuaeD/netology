#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>

void printUniverse(bool** universe, int rows, int cols, int generation, int alive_cells_count) {

#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif // _WIN32

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (universe[i][j]) {
				std::cout << "*" << " ";
			}
			else {
				std::cout << "-" << " ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << "Generation: " << generation << ". Alive cells: " << alive_cells_count << std::endl << std::endl;

}

void processUniverse(bool** universe, int rows, int cols, int alive) {
	bool** next = new bool* [rows] {};
	for (int i = 0; i < rows; i++) {
		next[i] = new bool[cols] {};
	}

	int gen{};
	bool changed{};

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			next[i][j] = universe[i][j];
		}
	}

	if (alive > 0) {
		do {
			changed = false;
			printUniverse(universe, rows, cols, ++gen, alive);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {

					int alive_around_count{};

					if (i > 0 && j > 0) {
						if (universe[i - 1][j - 1]) {
							/*
							* - -
							- - -
							- - -
							*/
							alive_around_count++;
						}

					}

					if (i > 0) {
						if (universe[i - 1][j]) {
							/*
							- * -
							- - -
							- - -
							*/
							alive_around_count++;
						}
					}

					if (i > 0 && j + 1 < cols) {
						if (universe[i - 1][j + 1]) {
							/*
							- - *
							- - -
							- - -
							*/
							alive_around_count++;
						}
					}

					if (j > 0) {
						if (universe[i][j - 1]) {
							/*
							- - -
							* - -
							- - -
							*/
							alive_around_count++;
						}
					}

					if (j + 1 < cols) {
						if (universe[i][j + 1]) {
							/*
							- - -
							- - *
							- - -
							*/
							alive_around_count++;
						}
					}

					if (i + 1 < rows && j > 0) {
						if (universe[i + 1][j - 1]) {
							/*
							- - -
							- - -
							* - -
							*/
							alive_around_count++;
						}
					}

					if (i + 1 < rows) {
						if (universe[i + 1][j]) {
							/*
							- - -
							- - -
							- * -
							*/
							alive_around_count++;
						}
					}

					if (i + 1 < rows && j + 1 < cols) {
						if (universe[i + 1][j + 1]) {
							/*
							- - -
							- - -
							- - *
							*/
							alive_around_count++;
						}
					}

					if (universe[i][j]) {
						if (alive_around_count < 2 || alive_around_count > 3) {
							next[i][j] = false;
							alive--;
							changed = true;
						}
					}
					else {
						if (alive_around_count == 3) {
							next[i][j] = true;
							alive++;
							changed = true;
						}
					}
				}
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					universe[i][j] = next[i][j];
				}
			}

			std::this_thread::sleep_for(std::chrono::seconds(1));

		} while (changed && alive > 0);


		for (int i = 0; i < rows; i++) {
			delete[] next[i];
		}

		delete[] next;
	}

	gen++;
	printUniverse(universe, rows, cols, gen, alive);

	if (alive == 0) {
		std::cout << "All cells are dead. Game over" << std::endl;
	}
	else {
		std::cout << "The world has stagnated. Game over" << std::endl;
	}

}

int main() {
	std::ifstream file("in.txt");

	if (!file) {
		std::cout << "Error opening file [in.txt]" << std::endl;
		return EXIT_FAILURE;
	}

	int rows{};
	int cols{};
	file >> rows >> cols;

	bool** universe_ptr = new bool* [rows] {};
	for (int i = 0; i < rows; i++) {
		universe_ptr[i] = new bool[cols] {};
	}

	int x{};
	int y{};
	int alive{};

	while (file >> x >> y) {
		universe_ptr[x][y] = true;
		++alive;
	}

	file.close();

	processUniverse(universe_ptr, rows, cols, alive);

	for (int i = 0; i < rows; i++) {
		delete[] universe_ptr[i];
	}

	delete[] universe_ptr;

	return EXIT_SUCCESS;
}