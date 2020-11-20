#include <iostream>
#include "MazeSolver.h"
#include "InfinixToPostfix.h"
using namespace std;

void printPathOfNodes(const Node *);

int main()
{

  /*
    Driver code for Question 1.
  */
  cout << endl
       << endl
       << "=============== Driver code for Question 1 ===============" << endl
       << endl;

  char infinix[] = {"(((12+13)*(20-30))/(811+99))"};
  cout << "-- Infinix Expression: " << infinix << endl
       << endl;

  char *postfix = infinixToPostfix(infinix);
  cout << "-- Equivalent Postfix Expression: " << postfix << endl;

  /*
    Driver code for Question 2.
  */

  cout << endl
       << endl
       << "=============== Driver code for Question 1 ===============" << endl
       << endl;

  Maze m1;
  m1.readMaze("input.txt");

  cout << "\t-- Original Maze --" << endl;
  m1.visualizeMaze();
  cout << endl;

  Node *sol = m1.solveMaze();

  // if solution was not empty, print it.
  if (sol)
  {
    cout << "Solution Path: ";
    printPathOfNodes(sol);
    cout << endl
         << endl;
  }
  else
  {
    cout << "No solution." << endl;
  }

  // print solved maze.
  cout << "\t--Solved Maze --" << endl;
  m1.visualizeMaze();
  // write solced maze to file.
  m1.writeMaze("output.txt");

  cout << endl
       << "=============== THE END ===============" << endl;
  return 0;
}

void printPathOfNodes(const Node *path)
{
  if (path)
  {

    for (int i = 0; path[i].x != -1; i++)
    {
      cout << path[i];
      if (path[i + 1].x != -1)
      {
        cout << " -> ";
      }
    }
  }
}