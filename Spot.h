/*Field's Spot*/
#ifndef SPOT_H
#define SPOT_H
#include "Team.h"

class Spot {
public:
	//big three:
	Spot(); //default constructor
	virtual ~Spot(); //destructor
	Spot& operator=(const Spot &rhs); //spot copy assignment operator
    int getNumOfPlayers() const ; //returns the number of the players
    bool hasPlayerInSpot(Player *player, int i, int j); //check if there's a player in the spot
    void setNumOfPlayers(int numOfPlayers); //sets the num of players as recieved 
	const Spot operator++(int); //increment operator for the number of players
	Spot& operator++(); //increment operator for the number of players
	const Spot operator--(int); //decrement operator for the number of players
	Spot& operator--(); //decrement operator for the number of players
private:
    int numOfPlayers;
};
#endif //SPOT_H
