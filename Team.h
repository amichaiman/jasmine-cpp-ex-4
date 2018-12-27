/*Players Team*/
#ifndef TEAM_H
#define TEAM_H
#include "PlayerTree.h"

class Team {
public:
	//big three
	Team(); //default constructor
	virtual ~Team(); //destructor
	Team& operator=(const Team &rhs); //copy assignment operator
    static const int MAX_PLAYERS = 100;
    static const int MIN_PLAYERS = 2;
    void update(); //updates the team by updating the global best player
	bool setNumOfPlayers(int numOfPlayers);//returns false if number of players exceeded the max or the min number, else sets the number of players as recived and returns true. 
    void setPlayer(Player *player, int i);//sets the player i in the array of players as recived
    void printPlayersLocations(); //this function prints the players locations
	void setDestinationPoint(Point destinationPoint);//sets the destination point as recived
    Player * getPlayer(int i) const; //returns the player i  in the players array
    /*getters*/
	int getNumberOfPlayers() const;
	int getGlobalBestPlayerId() const;
	const Point &getDestinationPoint() const;

    const PlayerTree &getPlayers() const;

private:
    int numOfPlayers;
    PlayerTree players;
    int globalBestPlayerId;
    void updateGlobalBestPlayerId(); //this function updates the best player id 
    Point destinationPoint;
};


#endif //TEAM_H
