#include "typewise-alert.h"
#include "CoolingStrategy.h"
#include <stdio.h>
#include <unordered_map>

// Assuming the BatteryCharacter struct is defined somewhere like this:
struct BatteryCharacter {
    CoolingStrategy* coolingStrategy;  // Pointer to the strategy
    char brand[48];
};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) {
        return TOO_LOW;
    }
    if (value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

// Correct definition of classifyTemperatureBreach
BreachType classifyTemperatureBreach(const BatteryCharacter& batteryChar, double temperatureInC) {
    if (batteryChar.coolingStrategy) {
        return batteryChar.coolingStrategy->classifyTemperature(temperatureInC);
    } else {
        return NORMAL;  // Default behavior if coolingStrategy is null
    }
}

void checkAndAlert(AlertTarget alertTarget, const BatteryCharacter& batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar, temperatureInC);  // Pass the correct type

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
