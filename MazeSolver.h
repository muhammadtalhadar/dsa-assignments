#pragma once
#include <iostream>
#include<fstream>
#include"misc.h"

using namespace std;

class Maze{
 private:
  char* maze;
  int x;
  int y;
 public:

  // default constructor
  Maze(const char* path, const char delim){
    // path: path of txt file where maze is to be read from
    // delim: character to be considered as a blocked path

    char temp;
    
    if(path){

      // opeth maze file
      ifstream fin(path);
      if(!fin.is_open()){
	cout<<"File not found."<<endl;
	exit(0);
      }

      // get maze dimensions (x,y) , from first line of file.
      fin>>x;
      fin>>y;

      int mazeSize=x*y;
      // create maze array
      maze=new char[mazeSize];
      
      // read from file to array
      int i=0;
      while(!fin.eof()){
	fin>>maze[i++];
      }
    }
    else{
      this->maze=nullptr;
      this->x=0, this->y=0;
    }
  }
  
  // destructor
  ~Maze(){
    if(this->maze){
      delete[] maze;
    }
    
  };
};
