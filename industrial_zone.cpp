// ** "Industrial Zone" file **

// The industrial zone is a child of the cell class. It contains functions specialized for simulating industrial growth.

#include "industrial_zone.h"

Industrial_Zone::Industrial_Zone() {
    isPolluted = false;
    population = 0;
    cellType = "industrial";
}

// Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
int Industrial_Zone::incrementTime(vector<vector<Cell*>> region) {

    //*******************
    // Sanjay's Assignment
    //*******************
    return 1;
}
