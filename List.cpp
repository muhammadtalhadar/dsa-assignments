#include"List.h"

template<class T>
List<T>::List(const int size)
{
	if (size) {
		arr = new T[size]{};
		maxSize = size;
	}
	else {
		arr = nullptr;
		maxSize = 0;
	}
	currentSize = 0;
}

template<class T>
List<T>::List(const List<T>& rhs)
{
	if (rhs.arr) {
		deepCopy<T>(this->arr, rhs.arr, rhs.maxSize);
	}
	this->maxSize = rhs.maxSize;
	this->currentSize = rhs.currentSize;
}

template<class T>
List<T>::~List()
{
	if (this->arr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

template<class T>
void List<T>::growList()
{
	T* temp = nullptr;
	if (this->arr && this->maxSize > 0) {
		temp = new T[this->maxSize*2]{};
		for (int i = 0; i < this->currentSize; i++) {
			temp[i] = this->arr[i];
		}

		delete[] this->arr;
		this->arr = temp;
		this->maxSize = this->maxSize * 2;

	}
}