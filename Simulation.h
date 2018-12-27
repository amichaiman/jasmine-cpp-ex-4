/*Game Simulation*/
#ifndef SIMULATION_H
#define SIMULATION_H
#include <string>
#include <fstream>
#include "Field.h"
#include "Team.h"
using namespace std;

class Simulation {
public:
	//big three:
    Simulation(); //constructor
    virtual ~Simulation(); //destructor
    Simulation& operator=(const Simulation &rhs); //copy assignment operator
	void run(); ////this function runs the simulation as long as the game time isn't over and the goal is not recieved
    bool config(char* fileName);//this function returns true if reading the config file went good & gets the game total time and the goal destination details, false otherwise.
    bool init(char* fileName);//this function returns true if reading the init file went good & gets all of the player details, false otherwise.
    /* getters */
    int getCurTime() const;
    int getTotalTime() const;
    const Field &getField() const;
    const Team &getTeam() const;
private:
    int curTime; 
    int totalTime;
    Field field;
    Team team;
    void update(); //updates each stage of the simulation by updating both the team and the field
    void printResults(); //prints the cur time and the players locations
    bool fileStateIsGood(const ifstream &file); //returns true if file state is good,false otherwise.
};

#endif //SIMULATION_H
