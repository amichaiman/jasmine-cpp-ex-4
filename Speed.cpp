/*Player's Speed*/
#include "Speed.h"
#include "Point.h"

//default constructor
Speed::Speed(){}

//copy assignment operator for a recieved speed
Speed & Speed::operator=(const Speed & rhs)
{
	if (&rhs == this) {
		return *this;
	}
	speedX = rhs.speedX;
	speedY = rhs.speedY;
	return *this;
}
//speed multiplication operator; multipy the speed with a recieved number
Speed Speed::operator*(const double &n) const {
    Speed newSpeed;
    newSpeed.speedX = speedX*n;
    newSpeed.speedY = speedY*n;
    return newSpeed;
}
//speed sum operator; adds a recieved speed to the current one
Speed Speed::operator+(const Point &rhs) const {
    Speed newSpeed;
    newSpeed.speedX = speedX + rhs.x;
    newSpeed.speedY = speedY + rhs.y;
    return newSpeed;
}

//destructor
Speed::~Speed(){}
