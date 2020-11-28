#pragma once
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

template <class T>
class MyCircularLinkedList : public CircularLinkedList<T>
{
public:
	// constructor
	MyCircularLinkedList();
	// destructor
	virtual void destroyCircularLinkedList() override;

	// insertion
	virtual void insertFirstNode(T) override;
	virtual void insertAtTail(T) override;

	// deletion
	virtual bool deleteFromTail() override;
	virtual bool deleteFirstNode() override;
	virtual bool deleteAValue(T) override;

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

// destruction
template <typename T>
void MyCircularLinkedList<T>::destroyCircularLinkedList()
{
	if (this->tail)
	{
		Node<T>* head = this->tail->next_;
		Node<T>* temp = head;
		this->tail->next_ = nullptr;

		while (head)
		{
			head = head->next_;

			delete temp;

			temp = head;
		}
	}
	this->tail = nullptr;
}

/*
  Insertion
*/

// inserts a node at start of LL
template <class T>
void MyCircularLinkedList<T>::insertFirstNode(T data)
{
	// if CLL is empty
	if (!this->tail)
	{
		this->tail = new Node<T>(data);
		this->tail->next_ = this->tail;
	}
	// if CLL is not empty
	else
	{
		Node<T>* temp = this->tail->next_;
		this->tail->next_ = new Node<T>(data, temp);
	}
}

// inserts a new node as tail
template <class T>
void MyCircularLinkedList<T>::insertAtTail(T data)
{
	// if CLL is empty
	if (!this->tail)
	{
		this->tail = new Node<T>(data);
		this->tail->next_ = this->tail;
	}
	else
	{
		// backup next of tail
		Node<T>* temp = this->tail->next_;
		// insert new node at next of tail with it's next set to next of tail
		this->tail->next_ = new Node<T>(data, temp);
		// move tail forward to point to new node
		this->tail = this->tail->next_;
	}
}

/*
  Deletion
*/

template <class T>
bool MyCircularLinkedList<T>::deleteFirstNode()
{
	// if list was empty
	if (!this->tail)
	{
		return false;
	}

	// if there was only one node
	if (this->tail->next_ == this->tail)
	{
		delete[] this->tail;
		this->tail = nullptr;
		return true;
	}

	Node<T>* todelete = nullptr;
	Node<T>* newFirst = nullptr;

	todelete = this->tail->next_;
	newFirst = todelete->next_;

	delete todelete;

	this->tail->next_ = newFirst;

	return true;
}

template <class T>
bool MyCircularLinkedList<T>::deleteFromTail()
{
	// if list is empty
	if (!this->tail)
	{
		return false;
	}

	// if had only one Node
	if (this->tail == this->tail->next_)
	{
		delete this->tail;
		this->tail = nullptr;
		return true;
	}

	Node<T>* head = this->tail->next_; // first element of list, pointes at by
									   // tail
	Node<T>* next = this->tail;

	// point next to second last element of list
	while (next->next_ != this->tail)
	{
		next = next->next_;
	}

	// delete tail
	delete this->tail;

	// point tail to second last(now last) node of list
	this->tail = next;

	// point new tail to head
	this->tail->next_ = head;

	return true;
}

template <class T>
bool MyCircularLinkedList<T>::deleteAValue(T data)
{
	if (!this->tail)
	{
		return false;
	}

	// if our data was located at tail
	if (this->tail->data_ == data)
	{
		return this->deleteFromTail();
	}

	//
	Node<T>* previous = this->tail;      // the Node bhind the node to be deleted
	Node<T>* toDelete = previous->next_; // the node to be deleted

	while (toDelete != this->tail)
	{
		if (toDelete->data_ == data)
		{
			previous->next_ = toDelete->next_;
			delete toDelete;
			return true;
		}

		previous = previous->next_;
		toDelete = previous->next_;
	}
	return false;
}

// searching

template <typename T>
bool MyCircularLinkedList<T>::search(T val)
{
	if (!this->tail)
	{
		return false;
	}

	Node<T>* temp = this->tail;

	do
	{
		if (temp->data_ == val)
		{
			return true;
		}
		temp = temp->next_;
	} while (temp != this->tail);

	return false;
}

template <typename T>
int MyCircularLinkedList<T>::searchPositionOfValue(T val)
{
	if (!this->tail)
	{
		return -1;
	}

	Node<T>* temp = this->tail->next_;
	int i = 1;

	do
	{
		if (temp->data_ == val)
		{
			return i;
		}
		i += 1;
		temp = temp->next_;
	} while (temp != this->tail->next_);

	return -1;
}

// Sorting

template <typename T>
void MyCircularLinkedList<T>::sortCircularListInAscendingOrder()
{
	if (this->tail && this->tail != this->tail->next_)
	{
		Node<T>* last = this->tail;
		Node<T>* head = nullptr;
		Node<T>* next = nullptr;
		bool swapEvent = false;

		/*
		  We implement bubble sort to sort our CSLL.

		  We simulate the following bubble sort iterations for our LL;
		  for(int i=0; i<sizeOfMemory;i++) // outer loop
			  for(j=0;j<sizeOfMemory-i;j++) // inner loop

		  'last' serves as our sizeOfMemory-1 expression
		  and j=i=0=head=this->tail->next
		 */

		while (last != this->tail->next_)
		{
			head = this->tail;

			while (next != last)
			{
				// move head to start of CSLL, then forward successively.
				head = head->next_;
				next = head->next_;

				// compare and swap head's and next node's data
				if (head->data_ > next->data_)
				{
					swapNodeData(head, next);
					swapEvent = true;
				}
			}

			// if no swap occurred, break iterations
			if (!swapEvent)
			{
				break;
			}
			// reset swap flag
			swapEvent = false;

			// out head points to an Node behind the last element.
			last = head;
		}
	}
}

template <typename T>
void MyCircularLinkedList<T>::sortCircularListInDescendingOrder()
{
	if (this->tail && this->tail != this->tail->next_)
	{
		Node<T>* last = this->tail;
		Node<T>* head = nullptr;
		Node<T>* next = nullptr;
		bool swapEvent = false;

		/*
		  We implement bubble sort to sort our CSLL.

		  We simulate the following bubble sort iterations for our LL;
		  for(int i=0; i<sizeOfMemory;i++) // outer loop
			  for(j=0;j<sizeOfMemory-i;j++) // inner loop

		  'last' serves as our sizeOfMemory-1 expression
		  and j=i=0=head=this->tail->next
		 */

		while (last != this->tail->next_)
		{
			head = this->tail;

			while (next != last)
			{
				// move head to start of CSLL, then forward successively.
				head = head->next_;
				next = head->next_;

				// compare and swap head's and next node's data
				if (head->data_ < next->data_)
				{
					swapNodeData(head, next);
					swapEvent = true;
				}
			}

			// if no swap occurred, break iterations
			if (!swapEvent)
			{
				break;
			}
			// reset swap flag
			swapEvent = false;

			// out head points to an Node behind the last element.
			last = head;
		}
	}
}
// visualizes MyCircularLinkedList
template <class T>
void MyCircularLinkedList<T>::print()
{
	cout << "LINKED LIST: ";
	if (!MyCircularLinkedList::tail)
	{
		cout << "NULL";
	}
	else
	{
		Node<T>* next = this->tail;
		do
		{
			next = next->next_;
			cout << next->data_;

			if (next != this->tail)
			{
				cout << " -> ";
			}
		} while (next != this->tail);
	}
}

template <typename T>
void swapNodeData(Node<T>*& lhs, Node<T>*& rhs)
{
	if (lhs && rhs)
	{
		T temp = lhs->data_;
		lhs->data_ = rhs->data_;
		rhs->data_ = temp;
	}
}
