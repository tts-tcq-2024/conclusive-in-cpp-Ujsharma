// PassiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 35);
    }
};

// HiActiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 45);
    }
};

// MedActiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 40);
    }
};
