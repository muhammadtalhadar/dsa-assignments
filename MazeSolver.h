#pragma once
#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;

struct Node{
	int x, y, val;
	char direction; // U,R,D,L

	Node(const int _x = 0, const int _y = 0, const int _val = 1){
		x = _x, y = _y, val = _val, direction = 'R';
	}
};

class Maze {
private:
	int **maze;
	int rows;
	int columns;
	bool solved;

public:
	// default constructor
	Maze();
	Maze(const int *);
	// destructor
	~Maze();

	// *****methods***** //

	// read and write

	// reads a file at argument path
	bool readMaze(const char *);

	// writes current maze to a file give at path(creates the file to write, if it
	// doesnt already exist.)
	bool writeMaze(const char *) const;

	// prints out the current maze to console
	bool visualizeMaze() const;

	// finds a path in maze from start to finish.
	bool solveMaze();

};

Maze::Maze() {
	this->maze = nullptr;
	this->rows = 0, this->columns = 0;
	this->solved = false;
}

// destructor
Maze::~Maze() {
	if (this->maze) {
		// delete memory at row
		for (int i = 0; i < this->rows; i++){
			delete[] maze[i];
			maze[i] = nullptr;
		}
		delete[] maze;
		maze = nullptr;
	}
}

// methods

bool Maze::readMaze(const char *path) {
	// const char* path: path of txt file where maze is to be read

	if (path) {

		// open maze file
		ifstream fin(path);
		if (!fin.is_open()) {
			return false;
		}

		// get maze dimensions (x,y) , from first line of file.
		fin >> rows;
		fin >> columns;

		// create maze rows
		maze = new int*[rows]{nullptr};
		// create maze columns on each row
		for (int i = 0; i < rows; i++){
			maze[i] = new int[columns];
		}

		// read from file to array
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < columns; j++){
				fin >> maze[i][j];
			}
		}

		// close maze file
		fin.close();
	}

	//
	return true;
}

bool Maze::visualizeMaze() const {
	if (maze) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++){
				cout << maze[i][j] << "\t";
			}
			cout << endl;
		}
		return true;
	}
	return false;
}

bool Maze::writeMaze(const char *path) const {
	//if (maze) {
	//	//if (path) {
	//	//  // create file to write at path, or open to append
	//	//  fstream fout(path, ios::app | ios::out);

	//	//  // write maze dimensions to file
	//	//  fout << x << " " << y << endl;

	//	//  // write maze to file
	//	//  for (int i = 0; i < mazeSize; i++) {
	//	//    fout << maze[i];
	//	//    // if insertion is at end of row, insert new line, else insert
	//	//    // whitespace
	//	//    if ((i + 1) % y == 0) {
	//	//      fout << endl;
	//	//    } else {
	//	//      fout << " ";
	//	//    }
	//	//  }

	//	//  fout.close();
	//	//  return true;
	//	//}
	//}
	return false;
}

bool Maze::solveMaze() {

	//Stack<Node> path;
	//int destination = mazeSize - 1;
	//int temp = 0;
	//int x = 0, y = 0;
	//Node currentNode(0, 0, 1); // location (0,0) and val=1

	//path.push(currentNode);

	//while (!path.empty()){
	//	if (currentNode.direction == 'U'){
	//		// check node above 
	//		temp = currentNode.x + currentNode.y - this->y;
	//		if (this->maze[temp] == 0){
	//			currentNode.direction = 'R';
	//		}
	//	}
	//	else if (currentNode.direction)
	//}
	return true;
}