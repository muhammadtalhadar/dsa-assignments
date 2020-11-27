#include<iostream>
#include"MyCircularLinkedList.h"

using namespace std;

int main(){
  cout<<"\t========== Driver Code ========== "<<endl<<endl;

  MyCircularLinkedList<int> cll;
  cll.insertAtTail(10);
  cll.insertFirstNode(9);
  cll.insertAtTail(11);
  cll.insertFirstNode(8);
  cll.print();
  cout<<endl<<"deletion of first: "<<cll.deleteFirstNode()<<endl;
  cll.print();
  return 0;
}
