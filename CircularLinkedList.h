#pragma once
#include "Node.h"

template <class T>
class CircularLinkedList
{
protected:
	Node<T>* tail;

public:
	CircularLinkedList();
	virtual void insertAtTail(T) = 0;
	virtual void insertFirstNode(T) = 0;
	// similar to insertAtHead
	virtual bool search(T) = 0;
	virtual int searchPositionOfValue(T) = 0;
	virtual bool deleteAValue(T) = 0;
	virtual bool deleteFromTail() = 0;
	virtual bool deleteFirstNode() = 0;
	virtual void sortCircularListInAscendingOrder() = 0;
	virtual void sortCircularListInDescendingOrder() = 0;
	virtual void print() = 0;
	virtual void destroyCircularLinkedList() = 0;
};

// constructor
template <class T>
CircularLinkedList<T>::CircularLinkedList()
{
	this->tail = nullptr;
}
