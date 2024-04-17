// ** "Residential Zone" header file **

// The residential zone is a child of the cell class. It contains functions specialized for simulating residential growth.

#include "cell.h"

class Residential_Zone : public Cell {

    public:
        Residential_Zone(); // Constructor
        int incrementTime(vector<vector<Cell*>>); // Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
};
