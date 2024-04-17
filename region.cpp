// ** "Region" file **

// The region file contains a 2D Vector of cell pointers to represent the region for the simulation

#include "region.h"


//Constructing from file
Region::Region(string fileName) {
    ifstream regionFile;
    regionFile.open(fileName);

    if(regionFile.is_open()) {
        string line;
        int rowCount = 0;
        int columnCount;

        while(getline(regionFile, line)) {
            columnCount = 0;
            istringstream lineStream(line);
            string cellString;
            vector<Cell*> tempRow;

            while(getline(lineStream, cellString, ',')) {
                Cell* cellToAdd;

                if(cellString.compare(" ") == 0) {
                    cellToAdd = new Other_Cell();
                }
                else if(cellString.compare("-") == 0) {
                    cellToAdd = new Other_Cell();
                    cellToAdd->setCellType("road");
                }
                else if(cellString.compare("T") == 0) {
                    cellToAdd = new Other_Cell();
                    cellToAdd->setCellType("powerline");
                }
                else if(cellString.compare("#") == 0) {
                    cellToAdd = new Other_Cell();
                    cellToAdd->setCellType("powerline_over_road");
                }
                else if(cellString.compare("P") == 0) {
                    cellToAdd = new Other_Cell();
                    cellToAdd->setCellType("power_plant") ;
                }
                else if(cellString.compare("R") == 0) {
                    cellToAdd = new Residential_Zone();
                }
                else if(cellString.compare("I") == 0) {
                    cellToAdd = new Industrial_Zone();
                }
                else if(cellString.compare("C") == 0) {
                    cellToAdd = new Commercial_Zone();
                }
                else {
                    cout << "File formatted incorrectly. Aborting program." << endl;
                    exit(1);
                }
                cellToAdd->setXVal(columnCount);
                cellToAdd->setYVal(rowCount);

                tempRow.insert(tempRow.end(), cellToAdd);
                columnCount++;
            }

            region.insert(region.end(), tempRow);
            rowCount++;
        }

        regionFile.close();
    }

    else {
        cout << "Error opening file" << endl;
    }
}


//Destructor
Region::~Region() {
    for(vector<Cell*> Row: region) {
        for(Cell* toDelete : Row) {
            delete toDelete;
        }
    }
}


//Accessor
vector<vector<Cell*>> Region::getRegion() {
    return region;
}


//Simulates time passing by calling cells' incrementTime funtions
void Region::incrementTime() {
    list<Cell*> cells; // List to contain a list of visited cells. Values stored as x,y
    int y = 0;
    int x = 0;
    while(y < region.size()) {
        while(x < region[y].size()) {
            cells.push_back(region[x][y]);
            x++;
        }
        y++;
    }
    cells.sort();
    int changes;
    while(cells.size() > 0) {
        Cell* current = cells.back();
        cells.pop_back();
        changes += current->incrementTime(region);
    }
    if(changes == 0) {
        exit(0);
    }
}


//Gets total population of adjacent cells
int Region::getAdjacentPopulation(Cell* toAdd) {
    int populationCount = 0;
    bool clearLeft = false;
    bool clearRight = false;
    int x = toAdd->getXVal();
    int y = toAdd->getYVal();

    if(x > 0) {
        populationCount += region[x-1][y]->getPopulation();
        clearLeft = true;
    }
    if(x < region.size() - 1) {
        populationCount += region[x+1][y]->getPopulation();
        clearRight = true;
    }
    if(y > 0) {
        populationCount += region[y-1][x]->getPopulation();
        if(clearLeft) {
            populationCount += region[y-1][x-1]->getPopulation();
        }
        if(clearRight) {
            populationCount += region[y-1][x+1]->getPopulation();
        }
    }
    if(y < region[x].size() - 1) {
        populationCount+= region[y+1][x]->getPopulation();
        if(clearLeft) {
            populationCount += region[y+1][x-1]->getPopulation();
        }
        if(clearRight) {
            populationCount += region[y+1][x+1]->getPopulation();
        }
    }
    return populationCount;
}

// Prints region to terminal
void Region::printRegion() {
    for(vector<Cell*> row : region) {
        for(Cell* currentCell : row) {
            if(currentCell->getXVal() < region[0].size()-1) {
                cout << currentCell->getCharacter() << ",";
            }
            else {
                cout << currentCell->getCharacter();
            }
        }
        cout << endl << endl;
    }
}

// Prints region to file
void Region::printRegion(string fileName, int iterationNumber) {

    //***************
    // Zach work here
    //***************

}
