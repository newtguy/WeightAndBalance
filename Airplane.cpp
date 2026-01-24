//
// Created by natee on 1/18/2026.
//

#include "Airplane.h"

// Constructor for single fuelArm
Airplane::Airplane(
    double pilotArm,
    double passengerArm,
    double bagArm,
    double fuelArm
) :
    frontPilotArm(pilotArm),
    rearPassengerArm(passengerArm),
    baggageArm(bagArm),
    fuelArm(fuelArm)
{}

// Constructor for airplane with multiple fuelArms
// Useful in case more aircraft are added in future
Airplane::Airplane(
    double pilotArm,
    double passengerArm,
    double bagArm,
    double fuelArm,
    double fuelArm2
) :
    frontPilotArm(pilotArm),
    rearPassengerArm(passengerArm),
    baggageArm(bagArm),
    fuelArm(fuelArm),
    fuelArm2(fuelArm2)
{}

// Getters //
double Airplane::getFrontPilotArm() const {return frontPilotArm;}
double Airplane::getRearPassengerArm() const {return rearPassengerArm;}
double Airplane::getBaggageArm() const {return baggageArm;}
double Airplane::getFuelArm() const {return fuelArm;}
double Airplane::getFuelArm2() const {return fuelArm2;}

