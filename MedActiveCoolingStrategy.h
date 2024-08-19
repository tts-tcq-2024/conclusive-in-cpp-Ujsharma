#ifndef MEDACTIVECOOLINGSTRATEGY_H
#define MEDACTIVECOOLINGSTRATEGY_H
#pragma once

#include "CoolingStrategy.h"

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 40);
    }
};
#endif //MEDACTIVECOOLINGSTRATEGY_H
