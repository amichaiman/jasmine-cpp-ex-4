/*Game Field*/
#include <cmath>
#include <iostream>
#include "Field.h"


//default constructor
Field::Field() {}

//sets the goal destination point as recived
void Field::setGoalDestination(const Point &goalDestination) {
    Field::goalDestination = goalDestination;
	//sets the goal spot in the field 
    destinationSpot = &field[static_cast<int>(goalDestination.y)][static_cast<int>(goalDestination.x)];
}

//field copy assignment operator
Field & Field::operator=(const Field & rhs)
{
	if (&rhs == this) {
		return *this;
	}

	goalDestination=rhs.getGoalDestination();
	field[FIELD_SIZE_Y_PLANE][FIELD_SIZE_X_PLANE] = rhs.getField();
	*destinationSpot=rhs.getDestinationSpot();
	return *this;

}

//returns true if a player/s reached the goal destination spot
bool Field::hasPlayerInDestination() {
    return destinationSpot->getNumOfPlayers() != 0;
}

//this function updates the game field
void Field::update(const Team &team) {
    for (int i=0; i<FIELD_SIZE_Y_PLANE; i++){
        for (int j=0; j<FIELD_SIZE_X_PLANE; j++){
            field[i][j].setNumOfPlayers(0);
            for (int k=0; k<team.getNumberOfPlayers(); k++) {
                if (field[i][j].hasPlayerInSpot(team.getPlayer(k), i, j)){
                    field[i][j]++; //increase num of players
                }
            }
        }
    }
}

/*getters*/
const Point &Field::getGoalDestination() const{
	return goalDestination;
}
const Spot &Field::getField() const{
	return field[FIELD_SIZE_Y_PLANE][FIELD_SIZE_X_PLANE];
}
const Spot &Field::getDestinationSpot() const{
	return *destinationSpot;
}

//destructor
Field::~Field(){}
