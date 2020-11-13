#include "Stack.h"

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
