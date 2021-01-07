#include <iostream>
#include "BinaryTree.h"


template<class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *root):root(root) {}

// insert data
template<class T>
void BinaryTree<T>::insert_inner(BinaryTreeNode<T> *&node, T data) {

    //base case
    if (node == nullptr) {
        node = new BinaryTreeNode<T>(data);
    }


    //general cases
    if (data < node->data) {
        insert_inner(node->lnode, data);
    } else if(data>node->data){
        insert_inner(node->rnode, data);
    }
}
template<class T>
void BinaryTree<T>::insert(T data) {
    insert_inner(this->root, data);
}

// preorder_inner
template<class T>
void BinaryTree<T>::preorder_inner(BinaryTreeNode<T> *ptr) {
    if (ptr) {
        std::cout << ptr->data << " ";
        preorder_inner(ptr->lnode);
        preorder_inner(ptr->rnode);
    }
}

template<class T>
void BinaryTree<T>::preorder() {
    preorder_inner(this->root);
}

//inorder_inner
template<class T>
void BinaryTree<T>::inorder_inner(BinaryTreeNode<T> *ptr) {
    if (ptr) {
        inorder_inner(ptr->lnode);
        std::cout << ptr->data << " ";
        inorder_inner(ptr->rnode);
    }
}
template<class T>
void BinaryTree<T>::inorder() {
    inorder_inner(this->root);
}

// print postorder_inner
template<class T>
void BinaryTree<T>::postorder_inner(BinaryTreeNode<T> *ptr) {
    if (ptr) {
        postorder_inner(ptr->lnode);
        postorder_inner(ptr->rnode);
        std::cout << ptr->data << " ";
    }
}
template<class T>
void BinaryTree<T>::postorder() {
    postorder_inner(this->root);
}

//
template<class T>
bool BinaryTree<T>::search_inner(BinaryTreeNode<T> *node, T data)const {

    // base case
    if(node == nullptr) return false;

    // positive result case
    if(node->data==data) return true;

    // general case
    if(data<node->data){
        return search_inner(node->lnode, data);
    }
    else{
        return search_inner(node->rnode, data);
    }
}

//wrapper method
template<class T>
bool BinaryTree<T>::search(T data) const {
    return search_inner(this->root, data);
}

//
template<class T>
int BinaryTree<T>::height_inner(BinaryTreeNode<T> *node) const{
    if (node == nullptr) {
        return 0;
    }

    return 1+largest<T>(height_inner(node->lnode), height_inner(node->rnode));
}

//wrapper method
template<class T>
int BinaryTree<T>::height() const {
    return height_inner(this->root);
}


// counts leaf nodes in a BST
template<class T>
int BinaryTree<T>::leaves_inner(BinaryTreeNode<T> *node) const {
    // base case
    if(node==nullptr) return 0;

    // positive result case
    if(node->rnode== nullptr && node->lnode==nullptr){
        return 1;
    }
        //general case
    else{
        return leaves_inner(node->lnode) + leaves_inner(node->rnode);
    }
}

//wrapper method
template<class T>
int BinaryTree<T>::leaves() const {
    return leaves_inner(this->root);
}

template<class T>
void BinaryTree<T>::mirror() {
    mirror_inner(this->root);
}

template<class T>
void BinaryTree<T>::mirror_inner(BinaryTreeNode<T> *& node) {
    if(node){
        BinaryTreeNode<T>* temp;

        mirror_inner(node->lnode);
        mirror_inner(node->rnode);

        temp=node->lnode;
        node->lnode=node->rnode;
        node->rnode=temp;
    }
    else{
        return;
    }
}

template<class T>
bool BinaryTree<T>::delete_inner(BinaryTreeNode<T> *&node, T data) {

    // base case
    if(node==nullptr) return false;

    //positive result cases
    BinaryTreeNode<T>* temp= nullptr;
    if(node->data==data){
        // when both subtrees are empty
        if(node->lnode==nullptr && node->rnode== nullptr){
            delete node;
            node= nullptr;
        }
        //where left subtree is empty
        else if(node->lnode==nullptr){
            temp=node->rnode;
            delete node;
            node=temp;
        }
        //when right subtree is empty
        else if(node->rnode==nullptr){
            temp=node->lnode;
            delete node;
            node=temp;
        }
        // when neither subtree is empty
        else{
            BinaryTreeNode<T>* predecessor=node->lnode;
            temp=nullptr;

            // locate the predecessor to node to be deleted
            while(predecessor->rnode!= nullptr){
                temp=predecessor;
                predecessor=predecessor->rnode;
            }

            //update node to delete's data with predecessor's data
            node->data=predecessor->data;

            // update predecessor's original parent and delete predecessor from it's original position.
            if(temp==nullptr){ // incase, predecessor was node->lnode and no iteration was done
                node->lnode=predecessor->lnode;
            }
            else{
                temp->rnode=predecessor->lnode;
            }
            delete predecessor;
        }
        return true;
    }

    //general case
    if(data<node->data){
        return delete_inner(node->lnode, data);
    }
    else{
        return delete_inner(node->rnode, data);
    }
}

template<class T>
bool BinaryTree<T>::deletenode(T data) {
    return delete_inner(this->root, data);
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::min_inner(BinaryTreeNode<T> *node) const {
    if(node->lnode==nullptr){
        return node;
    }
    else{
        return min_inner(node->lnode);
    }
}

template<class T>
T BinaryTree<T>::min() const {
    return min_inner(this->root)->data;
}

template<class T>
bool BinaryTree<T>::balanced_inner(BinaryTreeNode<T>* node)const {

    if(node==nullptr) return 1;

    int subtreeHeightDifference=(height_inner(node->rnode) - height_inner(node->lnode));
    //int subtreeHeightDifferenceAbsolute= subtreeHeightDifference % (subtreeHeightDifference * 2);
    int subtreeHeightDifferenceAbsolute=abs(subtreeHeightDifference);

    if(subtreeHeightDifferenceAbsolute <=1) return true;

    return false;
}

template<class T>
bool BinaryTree<T>::balanced() const {
    return balanced_inner(this->root);
}

// returns the larger of two integers
template<class T>
int largest(const int a, const int b) {
    if(a>=b) return a;
    return b;
}

template<class T>
bool isleaf(const BinaryTreeNode<T> *node) {
    return (node->rnode== nullptr && node->lnode==nullptr);
}
