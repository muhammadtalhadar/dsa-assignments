#pragma once
#include "List.h"
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
