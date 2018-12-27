/*Field's Spot*/
#include "Spot.h"

//default constructor
Spot::Spot(){}

//this funtion returns true if there's a player in the spot
bool Spot::hasPlayerInSpot(Player *player, int i, int j) {
	//check if the player's location is into the spot limits
    return player->getCurrentLocation().y >= i &&
           player->getCurrentLocation().y < i+1 &&
           player->getCurrentLocation().x >= j &&
           player->getCurrentLocation().x < j+1;
}

//increases the number of players
const Spot Spot::operator++(int) {
    numOfPlayers++;
    return *this;
}
//decreases the number of players
const Spot Spot::operator--(int) {
    numOfPlayers--;
    return *this;
}

//copy assignment operator for a recieved spot 
Spot & Spot::operator=(const Spot & rhs)
{
	if (&rhs == this) {
		return *this;
	}
	numOfPlayers = rhs.getNumOfPlayers();
	return *this;
}

//gets the number of players
int Spot::getNumOfPlayers() const {
    return numOfPlayers;
}
//sets the number of player as recieved
void Spot::setNumOfPlayers(int numOfPlayers) {
    Spot::numOfPlayers = numOfPlayers;
}

//destructor
Spot::~Spot(){}

Spot &Spot::operator++() {
    numOfPlayers++;
    return *this;
}

Spot &Spot::operator--() {
    numOfPlayers--;
    return *this;
}
