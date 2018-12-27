/*Player*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Point.h"
#include "Speed.h"

class Player {
public:
    Player(Point point, Speed speed, int id); //constructor to set player's location,speed & id
    Player(); //default constructor
    Player(const Player& rhs); //default constructor
	virtual ~Player(); //destructor
    Player& operator=(const Player &rhs); //copy assignment operator

    void update(const Player *globalBest); //this function updates the speed and the location of the player
	bool operator>(const Player& rhs) const;
	bool operator<(const Player& rhs) const;
    /*getters*/
	const Speed &getSpeed() const;
    const Point &getCurrentLocation() const;
    const Point &getPersonalBest() const;
    int getId() const;
    virtual char getPlayerType()=0;
private:
	//each player got an id, location, speed & personal best
    int id;
    Point currentLocation; 
    Point personalBest;
    Speed speed;
    virtual double alpha()=0;
	virtual double beta()=0;
	virtual double gama()=0;
};
#endif //PLAYER_H
