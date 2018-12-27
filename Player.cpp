/*Player*/
#include <cstdlib>
#include <iostream>
#include "Player.h"

//default construcor
Player::Player() { }

//constructor to set player's location,speed & id
Player::Player(Point point, Speed speed, int id) {
    Player::currentLocation = point;
    Player::personalBest = currentLocation;
    Player::speed = speed;
    Player::id = id;
}

 //copy assignment operator
Player &Player::operator=(const Player &rhs) {
    if (&rhs == this){
        return *this;
    }
    speed = rhs.getSpeed();
    currentLocation = rhs.getCurrentLocation();
    personalBest = rhs.getPersonalBest();
    id = rhs.getId();
    return *this;
}

//this function returns a random number
double r() {
    return static_cast<double>(rand())/RAND_MAX;
}

//this function updates the speed and the location of the player
void Player::update(const Player *globalBest) {
    Speed newSpeed = speed*0.25*alpha() + (globalBest->getCurrentLocation()-currentLocation)*r()*beta()
            + (personalBest-currentLocation)*r()*gama();
    currentLocation = currentLocation+speed;
    speed = newSpeed;
}

/*getters*/
int Player::getId() const {
    return id;
}
const Point &Player::getPersonalBest() const {
    return personalBest;
}
const Speed &Player::getSpeed() const {
    return speed;
}
const Point &Player::getCurrentLocation() const {
    return currentLocation;
}

//destructor
Player::~Player(){}

bool Player::operator>(const Player& rhs) const {
    return id > rhs.getId();
}

bool Player::operator<(const Player& rhs) const {
    return id < rhs.getId();
}

Player::Player(const Player &rhs) {
    speed = rhs.getSpeed();
    currentLocation = rhs.getCurrentLocation();
    personalBest = rhs.getPersonalBest();
    id = rhs.getId();
}


