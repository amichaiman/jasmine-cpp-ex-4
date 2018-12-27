//
// Created by amichai on 27/12/18.
//

#ifndef GENERIC_TREE_DEFENSEMEN_H
#define GENERIC_TREE_DEFENSEMEN_H


#include "Player.h"

class Defensemen : public Player {
public:
    virtual char getPlayerType();

    Defensemen(const Point &p, const Speed &s, int id) : Player(p,s,id){}
private:
    virtual double alpha();
    virtual double beta();
    virtual double gama();
};


#endif //GENERIC_TREE_DEFENSEMEN_H
