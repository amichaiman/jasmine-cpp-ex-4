/*Game Simulation*/
#include <iostream>
#include <fstream>
#include "Simulation.h"
#include "Point.h"
#include "Goalie.h"
#include "Defensemen.h"
#include "Forwards.h"


//constructor to initalize the starting time of the game as 0
Simulation::Simulation(): curTime(0) {}

//this function runs the simulation as long as the game time isn't over and the goal is not recieved
void Simulation::run() {
    for (curTime=0; curTime < totalTime && !field.hasPlayerInDestination(); curTime++){
        update();
    }
    printResults();
}

//this function returns true if reading the config file went good & gets the game total time and the goal destination details, false otherwise.
bool Simulation::config(char* fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        return false;
    }
    Point goalDestination;
	//get the details of goal destination from the input config file into the variables
    file >> goalDestination.x >> goalDestination.y;
    if (!fileStateIsGood(file) || file.eof()){
        return false;
    }
    field.setGoalDestination(goalDestination);
    team.setDestinationPoint(goalDestination);
    file >> totalTime; //get the total game time from the file 
    return fileStateIsGood(file) ;
}

//this function returns true if reading the init file went good & gets all of the player details, false otherwise.
bool Simulation::init(char* fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        return false;
    }
    int numOfPlayers;
    file >> numOfPlayers; //get the number of players in the game
    if (!fileStateIsGood(file) || file.eof()){
        return false;
    }
    if (!team.setNumOfPlayers(numOfPlayers)){ //function returns false if number of players isn't valid
        return false;
    }
    char playerType;
    Point startingPoint;
    Speed startingSpeed;
	//for each player get his starting speed and starting point
    for (int i=0; i<numOfPlayers; i++){
        file >> playerType >> startingPoint.x >> startingPoint.y >> startingSpeed.speedX >> startingSpeed.speedY;
        if (!fileStateIsGood(file)){
            return false;
        }
        if (i!=numOfPlayers-1 && file.eof()) {
            return false;
        }
        Player *player;
        switch (playerType) {
            case 'G':
                player = new Goalie(startingPoint, startingSpeed, i); break;
            case 'D':
                player = new Defensemen(startingPoint, startingSpeed, i); break;
            case 'F':
                player = new Forwards(startingPoint, startingSpeed, i); break;
            default:
                return false;
        }
        team.setPlayer(player, i); //get him into the ream
    }
    return true;
}

//returns true if file state is good, false otherwise.
bool Simulation::fileStateIsGood(const ifstream &file) {
    return !file.fail() && !file.bad();
}

//this function updates each stage of the simulation by updating both the team and the field
void Simulation::update() {
    team.update();
    field.update(team);
}

//this function prints the curren time of the game and all of the players locations
void Simulation::printResults() {
    cout << curTime << endl;
    team.printPlayersLocations();
}

//copy assignment operator for a recieved simulation 
Simulation &Simulation::operator=(const Simulation &rhs) {
	if (&rhs == this) {
		return *this;
	}
    curTime = rhs.getCurTime();
    totalTime = rhs.getTotalTime();
    field = rhs.getField();
    team = rhs.getTeam();
    return *this;
}

//destructor
Simulation::~Simulation() { }

/* getters */ 
int Simulation::getCurTime() const {
    return curTime;
}
int Simulation::getTotalTime() const {
    return totalTime;
}
const Field &Simulation::getField() const {
    return field;
}
const Team &Simulation::getTeam() const {
    return team;
}

