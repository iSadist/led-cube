#include "EventListener.h"
#include <Arduino.h>

EventListener::EventListener() {
}

EventListener::~EventListener() {}

bool EventListener::readButton(int value) {
    return value > 500; // 1023 is the highest value and typically the value of the button when pressed
}

int EventListener::listen() {
    const int NO_CHOICE = 0;
    int choice = NO_CHOICE;

    int muteButton = analogRead(A0); // Not existing on the board
    int nextButton = analogRead(A1);
    int speedControlButton = analogRead(A2);

    if (readButton(nextButton)) {
        choice = 2;
    } else if (readButton(speedControlButton)) {
        choice = 3;
    }

    // Check if the button is still pressed down.
    if (choice == previousChoice) {
        return NO_CHOICE;
    }

    if (previousChoice != choice) {
        unsigned long currentMillis = millis();

        if (currentMillis - previousChoiceTime < 250) {
            return NO_CHOICE;
        }
    }

    previousChoice = choice;
    previousChoiceTime = millis();

    return choice;
}