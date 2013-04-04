#include "Maze.h"
#include <string>

std::ostream& operator<< (std::ostream& out, const Maze& maze)
{
	for (int i = 0; i < maze.height; i++) {
		for (int j = 0; j < maze.width; j++) {
			out << maze.cell[i][j];
		}
	out << std::endl;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Maze& maze)
{
	std::string line;
	std::getline(in, line);
	for (int i = 0; i < maze.height; ++i) {
		std::getline(in , line);
		for (int j = 0; j < maze.width; ++j) {
			maze.cell[i][j] = line[j];
		}
	}

	return in;
}