#include "EventListener.h"
#include <Arduino.h>

EventListener::EventListener(/* args */) {
}

EventListener::~EventListener() {}

bool EventListener::readButton(int value) {
    return value > 950; // 1023 is the highest value and typically the value of the button when pressed
}

int EventListener::listen() {
    int muteButton = analogRead(A0);
    int nextButton = analogRead(A1);
    int onOffButton = analogRead(A2);

    if (readButton(muteButton)) {
        return 1;
    } else if (readButton(nextButton)) {
        return 2;
    } else if (readButton(onOffButton)) {
        return 3;
    }

    // Remove below when the above is implemented fully
    int chance = random(0, 10000);

    if (chance < 1) {
        return 2;
    }

    return 0;
}