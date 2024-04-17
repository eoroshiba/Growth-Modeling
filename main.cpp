// ** Main File **

#include "region.h"

using namespace std;

int main() {
    string configFileName;
    cout << "Please specify configuration file:" << endl;
    cin >> configFileName;
    ifstream configFile;
    configFile.open(configFileName);
    if(!configFile.is_open()) {
        cout << "Error opening file or incorrect file name. Aborting program" << endl;
        exit(1);
    }
    
    // Declaring variables for retrieving data from configuration file
    string regionFileName;
    int totalTimes, refreshRate;
    string line;
    string input;

    // Getting first line of configuration file
    getline(configFile, line);
    if(line.substr(0, 14).compare("Region Layout:") != 0) { // Exception to catch if config file is formatted incorrectly
        cout << "Configuration file formatted incorrectly. Aborting program" << endl;
        exit(1);
    }
    input = line.substr(14, line.length()-14);
    regionFileName = input;

    // Getting second line of configuration file
    getline(configFile, line);
    if(line.substr(0, 11).compare("Time Limit:") != 0) { // Exception to catch if config file is formatted incorrectly
        cout << "Configuration file formatted incorrectly. Aborting program" << endl;
        exit(1);
    }
    input = line.substr(11, line.length()-11);
    totalTimes = stoi(input);

    // Getting third line of configuration file
    getline(configFile, line);
    if(line.substr(0, 13).compare("Refresh Rate:") != 0) { // Exception to catch if config file is formatted incorrectly
        cout << "Configuration file formatted incorrectly. Aborting program" << endl;
        exit(1);
    }
    input = line.substr(13, line.length()-13);
    refreshRate = stoi(input);

    // Declaring and initializing region object
    Region region(regionFileName);
    
    // Prompt user for output to terminal or output file
    cout << "Would you like to output region state to terminal or file? (Enter number of choice)" << endl;
    cout << "1. Terminal" << endl;
    cout << "2. Output File" << endl;
    cin >> input;
    int outputSelection = stoi(input);

    string outputFile;

    if(outputSelection == 1) {
        cout << "Initial Region State:" << endl;
        region.printRegion(); // Output the initial region state to terminal
    }
    else if(outputSelection == 2) {
        cout << "Please specify the output file:" << endl;
        cin >> outputFile;
        region.printRegion(outputFile, 0); // Output the initial region state to output file
    }

    for(int i = 1; i <= totalTimes; i++) {
        region.incrementTime();
        if(i % refreshRate == 0) {
            if(outputSelection == 1) {
                cout << "Iteration " << i << endl;
                region.printRegion();
            }
            else {
                region.printRegion(outputFile, i);
            }
        }
    }
    system("pause");
}