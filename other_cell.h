// ** "Other Cell" header file **

// The "other cell" is a child of the cell class. It is used to specify other kinds of cells than industrial, commercial, or residential.

#include "cell.h"

class Other_Cell : public Cell {

    public:
        Other_Cell(); // Constructor
        int incrementTime(vector<vector<Cell*>>); // Simply returns 0, as "other" cells have no increment time function.
};

