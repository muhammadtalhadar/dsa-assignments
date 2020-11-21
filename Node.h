#pragma once

template <typename T> class Node {
  T data_;
  Node *next_;

public:
  // Constructor
  Node(T data = {}, Node<T> *next = nullptr);
  // destructor
  ~Node();

  // setters & getters
  T data()const;
  Node<T> *next()const;

  void setData(T);
  void setNext(Node<T>*);
};

template <typename T> Node<T>::Node(T data, Node *next) {
  Node<T>::data_ = data;
  Node<T>::next_ = next;
}

template <typename T> Node<T>::~Node() { Node<T>::next_ = nullptr; }

template <typename T> T Node<T>::data() const { return Node<T>::data_; }

template <typename T> Node<T> *Node<T>::next() const { return Node<T>::next_; }

template <typename T> void Node<T>::setData( T data) { Node<T>::data_ = data; }

template <typename T> void Node<T>::setNext( Node<T> *next) { Node<T>::next_ = next; }
