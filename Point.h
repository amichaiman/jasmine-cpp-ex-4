/*Point*/
#ifndef POINT_H
#define POINT_H
class Speed;

class Point {
public:
	Point(); //default constructor
	virtual ~Point(); //destructor
	Point& operator=(const Point &rhs); //point copy assignment operator
    double x,y;
    Point operator+(const Speed &rhs) const; //sum operator; adds the recieved speed to the point
    Point operator-(const Point &rhs) const; //sub operator between two points
    Point operator*(const double &n) const; //multiplication operator; multiby the point with a recieved num
    double distanceFrom(const Point& point) const; //calculating distance using the pythagorean theorem
};
#endif //POINT_H
