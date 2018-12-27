#include "Goalie.h"

double Goalie::alpha() {
    return 0.01;
}

double Goalie::beta() {
    return -0.1;
}

double Goalie::gama() {
    return -0.25;
}

char Goalie::getPlayerType() {
    return 'G';
}
