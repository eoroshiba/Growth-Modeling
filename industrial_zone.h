// ** "Industrial Zone" header file **

// The industrial zone is a child of the cell class. It contains functions specialized for simulating industrial growth.

#include "cell.h"

class Industrial_Zone : public Cell {

    public:
        Industrial_Zone(); // Constructor
        int incrementTime(vector<vector<Cell*>>); // Performs the actions necessary when time is incremented on the cell, returns 0 if no changes made, 1 if changes were
};
