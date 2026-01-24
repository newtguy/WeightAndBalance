//
// Created by natee on 1/18/2026.
//

#ifndef CPPWEIGHTANDBALANCE_AIRPLANE_H
#define CPPWEIGHTANDBALANCE_AIRPLANE_H

// Airplane class declaration
class Airplane {
    private:
        double frontPilotArm;
        double rearPassengerArm;
        double baggageArm;
        double fuelArm;
        double fuelArm2 = 0;
    public:
        Airplane(double pilotArm, double passengerArm, double bagArm, double fuelArm);
        Airplane(double pilotArm, double passengerArm, double bagArm, double fuelArm, double fuelArm2);

        double getFrontPilotArm() const;
        double getRearPassengerArm() const;
        double getBaggageArm() const;
        double getFuelArm() const;
        double getFuelArm2() const;
};


#endif //CPPWEIGHTANDBALANCE_AIRPLANE_H