#include <Arduino.h>
#include "Controller.h"
#include "Pattern.h"
#include "pin-selection.h"

Controller::Controller(/* args */) {
    currentMode = 0;
    stepIndex = 0;
}

Controller::~Controller() {
}

void Controller::loop() {
    stepIndex++;
    stepIndex %= this->maxStepIndex;

    getModePattern(currentMode, stepIndex);
}

void Controller::mute() {
    muted = !muted;
}

void Controller::turnOff() {
    currentMode = 0;
    // TODO: Should set inherit pin on multiplexer to 1
}

void Controller::setMode(int mode) {
    currentMode = mode;
}

void Controller::nextMode() {
    currentMode++;
    currentMode %= 8;
}

void Controller::getModePattern(int mode, int stepIndex) {
    int pinIndex = stepIndex / (this->maxStepIndex / 100) % 16;
    int layerIndex = stepIndex / (this->maxStepIndex / 100) % 4;

    switch (mode) {
    case 0:
        break;
    case 1:
        randomLED();
        break;
    case 2:
        selectColumn(pinIndex);
        break;
    case 3:
        selectLED(pinIndex, layerIndex);
        break;
    case 4:
        selectVerticalLayer(layerIndex, false);
        break;
    case 5:
        selectVerticalLayer(layerIndex, true);
        break;
    default:
        selectLayer(layerIndex);
        break;
    }
}
