#ifndef MEDACTIVECOOLINGSTRATEGY_H
#define MEDACTIVECOOLINGSTRATEGY_H

#include "CoolingStrategy.h"

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        if (temperatureInC < 0) {
            return TOO_LOW;
        } else if (temperatureInC > 35) {
            return TOO_HIGH;
        }
        return NORMAL;
        return inferBreach(temperatureInC, 0, 40);
    }
};
#endif //MEDACTIVECOOLINGSTRATEGY_H
