// typewise-alert.cpp
#include "typewise-alert.h"
#include "CoolingStrategy.h"
#include <stdio.h>

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

void checkAndAlert(AlertTarget alertTarget, const BatteryCharacter& batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar, temperatureInC);

    switch (alertTarget) {
        case TO_CONTROLLER:
            sendToController(breachType);
            break;
        case TO_EMAIL:
            sendToEmail(breachType);
            break;
    }
}

void sendToController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recepient = "a.b@c.com";
    switch (breachType) {
        case TOO_LOW:
            printf("To: %s\n", recepient);
            printf("Hi, the temperature is too low\n");
            break;
        case TOO_HIGH:
            printf("To: %s\n", recepient);
            printf("Hi, the temperature is too high\n");
            break;
        case NORMAL:
            break;
    }
}
