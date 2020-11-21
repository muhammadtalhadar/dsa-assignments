#pragma once

template <typename T> class Node {
  T data_;
  T *next_;

public:
  // Constructor
  Node(T data = {}, T *next = nullptr);
  // destructor
  ~Node();

  // setters & getters
  T data()const;
  T *next()const;

  void setData(const T);
  void setNext(const T*);
};

template <typename T> Node<T>::Node(T data, T *next) {
  Node<T>::data_ = data;
  Node<T>::next_ = next;
}

template <typename T> Node<T>::~Node() { Node<T>::next_ = nullptr; }

template <typename T> T Node<T>::data() const { return Node<T>::data_; }

template <typename T> T *Node<T>::next() const { return Node<T>::next_; }

template <typename T> void Node<T>::setData(const T data) { Node<T>::data_ = data; }

template <typename T> void Node<T>::setNext(const T *next) { Node<T>::next_ = next; }
