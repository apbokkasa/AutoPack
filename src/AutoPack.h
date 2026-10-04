#ifndef AUTOPACK_H
#define AUTOPACK_H

#include <Arduino.h>

class AutoPackClass {
private:
    char _delimiters[8];
    uint8_t _delimCount;

public:
    AutoPackClass();

    void delimit(const char* delimiters);

    // Array Unpackers updated to uint16_t maxCapacity to support sizes up to 65,535
    uint16_t parseInt(char* inputMsg, int* outputArray, uint16_t maxCapacity);
    uint16_t parseFloat(char* inputMsg, float* outputArray, uint16_t maxCapacity);
    uint16_t parseByte(char* inputMsg, uint8_t* outputArray, uint16_t maxCapacity);
    uint16_t parseChar(char* inputMsg, char* outputArray, uint16_t maxCapacity);
    uint16_t parseString(char* inputMsg, String* outputArray, uint16_t maxCapacity);
};

extern AutoPackClass AutoPack;

#endif // AUTOPACK_H
