#include "AirplaneLoader.h"
#include <fstream>

#include "include/nlohmann/json.hpp"

using namespace std;

//Returns airplane object populated by data from JSON file
Airplane loadAirplaneFromJson(const string& filename) {
    //Create input file stream
    ifstream file(filename);

    //Check proper file retrieval
    if (!file) {
        throw runtime_error("Could not open file: " + filename);
    }

    //JSON object instantiated
    nlohmann::json j;
    //File read into JSON object
    file >> j;

    //Return Airplane object
    return Airplane(
        // access JSON value by key
        // ensures data is retrieved as <double>
        j.at("arms").at("front_pilot").get<double>(),
        j.at("arms").at("rear_passenger").get<double>(),
        j.at("arms").at("baggage").get<double>(),
        j.at("arms").at("fuel").get<double>()
    );
}
