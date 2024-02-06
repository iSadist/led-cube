#include "Pattern.h"

#include <Arduino.h>

Pattern emptyCube() {
    Pattern p;
    for (int i = 0; i < 64; i++) {
        LED led;
        led.pin = i;
        led.layer = i / 16;
        led.state = false;
        p.leds.push_back(led);
    }
    return p;
}

Pattern fullCube() {
    Pattern p;
    for (int i = 0; i < 64; i++) {
        LED led;
        led.pin = i;
        led.layer = i / 16;
        led.state = true;
        p.leds.push_back(led);
    }
    return p;
}

Pattern randomCube() {
    Pattern p;
    for (int i = 0; i < 64; i++) {
        LED led;
        led.pin = i;
        led.layer = i / 16;
        led.state = random(0, 2);
        p.leds.push_back(led);
    }
    return p;
}

Pattern innerCore() {
    Pattern p;
    int pins[] = { 6, 7, 10, 11 };
    for (int pinIndex = 0; pinIndex < 4; pinIndex++) {
        for (int layer = 1; layer < 3; layer++) {
            int pin = pins[pinIndex];
            LED led;
            led.pin = pin;
            led.layer = layer;
            led.state = true;
            p.leds.push_back(led);
        }
    }

    return p;
}