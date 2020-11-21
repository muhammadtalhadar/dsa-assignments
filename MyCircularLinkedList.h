#pragma once
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

template <class T> class MyCircularLinkedList : CircularLinkedList<T> {

public:
  // constructor
  MyCircularLinkedList();
  // destructor
  // ~MyCircularLinkedList();
  virtual void destroyCircularLinkedList() override;

  // insertion
  virtual void insertFirstNode(T) override;
  virtual void insertAtTail(T) override;

  // deletion
  virtual bool deleteAValue(T) override;
  virtual bool deleteFromTail() override;
  virtual bool deleteFirstNode() override;

  // searching
  virtual bool search(T) override;
  virtual int searchPositionOfValue(T) override;

  // sorting
  virtual void sortCircularListInAscendingOrder() override;
  virtual void sortCircularListInDescendingOrder() override;

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

template <class T> void MyCircularLinkedList<T>::insertFirstNode(T data) {

  // if CLL is empty
  if (!this->tail) {
    this->tail = new Node<T>(data);
    this->tail->setNext(this->tail);
  }
  // if CLL is not empty, locate second last element of CLL
  else {
    Node<T> *head = this->tail->next();
    while (head->next() != this->tail) {
      head = head->next();
    }
    // create new node, at as next node of second last node, and set new node's
    // next to tail.
    head->next(new Node<T>(data, this->tail));
  }
}

// visualizes MyCircularLinkedList
template <class T> void MyCircularLinkedList<T>::print() {
  if (!MyCircularLinkedList::tail) {
    cout << "NULL";
  } else {
    Node<T> *next = this->tail->next();

    while (next != this->tail) {
      cout << next->data();

      if (next->next() != this->tail) {
        cout << " -> ";
      }
    }
  }
}
