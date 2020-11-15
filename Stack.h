#pragma once
#include "List.h"
#include"ListLinker.h"

template<typename T>
class Stack :
    protected List<T>
{
private:
    //overridden methods
    void addElement(const T)override;
    T removeElement(const int)override;
public:
    Stack(const int size=0);
    Stack(const Stack<T>&);
    ~Stack();

    // class methods
    bool full()const;
    bool empty()const;
    void push(const T);
    T pop();

    int getCurrentSize()const;
    int getMaxSize()const;

    // operator
    const T& operator[](const int index)const;
    T& operator[](const int index);
};

template<typename T>
Stack<T>::Stack(const int size) : List<T>(size) {}

template<typename T>
Stack<T>::Stack(const Stack<T>& rhs) : List<T>(rhs) {}

template<typename T>
Stack<T>::~Stack() {/*implicitly calls base class destructor*/ }

template<typename T>
void Stack<T>::addElement(const T obj)
{
    if (List<T>::currentSize == List<T>::maxSize) {
        List<T>::growList();
    }
    List<T>::arr[List<T>::currentSize++] = obj;
}

template<typename T>
T Stack<T>::removeElement(const int index)
{
    T temp={};
    if (index < List<T>::currentSize) {
        temp = List<T>::arr[index];
        for (int i = index; i < List<T>::currentSize; i++) {
            List<T>::arr[i] = List<T>::arr[i + 1];
        }
        List<T>::currentSize--;
    }
    return temp;
}


template<typename T>
bool Stack<T>::full() const
{
    if (List<T>::currentSize== List<T>::maxSize) {
        return true;
    }
    return false;
}

template<typename T>
bool Stack<T>::empty() const
{
    if (List<T>::currentSize == 0) {
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::push(const T obj)
{
    addElement(obj);
}

template<typename T>
T Stack<T>::pop()
{
    return removeElement(List<T>::currentSize-1);
}

template<typename T>
int Stack<T>::getCurrentSize() const
{
    return List<T>::currentSize;
}

template<typename T>
int Stack<T>::getMaxSize() const
{
    return List<T>::maxSize;
}

template<typename T>
const T& Stack<T>::operator[](const int index)const
{
    return List<T>::arr[index];
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
    return List<T>::arr[index];
}
