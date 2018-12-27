/*Point*/
#include <cmath>
#include "Point.h"
#include "Speed.h"
#include "Field.h"

//default constructor
Point::Point(){}

//point copy assignment operator
Point & Point::operator=(const Point & rhs)
{
	if (&rhs == this) {
		return *this;
	}
	x = rhs.x;
	y = rhs.y;
	return *this;
}

//sum operator; adds the recieved speed to the point
Point Point::operator+(const Speed &rhs) const {
    Point newPoint;
    newPoint.x = x+rhs.speedX;
    newPoint.y = y+rhs.speedY;
	//to stay in the field limits
    if (newPoint.x < 0) {
        newPoint.x = 0;
    }
    if (newPoint.y < 0) {
        newPoint.y = 0;
    }
    if (newPoint.x > Field::FIELD_SIZE_X_PLANE) {
        newPoint.x = Field::FIELD_SIZE_X_PLANE;
    }
    if (newPoint.y > Field::FIELD_SIZE_Y_PLANE) {
        newPoint.y = Field::FIELD_SIZE_Y_PLANE;
    }
    return newPoint;
}

//sub operator between two points
Point Point::operator-(const Point &rhs) const {
    Point newPoint;
    newPoint.x = x-rhs.x;
    newPoint.y = y-rhs.y;
    return newPoint;
}

//multiplication operator; multiby the point with a recieved num
Point Point::operator*(const double &n) const {
    Point newPoint;
    newPoint.x = x*n;
    newPoint.y = y*n;

    return newPoint;
}

//create a square of n*n
double square(double n) {
    return n*n;
}

//calculating distance using the pythagorean theorem
double Point::distanceFrom(const Point &point) const {
    return sqrt(square(x-point.x) + square(y-point.y));
}

//destructor
Point::~Point(){}
