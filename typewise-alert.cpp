// typewise-alert.cpp
#include "typewise-alert.h"
#include "CoolingStrategy.h"
#include <stdio.h>
#include <unordered_map>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) {
        return TOO_LOW;
    }
    if (value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

BreachType classifyTemperatureBreach(const BatteryCharacter& batteryChar, double temperatureInC) {
    return batteryChar.coolingStrategy->classifyTemperature(temperatureInC);
}

}

void checkAndAlert(AlertTarget alertTarget, const BatteryCharacter& batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

    // Map associating AlertTarget with the corresponding alert function
    std::unordered_map<AlertTarget, AlertFunction> alertFunctionMap = {
        { TO_CONTROLLER, sendToController },
        { TO_EMAIL, sendToEmail }
    };

    // Call the appropriate function based on alertTarget
    alertFunctionMap[alertTarget](breachType);
}

void sendToController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    switch (breachType) {
        case TOO_LOW:
            printf("To: %s\n", recipient);
            printf("Hi, the temperature is too low\n");
            break;
        case TOO_HIGH:
            printf("To: %s\n", recipient);
            printf("Hi, the temperature is too high\n");
            break;
        case NORMAL:
            break;
    }
}
