// ** "Cell" Header File **

// The cell class serves as the parent class for more detailed cell objects, which inherit via polymorphism.

#include <string>
#include <vector>
#pragma once
using namespace std;

class Cell {

    protected:
        bool isPolluted; // Boolean value shows if cell is polluted
        int population; // Indicates cell population
        string cellType; // Contains cell type, i.e. "Residential", "Commercial", etc.
        int xVal; // Contains the x value of the cell
        int yVal; // Contains the y value of the cell

    public:

        //Constructor
        Cell();

        //Accessors and mutators for variables
        bool getPollution();
        void setPollution(bool);
        int getPopulation();
        void setPopulation(int);
        string getCellType();
        void setCellType(string);
        int getXVal();
        void setXVal(int);
        int getYVal();
        void setYVal(int);
        string getCharacter();

        bool operator< (Cell&);

        virtual int incrementTime(vector<vector<Cell*>>); //Base function for imcrementing time
};