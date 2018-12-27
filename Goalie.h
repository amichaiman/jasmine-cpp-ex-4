//
// Created by amichai on 27/12/18.
//

#ifndef GENERIC_TREE_GOALIE_H
#define GENERIC_TREE_GOALIE_H


#include "Player.h"

class Goalie : public Player{
public:
    Goalie(const Point &p, const Speed &s, int id) : Player(p,s,id){}

    virtual char getPlayerType();

private:
    virtual double alpha();
    virtual double beta();
    virtual double gama();
};


#endif //GENERIC_TREE_GOALIE_H
