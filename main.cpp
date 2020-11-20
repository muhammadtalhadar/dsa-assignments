#include<iostream>
#include"MazeSolver.h"
using namespace std;


int main(){
  Maze m1;
  m1.readMaze("maze.txt");
  m1.visualizeMaze();

  Node* sol=m1.solveMaze();

  for(int i=0; sol[i].direction!=-1;i++){
    cout<<sol[i];
    if(sol[i+1].direction!=-1){
      cout<<" -> ";
    }
  }
  return 0;
}
