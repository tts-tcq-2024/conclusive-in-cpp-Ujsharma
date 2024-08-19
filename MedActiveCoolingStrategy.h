
// MedActiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 40);
    }
};
