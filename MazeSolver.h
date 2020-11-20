#pragma once
#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;


/*
  MISC FUNCTIONS
*/
template<typename T>
int stackSize(Stack<T> stk){
  int i=0;
  while(!stk.empty()){
    stk.pop();
    i++;
  }
  return i;
}


/*
  struct Node is a single location in our maze indexed as (x,y).
*/
struct Node {
  int x, y;
  int direction; // 0=up, 1=right, 2=down, 3=left

  Node(const int _x = -1, const int _y = -1, const int _direction=-1) {
    x = _x, y = _y,direction = 0;
  }
  
  int getX()const{
    return x;
  }
  int getY()const{
    return 0;
  }

};

ostream& operator<<(ostream& out, const Node& obj){
 return  out<<'('<<obj.x<<','<<obj.y<<')';
}


/*
  Maze as a class.
*/
class Maze {
private:
  // maze as a 2d array
  int **maze;
  // maze dimensions
  int rows;
  int columns;
  // wether maze has been solved or not.
  bool solved;

public:
  // default constructor
  Maze();
  
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

  // finds a path in maze from start to finish
  // returns solution as an array of struct Node.
  Node *solveMaze();
};

Maze::Maze() {
  this->maze = nullptr;
  this->rows = 0, this->columns = 0;
  this->solved = false;
}

// destructor
Maze::~Maze() {
  if (this->maze) {
    // delete memory at each row
    for (int i = 0; i < this->rows; i++) {
      delete[] this->maze[i];
      this->maze[i] = nullptr;
    }
    delete[] this->maze;
    this->maze = nullptr;
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
    maze = new int *[rows] { nullptr };
    // create maze columns on each row
    for (int i = 0; i < rows; i++) {
      maze[i] = new int[columns];
    }

    // read from file to array
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
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
      for (int j = 0; j < columns; j++) {
        cout << maze[i][j] << "\t";
      }
      cout << endl;
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
      fout << rows << " " << columns << endl;

      // write maze to file
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          fout << maze[i][j] << " ";
        }
        fout << endl;
      }

      fout.close();
      return true;
    }
  }
  return false;
}

// returns a solution path as a char array
Node* Maze::solveMaze() {

  // the solution array to be returned
  Node *solution = nullptr;
  int solutionSize=0;

  // the stack for backtracking
  Stack<Node> path;

  if (maze && !solved) {
    Node top(0, 0,0);

    path.push(top);

    // if we back tracked all the way back to start, it means there was no path
    // forward, hence no solution.
    while (!path.empty()) {

      top = path.head();
      // if our latest move is our destination node, break loop.
      if (top.x == this->rows - 1 && top.y == this->columns - 1) {
        this->solved = true;
        break;
      }
      
      // update our path's top's direction by replacing it with an update Node.
      // using a nameless temporary object for that purpose.
      path.pop();
      path.push(Node(top.x, top.y, top.direction++));

      // for each direction from our path's top,
      // check if a move was valid, then make that move.

      //upwards
      if (top.direction == 0) {
        if (top.x - 1 >= 0 && maze[top.x - 1][top.y] != 0) {
          // mark current location as visited
          maze[top.x][top.y] = -1;
          // move up
          top.x--;
          // push new location to stack
          path.push(top);
        }
      }
      // rightwards
      else if (top.direction == 1) {
        if (top.y + 1 < this->columns && maze[top.x][top.y + 1] != 0) {
	  // mark current location as visited
	  maze[top.x][top.y] = -1;
	  // move right
          top.y++;
          // push new location to stack
          path.push(top);
        }
      } // downwards
      else if (top.direction == 2) {
	  if (top.x + 1 < this->rows && maze[top.x+1][top.y] != 0) {
	  // mark current location as visited
	  maze[top.x+1][top.y] = -1;
	  // move down
          top.x++;
          // push new location to stack
          path.push(top);
        }
      }
      // leftwards
      else if(top.direction==3){
	 if (top.y-1 > 0 && maze[top.x][top.y-1] != 0) {
	  // mark current location as visited
	  maze[top.x][top.y-1] = -1;
	  // move left
          top.y--;
          // push new location to stack
          path.push(top);
        }
      }
      // if no direction was moveable,
      // mark current node as blocked, and backtrack.
      else{
	maze[top.x][top.y]=0;
	// pop current location, top will now backtrack to previous visited node..
	path.pop();
      }
    }

    if (!path.empty()) {
      solutionSize=stackSize<Node>(path);
      solution=new Node[solutionSize+1];

      // Node(-1,-1-,1) is taken as array delimiter
      solution[--solutionSize]=Node();
      //
      for (int i=solutionSize-1; i>=0; i--){
	solution[i]=path.pop();
      }
    }
  }
  return solution;
}
