/*Game Field*/
#ifndef FIELD_H
#define FIELD_H
#include "Point.h"
#include "Spot.h"
#include "Team.h"

class Field {
public:
    Field(); //default constructor
	virtual ~Field(); //destructor
	Field& operator=(const Field &rhs); //field copy assignment operator
    //field size is 61*30
	static const int FIELD_SIZE_X_PLANE = 61;
    static const int FIELD_SIZE_Y_PLANE = 30;
    void setGoalDestination(const Point &goalDestination); //sets the goal destination point as recived
    bool hasPlayerInDestination(); //returns true if a player/s reached the goal destination spot
    void update(const Team &team);//this function updates the game field
	/*getters*/
	const Point &getGoalDestination() const;
	const Spot &getField() const;
	const Spot &getDestinationSpot() const;
private:
    Point goalDestination;
    Spot field[FIELD_SIZE_Y_PLANE][FIELD_SIZE_X_PLANE];
    Spot *destinationSpot;
};
#endif //FIELD_H
