#include "AutoPack.h"
#include <stdlib.h>
#include <string.h>

// Pre-instantiate the global instance
AutoPackClass AutoPack;

AutoPackClass::AutoPackClass() {
    // Default delimiters
    _delimiters[0] = ',';
    _delimiters[1] = ' ';
    _delimiters[2] = '\0';
    _delimCount = 2;
}

void AutoPackClass::delimit(const char* delimiters) {
    _delimCount = 0;
    if (delimiters == NULL) return;
    
    while (delimiters[_delimCount] != '\0' && _delimCount < 7) {
        _delimiters[_delimCount] = delimiters[_delimCount];
        _delimCount++;
    }
    _delimiters[_delimCount] = '\0';
}

uint16_t AutoPackClass::parseInt(char* inputMsg, int* outputArray, uint16_t maxCapacity) {
    if (inputMsg == NULL || outputArray == NULL) return 0;
    uint16_t count = 0;
    char* token = strtok(inputMsg, _delimiters);
    while (token != NULL && count < maxCapacity) {
        outputArray[count++] = atoi(token);
        token = strtok(NULL, _delimiters);
    }
    return count;
}

uint16_t AutoPackClass::parseFloat(char* inputMsg, float* outputArray, uint16_t maxCapacity) {
    if (inputMsg == NULL || outputArray == NULL) return 0;
    uint16_t count = 0;
    char* token = strtok(inputMsg, _delimiters);
    while (token != NULL && count < maxCapacity) {
        outputArray[count++] = atof(token);
        token = strtok(NULL, _delimiters);
    }
    return count;
}

uint16_t AutoPackClass::parseByte(char* inputMsg, uint8_t* outputArray, uint16_t maxCapacity) {
    if (inputMsg == NULL || outputArray == NULL) return 0;
    uint16_t count = 0;
    char* token = strtok(inputMsg, _delimiters);
    while (token != NULL && count < maxCapacity) {
        // Base 0 automatically handles hex (0x), octal (0), and decimal strings
        outputArray[count++] = (uint8_t)strtoul(token, NULL, 0);
        token = strtok(NULL, _delimiters);
    }
    return count;
}

uint16_t AutoPackClass::parseChar(char* inputMsg, char* outputArray, uint16_t maxCapacity) {
    if (inputMsg == NULL || outputArray == NULL) return 0;
    uint16_t count = 0;
    char* token = strtok(inputMsg, _delimiters);
    while (token != NULL && count < maxCapacity) {
        outputArray[count++] = token[0];
        token = strtok(NULL, _delimiters);
    }
    return count;
}

uint16_t AutoPackClass::parseString(char* inputMsg, String* outputArray, uint16_t maxCapacity) {
    if (inputMsg == NULL || outputArray == NULL) return 0;
    uint16_t count = 0;
    char* token = strtok(inputMsg, _delimiters);
    while (token != NULL && count < maxCapacity) {
        outputArray[count++] = String(token);
        token = strtok(NULL, _delimiters);
    }
    return count;
}
