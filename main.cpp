#include <fstream>
#include <print>
#include <string>

#include "include/maze.h"

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		auto arg = std::string(argv[i]);

		auto maze = maze::Maze();

		std::ifstream file(arg);
		std::string line;
		while (std::getline(file, line)) {
			maze.add_row(line);
		}
		file.close();
		if(maze.solve()) {
			std::println("IT IS SOLVED");
		} else {
			std::println(":(");
		}
	}
	return 0;
}
