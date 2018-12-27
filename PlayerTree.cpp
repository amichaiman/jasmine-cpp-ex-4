#include "PlayerTree.h"
Player * PlayerTree::getPlayerById(int id)const {
    return getPlayerById(id, root);
}

Player * PlayerTree::getPlayerById(int id, Node<Player*> *cur)const {
    if (!cur) {
        return NULL;
    }
    if (cur->getData()->getId() == id) {
        return cur->getData();
    }
    if (id > cur->getData()->getId()) {
        return getPlayerById(id, cur->getRight());
    } else {
        return getPlayerById(id, cur->getLeft());
    }
}

PlayerTree::PlayerTree() {}

PlayerTree::PlayerTree(const Tree<Player *> &rhs) : Tree(rhs) {}

PlayerTree::~PlayerTree() { }

PlayerTree &PlayerTree::operator=(const Tree<Player *> &rhs) {
    Tree::operator=(rhs);
    return *this;
}

