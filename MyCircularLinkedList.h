#pragma once
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

template <class T> class MyCircularLinkedList :public CircularLinkedList<T> {

public:
  // constructor
  MyCircularLinkedList();
  // destructor
  // ~MyCircularLinkedList();
  virtual void destroyCircularLinkedList() override{};

  // insertion
  virtual void insertFirstNode(T) override;
  virtual void insertAtTail(T) override;

  // deletion
  virtual bool deleteFromTail() override;
  virtual bool deleteFirstNode() override;
  virtual bool deleteAValue(T) override;

  // searching
  virtual bool search(T val) override{return true;}
  virtual int searchPositionOfValue(T val) override{return -1;}

  // sorting
  virtual void sortCircularListInAscendingOrder() override{}
  virtual void sortCircularListInDescendingOrder() override{}
  
  // misc
  virtual void print() override;
};

// constructor implementation - invokes default constructor of parent class
template <class T>
MyCircularLinkedList<T>::MyCircularLinkedList() : CircularLinkedList<T>() {}

// destructor implementation
// template<class T>
// MyCircularLinkedList<T>::~MyCircularLinkedList(){
//   MyCircularLinkedList<T>::destroyCircularLinkedList();
//   MyCircularLinkedList<T>::tail=nullptr;
// }



/*
  Insertion
*/

//inserts a node at start of LL
template <class T> void MyCircularLinkedList<T>::insertFirstNode(T data) {

  // if CLL is empty
  if (!this->tail) {
    this->tail = new Node<T>(data);
    this->tail->next_=this->tail;
  }
  // if CLL is not empty
  else {
    Node<T> *temp = this->tail->next_;
    this->tail->next_=new Node<T>(data, temp);
  }
}

// inserts a new node as tail
template<class T> void MyCircularLinkedList<T>::insertAtTail(T data){

  // if CLL is empty
  if(!this->tail){
    this->tail=new Node<T>(data);
    this->tail->next_=this->tail;
  }
  else{
    // backup next of tail
    Node<T>* temp=this->tail->next_;
    // insert new node at next of tail with it's next set to next of tail
    this->tail->next_=new Node<T>(data, temp);
    // move tail forward to point to new node
    this->tail=this->tail->next_;
  }
}

/*
  Deletion
*/ 

template<class T>
bool MyCircularLinkedList<T>::deleteFirstNode(){
  // if list was empty
  if(!this->tail){
    return false;
  }

  // if there was only one node
  if(this->tail->next_==this->tail){
    delete[] this->tail;
    this->tail=nullptr;
    return true;
  }
  
  Node<T>* todelete=nullptr;
  Node<T>* newFirst=nullptr;

  todelete=this->tail->next_;
  newFirst=todelete->next_;

  delete todelete;

  this->tail->next_=newFirst;

  return true;
}

template<class T>
bool MyCircularLinkedList<T>::deleteFromTail(){
  // if list is empty
  if(!this->tail){
    return false;
  }

  // if had only one Node
  if(this->tail==this->tail->next_){
    delete this->tail;
    this->tail=nullptr;
    return true;
  }

  Node<T>* head=this->tail->next_;//first element of list, pointes at by tail
  Node<T>* next=this->tail;

  // point next to second last element of list
  while(next->next_!=this->tail){
    next=next->next_;
  }

  //delete tail
  delete this->tail;

  // point tail to second last(now last) node of list
  this->tail=next;
  
  // point new tail to head
  this->tail->next_=head;
  
  return true;
}

template<class T>
bool MyCircularLinkedList<T>::deleteAValue(T data){
  if(!this->tail){
    return false;
  }

  
  return true;
}

// visualizes MyCircularLinkedList
template <class T> void MyCircularLinkedList<T>::print() {
  if (!MyCircularLinkedList::tail) {
    cout << "NULL";
  } else {
    Node<T> *next = this->tail;
    do{
      next=next->next_;
      cout<<next->data_;

      if(next!=this->tail){
        cout<<" -> ";
      }
    }while (next!=this->tail);
    
  }
}
