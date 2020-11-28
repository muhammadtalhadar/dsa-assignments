#pragma once

template <typename T>
struct Node
{
  T data_;
  Node *next_;

public:
  // Constructor
  Node(T data = {}, Node<T> *next = nullptr);
  // destructor
  ~Node();
};

template <typename T>
Node<T>::Node(T data, Node<T> *next)
{
  this->data_ = data;
  this->next_ = next;
}

template <typename T>
Node<T>::~Node()
{
  this->next_ = nullptr;
}
