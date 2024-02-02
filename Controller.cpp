#include <Arduino.h>
#include "Controller.h"
#include "pin-selection.h"
#include "modes.h"

Controller::Controller(/* args */) {
    currentMode = 0;
    stepIndex = 0;
}

Controller::~Controller() {
}

void Controller::loop() {
    stepIndex++;
    stepIndex %= 10000;

    getModePattern(currentMode, stepIndex);
}

void Controller::mute() {
    muted = !muted;
}

void Controller::turnOff() {
    currentMode = 0;
}

void Controller::setMode(int mode) {
    currentMode = mode;
}

void Controller::nextMode() {
    currentMode++;
    currentMode %= 8;
}

void Controller::getModePattern(int mode, int stepIndex) {
    switch (mode) {
    case 0:
        break;
    case 1:
        randomLED();
        break;
    case 2:
        selectColumn(stepIndex / 128 % 16);
        break;
    case 3:
        selectLED(stepIndex / 128 % 16, stepIndex / 256 % 4);
        break;
    case 4:
        selectVerticalLayer(stepIndex / 128 % 4, false);
        break;
    case 5:
        selectVerticalLayer(stepIndex / 128 % 4, true);
        break;
    default:
        selectLayer(stepIndex / 128 % 4);
        break;
    }
}
