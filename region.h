// ** "Region" header file **

// The region file contains a 2D Vector of cell pointers to represent the region for the simulation

#include "cell.h"
#include "industrial_zone.h"
#include "residential_zone.h"
#include "commercial_zone.h"
#include "other_cell.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <stack>

using namespace std;

class Region {
    
    private:
        vector<vector<Cell*>> region;

    public:

        //Constructor and destructor
        Region(string fileName); //Constructs from file
        ~Region();

        vector<vector<Cell*>> getRegion(); // Accessor

        void incrementTime(); //Simulates time passing by calling cells' incrementTime funtions

        int getAdjacentPopulation(Cell* toAdd); // Gets the total population of adjacent cells

        void printRegion(); //Prints region to terminal
        void printRegion(string fileName, int iterationNumber); //Prints region to file
};
