//
// Created by natee on 1/17/2026.
//

#include "WeightAndBalance.h"

// Constructor //
// - assigns variables immediately (member initializer list)
WeightAndBalance::WeightAndBalance(
    Airplane aircraft,
    double usableFuel,
    double fuelBurn,
    double frontPilot,
    double rearPassenger,
    double baggage,
    double emptyWeight,
    double emptyMoment
) :
    plane(aircraft),
    usableFuelGallons(usableFuel),
    fuelBurnGallons(fuelBurn),
    frontPilotsWeight(frontPilot),
    rearPassengerWeight(rearPassenger),
    baggageWeight(baggage),
    basicEmptyWeight(emptyWeight),
    basicEmptyMoment(emptyMoment)
{}


// Getters//
// - applying principle of encapsulation.
double WeightAndBalance::getUsableFuelGallons() const {return usableFuelGallons;}
double WeightAndBalance::getFuelBurnGallons() const {return fuelBurnGallons;}

double WeightAndBalance::getFrontPilotsWeight() const {return frontPilotsWeight;}
double WeightAndBalance::getRearPassengerWeight() const {return rearPassengerWeight;}
double WeightAndBalance::getBaggageWeight() const {return baggageWeight;}

double WeightAndBalance::getBasicEmptyWeight() const {return basicEmptyWeight;}
double WeightAndBalance::getBasicEmptyMoment() const {return basicEmptyMoment;}

double WeightAndBalance::getZeroFuelCG() const { return zeroFuelCG;}
double WeightAndBalance::getTakeoffCG() const {return takeoffCG;}
double WeightAndBalance::getLandingCG() const {return landingCG;}

//Setters//
// - CG only available to be assigned after calculation,
//   so setters are necessary
// - 'const double&' syntax prevents making a copy of cg when function is called
void WeightAndBalance::setZeroFuelCG(const double& cg) {
    zeroFuelCG = cg;
}
void WeightAndBalance::setTakeoffCG(const double& cg) {
    takeoffCG = cg;
}
void WeightAndBalance::setLandingCG(const double& cg) {
    landingCG = cg;
}

//Run W&B Calculations //

// to find CG: Total moment / total weight = CG
double WeightAndBalance::calculateCG(const double& weight, const double& moment) {
    return moment / weight;
}

//Calculate and set CG at 3 phases: zeroFuel, takeoff, landing
// weight * arm = moment
void WeightAndBalance::runWeightAndBalance() {
    // 100LL Avgas = 6 lbs / gallon
    const double FUEL_WEIGHT = 6.0;

    // zero fuel //
    double zfWeight =
        getBasicEmptyWeight() +
        getFrontPilotsWeight() +
        getRearPassengerWeight() +
        getBaggageWeight();

    double zfMoment =
        getBasicEmptyMoment() +
        getFrontPilotsWeight() * plane.getFrontPilotArm() +
        getRearPassengerWeight() * plane.getRearPassengerArm() +
        getBaggageWeight() * plane.getBaggageArm();

    setZeroFuelCG(calculateCG(zfWeight, zfMoment));

    // takeoff //
    double fuelWeight = getUsableFuelGallons() * FUEL_WEIGHT;
    double fuelMoment = fuelWeight * plane.getFuelArm();

    double toWeight = zfWeight + fuelWeight;
    double toMoment = zfMoment + fuelMoment;

    setTakeoffCG(calculateCG(toWeight, toMoment));

    // landing //
    double landingFuel = (getUsableFuelGallons() - getFuelBurnGallons()) * FUEL_WEIGHT;
    double landingFuelMoment = landingFuel * plane.getFuelArm();

    double landingWeight = zfWeight + landingFuel;
    double landingMoment = zfMoment + landingFuelMoment;

    setLandingCG(calculateCG(landingWeight, landingMoment));
}