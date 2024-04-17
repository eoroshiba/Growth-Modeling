// ** "Commercial Zone" file **

// The commercial zone is a child of the cell class. It contains functions specialized for simulating commercial growth.

#include "commercial_zone.h"

Commercial_Zone::Commercial_Zone() {
    isPolluted = false;
    population = 0;
    cellType = "commercial";
}

// Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
int Commercial_Zone::incrementTime(vector<vector<Cell*>> region) {

    //*******************
    // Turki's Assignment
    //*******************
    return 1;
}
