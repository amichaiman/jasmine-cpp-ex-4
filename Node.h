//
// Created by amichai on 20/12/18.
//

#ifndef GENERIC_TREE_NODE_H
#define GENERIC_TREE_NODE_H

#include <cstdio>
#include <iostream>

template <typename Type>
class Node {
public:
    Node(Type data); //c'tor
    Node(const Node& rhs); //copy c'tor
    Node<Type>& operator=(const Node<Type>& rhs); //copy operator
    virtual ~Node();

    Type getData() const;
    void setData(Type data);
    Node<Type> *getRight() const;
    void setRight(Node<Type> *right);
    Node<Type> *getLeft() const;
    void setLeft(Node<Type> *left);
    bool isLeaf();
    void *getSon(Node<Type> *son);
    void setSon(Node<Type> *son, Node<Type>* newSon);
    int getNumberOfChildren();
    Node<Type> *getOnlySon();


private:
    Type data;
    Node<Type> *left;
    Node<Type> *right;
};

template<typename Type>
Type Node<Type>::getData() const {
    return data;
}

template<typename Type>
void Node<Type>::setData(Type data) {
    Node<Type>::data = data;
}

template<typename Type>
Node<Type> *Node<Type>::getRight() const {
    return right;
}

template<typename Type>
Node<Type> *Node<Type>::getLeft() const {
    return left;
}

template<typename Type>
void Node<Type>::setLeft(Node<Type> *left) {
    Node<Type>::left = left;
}

template<typename Type>
void Node<Type>::setRight(Node<Type> *right) {
    Node<Type>::right = right;
}

template<typename Type>
Node<Type>::Node(Type data):data(data), left(NULL), right(NULL) { }

template<typename Type>
bool Node<Type>::isLeaf() {
    return left == NULL && right == NULL;
}

template<typename Type>
void *Node<Type>::getSon(Node<Type> *son) {
    if (right == son) {

        return right;
    }
    return NULL;
}

template<typename Type>
void Node<Type>::setSon(Node<Type> *son, Node<Type>* newSon) {
    if (right == son) {
        right = newSon;
    } else {
        left = newSon;
    }
}

template<typename Type>
int Node<Type>::getNumberOfChildren() {
    return !!left + !!right;
}

template<typename Type>
Node<Type> *Node<Type>::getOnlySon() {
    return right ? right : left;
}

template<typename Type>
Node<Type>::~Node() {
    delete data;
}

template<typename Type>
Node<Type>::Node(const Node &rhs) {
    data = rhs.getData();
    right = rhs.getRight();
    left = rhs.getLeft();
}

template<typename Type>
Node<Type> &Node<Type>::operator=(const Node<Type> &rhs) {
    if (&rhs == this) {
        return *this;
    }
    data = rhs.getData();
    right = rhs.getRight();
    left = rhs.getLeft();
    return *this;
}


#endif //GENERIC_TREE_NODE_H
