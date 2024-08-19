// HiActiveCoolingStrategy.h
#pragma once

#include "CoolingStrategy.h"

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 45);
    }
};
