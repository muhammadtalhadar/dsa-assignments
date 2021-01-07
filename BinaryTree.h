//
#pragma once

#include "BinaryTreeNode.h"
#include "BinaryTreeNodeLinker.h"

template<class T>
        int largest(const int a, const int b);

template<class T>
        bool isleaf(const BinaryTreeNode<T>* node);


template<class T>
class BinaryTree {
protected:
    BinaryTreeNode<T> *root;
private:

    // methods postfixed with _inner must have public access wrapper methods
    // and are not to be called directly

    int height_inner(BinaryTreeNode<T> *node)const;

    void inorder_inner(BinaryTreeNode<T> *ptr);

    void preorder_inner(BinaryTreeNode<T> *ptr);

    void postorder_inner(BinaryTreeNode<T> *ptr);

    void insert_inner(BinaryTreeNode<T> *&node, T data);

    bool search_inner(BinaryTreeNode<T>* node, T data)const;

    int leaves_inner(BinaryTreeNode<T>* node)const;

    void mirror_inner(BinaryTreeNode<T>*& node);

    bool delete_inner(BinaryTreeNode<T>*& node, T data);

    //returns mem handle to node with min value;
    BinaryTreeNode<T>* min_inner(BinaryTreeNode<T>* node)const;

    bool balanced_inner(BinaryTreeNode<T>* node)const;
public:

    explicit BinaryTree(BinaryTreeNode<T> *root = nullptr);

    void insert(T data);

    void inorder();

    void preorder();

    void postorder();

    bool search(T data)const;

    int height()const;

    int leaves()const;

    void mirror();

    bool deletenode(T data);

    //returns a pointer to a copy of of the node with the smallest value,but child pointers are null.
    T min()const;

    bool balanced()const;
};