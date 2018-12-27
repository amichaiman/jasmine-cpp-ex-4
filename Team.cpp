/*Players Team*/
#include <iostream>
#include <climits>
#include "Team.h"
using namespace std;

//default construcor
Team::Team(){}

//returns false if number of players exceeded the max or the min number, else sets the number of players as recived and returns true. 
bool Team::setNumOfPlayers(const int numOfPlayers) {
    if (numOfPlayers < MIN_PLAYERS || numOfPlayers > MAX_PLAYERS){
        return false;
    }
    Team::numOfPlayers = numOfPlayers;
    return true;
}

//sets the player i in the array of players as recived
void Team::setPlayer(Player *player, int i) {
    players.insert(player);
}

//this function prints the players locations
void Team::printPlayersLocations() {
    for (int i=0; i<numOfPlayers; i++){
        cout << players.getPlayerById(i)->getPlayerType() << " " << players.getPlayerById(i)->getCurrentLocation().x << " " <<  players.getPlayerById(i)->getCurrentLocation().y;
        if (i != numOfPlayers-1) {
            cout << endl;
        }
    }
}

//this function updates the team by updating the global best player
void Team::update() {
    updateGlobalBestPlayerId(); //update the global best player id among all of the players
    for (int i=0; i<numOfPlayers; i++){
        players.getPlayerById(i)->update(players.getPlayerById(globalBestPlayerId));
    }
}

//copy assignment operator for a recieved team
Team & Team::operator=(const Team & rhs) {
	if (&rhs == this) {
		return *this;
	}
	numOfPlayers = rhs.getNumberOfPlayers();
	players = rhs.getPlayers();
	globalBestPlayerId=rhs.getGlobalBestPlayerId();
	destinationPoint=rhs.getDestinationPoint();
	return *this;
}

const PlayerTree &Team::getPlayers() const {
    return players;
}

//this function updates the best player id 
void Team::updateGlobalBestPlayerId() {
    double shortestDistanceFromDestination = INT_MAX;
    double currentDistanceFromDestination;
    for (int i=0; i<numOfPlayers; i++){
        currentDistanceFromDestination = players.getPlayerById(i)->getCurrentLocation().distanceFrom(destinationPoint);
		/*if the current distance of the player from the destination is lower then the shortest one,
		then update it, and update this player to be th global best*/
        if (currentDistanceFromDestination < shortestDistanceFromDestination) {
            shortestDistanceFromDestination = currentDistanceFromDestination;
            globalBestPlayerId = i;
        }
    }
}

//sets the destination point as recived
void Team::setDestinationPoint(Point destinationPoint) {
    Team::destinationPoint = destinationPoint;
}

//returns player i in the array of players
Player *Team::getPlayer(int i) const{
    return players.getPlayerById(i);
}

/*getters*/
int Team::getGlobalBestPlayerId() const {
	return globalBestPlayerId;
}
const Point &Team::getDestinationPoint() const{
	return destinationPoint;
}
int Team::getNumberOfPlayers() const{
    return numOfPlayers;
}

//destructor
Team::~Team(){ }
