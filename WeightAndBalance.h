//
// Created by natee on 1/17/2026.
//

#ifndef CPPWEIGHTANDBALANCE_WEIGHTANDBALANCE_H
#define CPPWEIGHTANDBALANCE_WEIGHTANDBALANCE_H
#include "Airplane.h"
using namespace std;

//See .cpp for comments
class WeightAndBalance {
    private:
        Airplane plane;
        double usableFuelGallons;
        double fuelBurnGallons;

        double frontPilotsWeight;
        double rearPassengerWeight;
        double baggageWeight;
        double basicEmptyWeight;
        double basicEmptyMoment;

        double zeroFuelCG;
        double takeoffCG;
        double landingCG;

    public:
        WeightAndBalance(
            Airplane plane,
            double usableFuelGallons,
            double fuelBurnGallons,
            double frontPilotsWeight,
            double rearPassengerWeight,
            double baggageWeight,
            double basicEmptyWeight,
            double basicEmptyMoment
        );

        double getUsableFuelGallons() const;
        double getFuelBurnGallons() const;
        double getFrontPilotsWeight() const;
        double getRearPassengerWeight() const;
        double getBaggageWeight() const;
        double getBasicEmptyWeight() const;
        double getBasicEmptyMoment() const;
    
        double getZeroFuelCG() const;
        double getTakeoffCG() const;
        double getLandingCG() const;

        void setZeroFuelCG(const double& cg);
        void setTakeoffCG(const double& cg);
        void setLandingCG(const double& cg);

        double calculateCG(const double& weight, const double& moment);
        void runWeightAndBalance();
};


#endif //CPPWEIGHTANDBALANCE_WEIGHTANDBALANCE_H