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
    for (int i = 0; sol[i].x != -1; i++)
    {
      cout << sol[i];
      if (sol[i + 1].x != -1)
      {
        cout << " -> ";
      }
    }
  }
  else{
    cout<<"No solution."<<endl;
  }

  // new maze
  cout<<"New maze: "<<endl;
  m1.visualizeMaze();
  return 0;
}
