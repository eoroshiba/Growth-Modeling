// ** "Residential Zone" file **

// The residential zone is a child of the cell class. It contains functions specialized for simulating residential growth.

#include "residential_zone.h"

Residential_Zone::Residential_Zone() {
    isPolluted = false;
    population = 0;
    cellType = "residential";
}

// Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
int Residential_Zone::incrementTime(vector<vector<Cell*>> region) {

    //*******************
    // Tyler's Assignment
    //*******************
    return 1;
}
