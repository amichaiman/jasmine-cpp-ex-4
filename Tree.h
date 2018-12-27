//
// Created by amichai on 20/12/18.
//

#ifndef GENERIC_TREE_TREE_H
#define GENERIC_TREE_TREE_H


#include <iostream>
#include <climits>
#include "Node.h"
using namespace std;

template <typename Type>
class Tree {
public:
    Tree();
    Tree(const Tree<Type>& rhs);

    virtual Tree<Type>& operator=(const Tree<Type>& rhs);
    virtual ~Tree();
    void insert(Type type);
    void print();
    Node<Type>* search(Type data);
    Node<Type>* min();
    Node<Type>* max();
    void clear();
    void remove(Type data);
    int getNumOfNodes();

    Node<Type> *getRoot() const;

private:
    Node<Type> * addToTree(Type data, Node<Type> *cur);
    void print(Node<Type> *cur);
    Node<Type> * search(Node<Type> *cur, Type data);
    Node<Type>* min(Node<Type> *cur);
    Node<Type>* max(Node<Type> *cur);
    void clearTree(Node<Type> *cur);
    Node<Type> * remove(Type data, Node<Type>* root);
    Node<Type> *getParent(Node<Type> *cur, Type data);
    int getNumOfNodes(Node<Type> *cur);

protected:
    Node<Type> *root;
};

template<typename Type>
void Tree<Type>::insert(Type type) {
    root = addToTree(type, root);
}

template<typename Type>
Node<Type>* Tree<Type>::addToTree(Type data, Node<Type> *cur) {
    if (!cur) {
        return new Node<Type>(data);
    }
    if (*data > *(cur->getData())) {
        cur->setRight(addToTree(data, cur->getRight()));
    } else if (*data < *(cur->getData())){
        cur->setLeft(addToTree(data, cur->getLeft()));
    } else {
        cur->setData(data);
    }
    return cur;
}

template<typename Type>
Tree<Type>::Tree() {
    root = NULL;
}

template<typename Type>
void Tree<Type>::print() {
    print(root);
}

template<typename Type>
void Tree<Type>::print(Node<Type> *cur) {
    if (!cur) {
        return;
    }
    print(cur->getLeft());
    std::cout << cur->getData() << endl;
    print(cur->getRight());
}

template<typename Type>
Node<Type>* Tree<Type>::min() {
    return min(root);
}

template<typename Type>
Node<Type>* Tree<Type>::search(Type data) {
    return search(root, data);
}

template<typename Type>
Node<Type>* Tree<Type>::search(Node<Type> *cur, Type data) {
    if (!cur) {
        return NULL;
    }
    if (cur->getData() == data) {
        return cur;
    }
    if (*data > *(cur->getData())) {
        return search(cur->getRight(), data);
    } else {
        return search(cur->getLeft(), data);
    }
}

template<typename Type>
Node<Type>* Tree<Type>::min(Node<Type> *cur) {
    if (!cur) {
        return NULL;
    }
    if (!cur->getLeft()) {
        return cur;
    }
    return min(cur->getLeft());
}

template<typename Type>
Node<Type>* Tree<Type>::max() {
    return max(root);
}

template<typename Type>
Node<Type>* Tree<Type>::max(Node<Type> *cur) {
    if (!cur) {
        return NULL;
    }
    if (!cur->getRight()) {
        return cur;
    }
    return max(cur->getRight());
}

template<typename Type>
Tree<Type>::~Tree() {
    clearTree(root);
}

template<typename Type>
void Tree<Type>::clearTree(Node<Type> *cur) {
    if (!cur) {
        return;
    }
    if (cur->isLeaf()) {
        delete cur;
        return;
    }
    clearTree(cur->getLeft());
    clearTree(cur->getRight());
    delete cur;
}


template<typename Type>
void Tree<Type>::clear() {
    clearTree(root);
    root = NULL;
}

template<typename Type>
int Tree<Type>::getNumOfNodes() {
    return getNumOfNodes(root);
}

template<typename Type>
void Tree<Type>::remove(Type data) {
    root = remove(data, root);
}


template<typename Type>
Node<Type>* Tree<Type>::remove(Type data, Node<Type>* root) {
    Node<Type> *toRemove = search(root, data);
    if (!toRemove) {
        return root;
    }
    if (toRemove->isLeaf()) {
        Node<Type> *parent = getParent(root, data);
        if (!parent) {
            delete toRemove;
            return NULL;
        }
        parent->setSon(toRemove, NULL);
        delete toRemove;
        return root;
    }
    if (toRemove->getNumberOfChildren() == 1) {
        Node<Type> *parent = getParent(root, data);
        if (!parent) {
            Node<Type>* onlySon = toRemove->getOnlySon();
            delete toRemove;
            return onlySon;
        }
        parent->setSon(toRemove, toRemove->getOnlySon());
        delete toRemove;
        return root;
    }
    Node<Type> *successor = min(toRemove->getRight());
    Type temp = toRemove->getData();
    toRemove->setData(successor->getData());
    successor->setData(temp);
    toRemove->setRight(remove(data, toRemove->getRight()));
    return root;
}

template<typename Type>
Node<Type> *Tree<Type>::getParent(Node<Type> *cur, Type data) {
    if (!cur || cur->isLeaf()) {
        return NULL;
    }
    if (*data > *(cur->getData())) {
        if (cur->getRight() && cur->getRight()->getData() == data) {
            return cur;
        }
        return getParent(cur->getRight(), data);
    } else {
        if (cur->getLeft() && cur->getLeft()->getData() == data) {
            return cur;
        }
        return getParent(cur->getLeft(), data);
    }
}

template<typename Type>
int Tree<Type>::getNumOfNodes(Node<Type> *cur) {
    if (!cur) {
        return 0;
    }
    return getNumOfNodes(cur->getRight()) + getNumOfNodes(cur->getLeft()) + 1;
}

template<typename Type>
Tree<Type> &Tree<Type>::operator=(const Tree<Type> &rhs) {
    if (&rhs == this) {
        return *this;
    }
    root = rhs.getRoot();
    return *this;
}

template<typename Type>
Node<Type> *Tree<Type>::getRoot() const {
    return root;
}

template<typename Type>
Tree<Type>::Tree(const Tree<Type> &rhs) {
    root = rhs.getRoot();
}

#endif //GENERIC_TREE_TREE_H
