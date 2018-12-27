#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Simulation.h"
using namespace std;

/*This is a program of Ice Hockey, based on a two-dimensional euclidean space that defines the arena of the game, and
the players in a time-dependent simulation.*/

int main(int argc, char **argv) {
    srand(static_cast<unsigned int>(time(NULL)));
	
	//if recieving the input files and reading them went right, then let the game begin
    if (argc != 3){
        cerr << "ERROR: Invalid input." << endl;
        exit(1);
    }
    Simulation simulation;
    if (!simulation.config(argv[1]) || !simulation.init(argv[2])){
        cerr << "ERROR: Invalid input." << endl;
        exit(2);
    }
    simulation.run();
    return 0;
}