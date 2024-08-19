// PassiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 35);
    }
};

