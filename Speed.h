/*Player's Speed*/
#ifndef SPEED_H
#define SPEED_H
class Point;

class Speed {
public:
	Speed(); //default constructor
	virtual ~Speed(); //destructor
	Speed& operator=(const Speed &rhs); //speed copy assignment operator
    Speed operator*(const double &n) const; //speed multiplication operator; multiby the speed with a recieved num
    Speed operator+(const Point &rhs) const; //speed sum operator; adds a recieved speed to the current one
    double speedX, speedY; //cordinates of the speed
};
#endif //SPEED_H
