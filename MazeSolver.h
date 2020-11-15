#pragma once
#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;

class Maze {
private:
  int *maze;
  int x;
  int y;
  int mazeSize;
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

  // finds a path in maze from start to finish, if it exists, writes it to a
  // file.
  bool writeMazeSolution(const char *);

  // returns true if coordinate is a valid coordinate withing indexing the
  // matrix.
  bool validateCoordinate(const int);

  // returns true if a is not entirely blocked
  friend bool isMoveable(const Maze &, const int);
};

Maze::Maze() {
  this->maze = nullptr;
  this->x = 0, this->y = 0, this->mazeSize = 0;
  this->solved = false;
}

// destructor
Maze::~Maze() {
  if (this->maze) {
    delete[] maze;
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
    fin >> x;
    fin >> y;
    mazeSize = x * y;

    // create maze array
    maze = new int[mazeSize]{};

    // read from file to array
    int i = 0;
    while (!fin.eof()) {
      fin >> maze[i++];
    }

    // close maze file
    fin.close();
  }

  //
  return true;
}

bool Maze::visualizeMaze() const {
  if (maze) {
    for (int i = 0; i < mazeSize; i++) {
      cout << maze[i] << "\t";
      if (i % y == 0) {
        cout << endl;
      }
    }
    return true;
  }
  return false;
}

bool Maze::writeMaze(const char *path) const {
  if (maze) {
    if (path) {
      // create file to write at path, or open to append
      fstream fout(path, ios::app | ios::out);

      // write maze dimensions to file
      fout << x << " " << y << endl;

      // write maze to file
      for (int i = 0; i < mazeSize; i++) {
        fout << maze[i];
        // if insertion is at end of row, insert new line, else insert
        // whitespace
        if ((i + 1) % y == 0) {
          fout << endl;
        } else {
          fout << " ";
        }
      }

      fout.close();
      return true;
    }
  }
  return false;
}

bool Maze::writeMazeSolution(const char *path) {
  // solve Maze, if it isnt already solved.
  bool solution = false;

  if (!this->solved) {
    solution = this->solveMaze();
  }

  // if a solution exists, write it to file at path
  if (solution) {
    this->writeMaze(path);
    return true;
  }

  fstream fout(path, ios::app | ios::out);
  fout << "PATH NOT FOUND.";
  fout.close();

  return false;
}

bool Maze::validateCoordinate(const int i) {
  // TODO: what???
  return true;
}

bool Maze::solveMaze() {

  Stack<int> path;
  int destination = mazeSize - 1;
  int currentLocation=0;

  
  return true;
}

bool isMoveable(const Maze &maze, const int location) {
  if (location < 0 && location >= maze.mazeSize) {
    return false;
  }

  const int moves[4]{location - maze.y, location + 1, location + maze.y,
                     location - 1};

  for (int i = 0; i < 4; i++) {
    // if any one of the 4 moves were are valid, return true
    if (moves[i] >= 0 && moves[i] < maze.mazeSize && maze.maze[moves[i]] == 1)
      return true;
  }

  return false;
}
