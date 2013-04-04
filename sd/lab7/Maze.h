#ifndef __MAZE_H__
#define __MAZE_H__

#include <iostream>
#include <fstream>

class Maze {

private:

	int height, width;
	char** cell;

public:

	/** 
	* Constructor.
	* width Latimea labirintului (nr. coloane)
	* height Inaltimea labirintului (nr. linii)
	*/
	Maze(int height, int width) : height(height), width(width) {
		cell = new char*[height];
		for (int i = 0; i < height; i++) {
			cell[i] = new char[width];
			for (int j = 0; j < width; j++) {
				cell[i][j] = '#';
			}
		}
	}

	/**
	* Destructor.
	*/
	~Maze() {
		
		if (cell != NULL) {
			for (int i = 0; i < height; i++) {
				delete[] cell[i];
			}
		delete[] cell;
		cell = NULL;
		}
	}

	/** 
	* Functie pentru determinarea latimii labirintului.
	*/
	int get_width() {
		return width;
	}

	/** 
	* Functie pentru determinarea inaltimii labirintului.
	*/
	int get_height() {
		return height;
	}

	/**
	* Functie care spune daca o celula din labirint este accesibila.
	* line Linia din labirint.
	* column Coloana din labirint.
	*/
	bool is_walkable(int line, int column) {
		if (line >= 0 && line < height && column >= 0 && column < width) {
			return cell[line][column] != '#';
		} else {
			return false;
		}
	}


	friend std::istream& operator>> (std::istream&, Maze& maze);
	friend std::ostream& operator<< (std::ostream&, const Maze&);
};

#endif

