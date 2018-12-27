#ifndef GENERIC_TREE_PLAYERTREE_H
#define GENERIC_TREE_PLAYERTREE_H


#include "Tree.h"
#include "Player.h"

class PlayerTree : public Tree<Player*>{
public:
    PlayerTree();
    explicit PlayerTree(const Tree<Player *> &rhs);
    PlayerTree& operator=(const Tree<Player *> &rhs);
    virtual ~PlayerTree();
    Player * getPlayerById(int id)const;
private:
    Player * getPlayerById(int id, Node<Player*> *cur)const;
};
#endif //GENERIC_TREE_PLAYERTREE_H
