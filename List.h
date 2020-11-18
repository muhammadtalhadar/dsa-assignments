#pragma once
#include "misc.h"

template <class T>
class List
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
	void growList();

public:
	List(const int size = 0);
	List(const List<T> &);
	~List();

	virtual void addElement(const T) = 0;
	virtual T removeElement(const int) = 0;
};

template <class T>
List<T>::List(const int size)
{
	if (size)
	{
		this->arr = new T[size]{};
		this->maxSize = size;
	}
	else
	{
		this->arr = nullptr;
		this->maxSize = 0;
	}
	this->currentSize = 0;
}

template <class T>
List<T>::List(const List<T> &rhs)
{
	if (rhs.arr)
	{
		deepCopy<T>(this->arr, rhs.arr, rhs.maxSize);
	}
	this->maxSize = rhs.maxSize;
	this->currentSize = rhs.currentSize;
}

template <class T>
List<T>::~List()
{
	if (this->arr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
}

template <class T>
void List<T>::growList()
{
	T *temp = nullptr;
	if (!this->arr && this->maxSize == 0)
	{
		temp = new T[++this->maxSize]{};
		this->arr = temp;
	}
	else
	{
		temp = new T[this->maxSize * 2]{};
		for (int i = 0; i < this->currentSize; i++)
		{
			temp[i] = this->arr[i];
		}

		delete[] this->arr;
		this->arr = temp;
		this->maxSize = this->maxSize * 2;
	}
}
