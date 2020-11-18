#include <initializer_list>
#include <iostream>
#include "List.h"
#include "misc.h"
#include "Stack.h"
using namespace std;

template <typename T>
int len(Stack<T> stk)
{
  int i = 0;
  while (!stk.empty())
    i++;
  return i;
}

// return the precedence of a given operator as compared to others
// 3 being highest, 1 being lowest, -1 means invalid opertor.
int opPrecedence(const char op)
{
  if (op == '^')
  {
    return 3;
  }
  else if (op == '*' or op == '/')
  {
    return 2;
  }
  else if (op == '-' or op == '+')
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

// recieves a post fix expression
char *infinixToPostfix(const char *infinix)
{
  int infinixLen = len(infinix);
  bool postfixInsertion=false;
  
  // our result as postfix expression
  int postfixLen = 0;
  char *postfix = new char[infinixLen+1]{'\0'};

  // stack to hold our operators
  Stack<char> tempStk;

  // scan each character of our infinix expression iteratively
  for (int i = 0; i < len(infinix); i++)
  {

    // skip character if it was a whitespace;
    if (infinix[i] == ' ')
    {
      continue;
    }

    // push an opening prenthesis onto our stack
    if (infinix[i] == '(')
    {
      tempStk.push(infinix[i]);
    }

    // in case of closing prenthesis,
    // pop all opeators from our stack and onto our postfix expression,
    // until our stack head is a closing prenthesis.
    else if (infinix[i] == ')')
    {
      while (!tempStk.empty() && tempStk.head() != '(')
      {
        postfix[postfixLen++] = tempStk.pop();
      }

      postfixInsertion=true;
      // pop the unmatched parenthesis from our stack
      tempStk.pop();
    }

    // if our scanned char is an operand
    // put it onto our postfix expression
    else if (infinix[i] >= '0' && infinix[i] <= '9')
    {

      // for first of two digits
      postfix[postfixLen++] = infinix[i];

      //if immediate next char was also a digit, then we have a tens number.
      //put this digit into out postfix as well
      while(infinix[i + 1] != '\0' && infinix[i + 1] >= '0' && infinix[i + 1] <= '9')
      {
        postfix[postfixLen++] = infinix[i + 1];

        // since we already scanned the next char,
        // move the iterator for infinix expression forward.
        i++;
      }
      postfixInsertion=true;
    }
    // case for when our next char is a operator
    else if (opPrecedence(infinix[i]) != -1)
    {

      if (opPrecedence(infinix[i]) > opPrecedence(tempStk.head()))
      {
	tempStk.push(infinix[i]);
      }
      else if (opPrecedence(infinix[i]) <= opPrecedence(tempStk.head()))
      {
        postfix[postfixLen++] = tempStk.pop();
        tempStk.push(infinix[i]);
      }
      postfixInsertion=true;
    }

    if(!tempStk.empty() && postfixLen!=0){
      postfix[postfixLen++]='_';
    }
    postfixInsertion=false;
  }
  return postfix;
}
int main()
{
  char infinix[] = {"(((12+13)*(20-30))/(811+99))"};

  cout << endl;
  char* postfix= infinixToPostfix(infinix);
  cout<<postfix<<endl;
  return 0;
}
