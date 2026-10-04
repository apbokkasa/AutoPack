#include <Arduino.h>
#include <AutoPack.h>

void setup() {
    Serial.begin(9600);
    while (!Serial);

    // 1. Configure delimiters cleanly with a string (comma and space)
    AutoPack.delimit(", ");

    // 2. Setup a modifiable payload
    char msg[] = "10, 20, 30, 40, 50";
    
    // 3. Prepare the destination array
    int myNumbers[10];

    // 4. Unpack directly into the array
    uint8_t itemsFound = AutoPack.parseInt(msg, myNumbers, 10);

    Serial.print("Items successfully unpacked: ");
    Serial.println(itemsFound);

    for (uint8_t i = 0; i < itemsFound; i++) {
        Serial.print("myNumbers[");
        Serial.print(i);
        Serial.print("] = ");
        Serial.println(myNumbers[i]);
    }
}

void loop() {
    // Idle
}
