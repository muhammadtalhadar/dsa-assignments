#include <iostream>
#include "MazeSolver.h"
using namespace std;

int main()
{
  Maze m1;
  m1.readMaze("maze.txt");
  m1.visualizeMaze();

  Node *sol = m1.solveMaze();

// expected path: (0,0),(0,1),(0,2),(1,2),(2,2),(2,3),(3,3),(3,4),(4,4)
  if (sol){
    for (int i = 0; sol[i].direction != -1; i++)
    {
      cout << sol[i];
      if (sol[i + 1].direction != -1)
      {
        cout << " -> ";
      }
    }
  }
  else{
    cout<<"No solution."<<endl;
  }
  return 0;
}
