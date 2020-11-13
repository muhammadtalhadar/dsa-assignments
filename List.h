#pragma once
#include"misc.h"

template<class T>
class List
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
	void growList();

public:
	List(const int size=0);
	List(const List<T>&);
	~List();

	virtual void addElement(const T)=0;
	virtual T removeElement(const int) = 0;
};
