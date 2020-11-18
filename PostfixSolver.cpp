#include <initializer_list>
#include<iostream>
#include "List.h"
#include"misc.h"
#include"Stack.h"
using namespace std;

template<typename T>
int len(Stack<T> stk){
  int i=0;
  while(!stk.empty()) i++;
  return i;
}

// return the precedence of a given operator as compared to others
// 3 being highest, 1 being lowest, -1 means invalid opertor.
int opPrecedence(const char op){
  if(op=='^'){
    return 3;
  }
  else if(op=='*' or op=='/'){
    return 2;
  }
  else if(op=='-' or op=='+'){
    return 1;
  }
  else{
    return -1;
  }
}

// recieves a post fix expression 
char* infinixToPostfix(const char* infinix){

  int infinixLen=len(infinix);

  int postfixLen=0;
  char* postfix=new char[infinixLen]{'\0'};

  int tempArrLen=0;
  char* tempArr=new char[infinixLen]{'\0'};
  
  Stack<char> tempStk;
  
  for(int i=0; i<len(infinix);i++){
    if(infinix[i]=='('){
      tempStk.push(infinix[i]);
    }
    else if(infinix[i]==')'){
      while(tempStk.head()!='('){
	
      }
    }
  }
  return postfix;
}
int main(){
  return 0;
}
