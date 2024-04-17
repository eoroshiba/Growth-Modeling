// ** "Other Cell" file **

// The "other cell" is a child of the cell class. It is used to specify other kinds of cells than industrial, commercial, or residential.

#include "other_cell.h"

Other_Cell::Other_Cell() {
    isPolluted = false;
    population = 0;
    cellType = "empty";
}

int Other_Cell::incrementTime(vector<vector<Cell*>> region) {
    return 0;
}
