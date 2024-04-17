// ** "Cell" File **

// The cell class serves as the parent class for more detailed cell objects, which inherit via polymorphism.

#include "cell.h"

//Constructor
Cell::Cell() {
    isPolluted = false;
    population = 0;
    cellType = "";
    xVal = -1;
    yVal = -1;
}

//Accessors and mutators for variables
bool Cell::getPollution() {
    return isPolluted;
}

void Cell::setPollution(bool toSetPollution) {
    isPolluted = toSetPollution;
}

int Cell::getPopulation() {
    return population;
}

void Cell::setPopulation(int toSetPopulation) {
    population = toSetPopulation;
}

string Cell::getCellType() {
    return cellType;
}

void Cell::setCellType(string toSetCellType) {
    cellType = toSetCellType;
}

int Cell::getXVal() {
    return xVal;
}

void Cell::setXVal(int toSetX) {
    xVal = toSetX;
}

int Cell::getYVal() {
    return yVal;
}

void Cell::setYVal(int toSetY) {
    yVal = toSetY;
}

string Cell::getCharacter() {
    if(population > 0) {
        return to_string(population);
    }
    else if(cellType.compare("commercial") == 0) {
        return "C";
    }
    else if(cellType.compare("residential") == 0) {
        return "R";
    }
    else if(cellType.compare("industrial") == 0) {
        return "I";
    }
    else if(cellType.compare("road") == 0) {
        return "-";
    }
    else if(cellType.compare("powerline") == 0) {
        return "T";
    }
    else if(cellType.compare("powerline_over_road") == 0) {
        return "#";
    }
    else if(cellType.compare("power_plant") == 0) {
        return "P";
    }
    return " ";
}

bool Cell::operator< (Cell& rightCellObject) {
    Cell* leftCell = this;
    Cell* rightCell = &rightCellObject;
    if((rightCell->getCellType().compare("commercial") == 0 ) && (leftCell->getCellType().compare("commercial") != 0)) {
        return true;
    }
    else if (rightCell->getPopulation() > leftCell->getPopulation()) {
        return true;
    }
    else {
        return false;
    }
}

int Cell::incrementTime(vector<vector<Cell*>>) {
    return 0;
}
