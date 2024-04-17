// ** "Commercial Zone" header file **

// The commercial zone is a child of the cell class. It contains functions specialized for simulating commercial growth.

#include "cell.h"

class Commercial_Zone : public Cell {

    public:
        Commercial_Zone(); // Constructor
        int incrementTime(vector<vector<Cell*>>); // Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
};