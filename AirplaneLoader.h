#ifndef CPPWEIGHTANDBALANCE_AIRCRAFTLOADER_H
#define CPPWEIGHTANDBALANCE_AIRCRAFTLOADER_H

#include <string>
#include "Airplane.h"

using namespace std;

Airplane loadAirplaneFromJson(const string& filename);

#endif
