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
  cout<<endl<<"deletion at tail: "<<cll.deleteFromTail()<<endl;
  cll.print();
  cll.insertAtTail(69);
  cll.insertFirstNode(420);
  cout<<endl<<"After new insertions: "<<endl;
  cll.print();
  cout<<endl<<"delete value 10(deleting a value somewhere between head and tail): "<<cll.deleteAValue(10)<<endl;
  cll.print();
  cout<<endl<<"delete value 69(deleting value at tail): "<<cll.deleteAValue(69)<<endl;
  cll.print();
  cout<<endl<<"delete value 420(deleeting value at head): "<<cll.deleteAValue(420)<<endl;
  cll.print();
  cout<<endl<<"delete non-existing value: "<<cll.deleteAValue(360)<<endl;
  cll.print();
  cout<<endl<<"delete value 9(empty out the list, testing circular tail case): "<<cll.deleteAValue(9)<<endl;
  return 0;
}
