//
// Created by natee on 1/17/2026.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

#include "Airplane.h"
#include "AirplaneLoader.h"
#include "WeightAndBalance.h"

using namespace std;

// Prompts user for applicable W&B information to populate a vector
vector<double> getUserFigures() {
    /* WAB Input Order:
    double usableFuel,
    double fuelBurn,
    double frontPilot,
    double rearPassenger,
    double baggage,
    double emptyWeight,
    double emptyMoment
    */
    vector<string> prompts = {
        "usable fuel (gallons)",
        "est. fuel burn during flight (gallons)",
        "front pilots' weight (lbs)",
        "rear passengers' weight (lbs)",
        "baggage compartment weight (lbs)",
        "plane basic empty weight (lbs)",
        "plane basic empty moment"
    };

    //Create vector of numbers that will be populated
    vector<double> wabFigs(7);

    for (int i = 0; i < 7; i++) {
        cout <<"Please enter " + prompts[i] + ": ";
        cin >> wabFigs[i];
    }

    return wabFigs;
}

// Interface to select between a generic W&B or manually inserted data
vector<double> wabMenu() {
    int userInt;
    vector<double> defaults = {53, 30, 380, 140, 50, 1734.6, 71722.2};

    while (true) {
        cout << "Press 1 for default weight and balance data." << endl;
        cout << "Press 2 to enter your own weight and balance data." << endl;
        cout << "Enter your choice: ";
        cin >> userInt;

        if (userInt == 1) {
            return defaults;
        } else if (userInt == 2) {
            return getUserFigures();
        } else {
            cout << endl << "Please enter a valid number." << endl << endl;
        }
    }
}

// Returns string object that contains formatted CG table
string buildCGTable(const WeightAndBalance& wab) {

    ostringstream out;
    const int tableWidth = 24;

    out << "WEIGHT & BALANCE RESULTS\n";
    out << string(tableWidth, '-') << '\n';

    out << setw(15) << left << "Phase"
        << setw(9)  << left << "CG (in)\n";

    out << string(tableWidth, '-') << '\n';

    out << setw(15) << left << "Zero Fuel"
        << fixed << setprecision(2)
        << wab.getZeroFuelCG() << '\n';

    out << setw(15) << left << "Takeoff"
        << wab.getTakeoffCG() << '\n';

    out << setw(15) << left << "Landing"
        << wab.getLandingCG() << '\n';

    return out.str();
}

//Writes string to the designated file
void writeToFile(const string& text, const string& filename) {
    //open filename for output file stream writing
    ofstream file(filename);

    //check error with output file
    if (!file) {
        throw runtime_error("Could not open output file:" + filename);
        return;
    }

    //Writes to output file
    file << text;
    file.close();
}

int main() {
    //Instantiate Airplane object with data from JSON
    Airplane airplane = loadAirplaneFromJson("../aircraft/c172s.json");

    //Populate vector with desired W&B data
    vector<double> wabFigs = wabMenu();

    //Instantiate WeightAndBalance object with airplane config and W&B data
    WeightAndBalance wab(airplane, wabFigs[0], wabFigs[1], wabFigs[2], wabFigs[3], wabFigs[4], wabFigs[5], wabFigs[6]);
    wab.runWeightAndBalance();

    string output = buildCGTable(wab);
    cout << output << endl;

    writeToFile(output, "../output/output.txt");

    return 0;
}
