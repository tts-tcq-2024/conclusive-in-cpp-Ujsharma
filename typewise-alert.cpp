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
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);  // Corrected

    std::unordered_map<AlertTarget, void(*)(BreachType)> alertFunctionMap = {
        { TO_CONTROLLER, sendToController },
        { TO_EMAIL, sendToEmail }
    };

    alertFunctionMap[alertTarget](breachType);
}

void sendToController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    
    std::unordered_map<BreachType, const char*> breachMessages = {
        { TOO_LOW, "Hi, the temperature is too low" },
        { TOO_HIGH, "Hi, the temperature is too high" }
    };

    if (breachMessages.find(breachType) != breachMessages.end()) {
        printf("To: %s\n", recipient);
        printf("%s\n", breachMessages[breachType]);
    }
}
