#include<iostream>
#include"MazeSolver.h"
using namespace std;

int main(){
  Maze m1;
  cout<<m1.readMaze("maze.txt")<<endl;
  m1.visualizeMaze();
  cout<<m1.writeMaze("newMaze.txt")<<endl;
  return 0;
}
