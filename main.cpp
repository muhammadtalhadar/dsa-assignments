#include<iostream>
#include"MazeSolver.h"
using namespace std;

int main(){
  Maze m1;
  m1.readMaze("maze.txt");
  m1.visualizeMaze();
  cout << endl;
  return 0;
}
