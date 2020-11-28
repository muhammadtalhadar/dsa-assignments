#include <iostream>
#include"MyCircularLinkedList.h"
using namespace std;

int main(){

  MyCircularLinkedList<int> mcll;
  cout<<endl;
  mcll.print();
  cout<<endl;

  int size, num;
  cout<<"Enter size of LL: ";
  cin>>size;

  for(int i=0; i<size;i++){
    cout<<endl<<"Enter node "<<i+1<<": ";
    cin>>num;
    mcll.insertAtTail(num);
  }
  mcll.sortCircularListInDescendingOrder();

  cout<<"Sorted list: "<<endl;
    cout<<endl;
  mcll.print();
  cout<<endl;
  return 0;
}
