#include <Arduino.h>
#include "Controller.h"
#include "PinSelector.h"

Controller::Controller(/* args */) {
    currentMode = 0;
    stepIndex = 0;
    muted = false;
    isOn = true;
    selector = PinSelector();
}

Controller::~Controller() {
}

void Controller::loop() {
    if (!isOn) return;

    stepIndex++;
    stepIndex %= this->maxStepIndex;

    getModePattern(currentMode, stepIndex);
}

void Controller::mute() {
    muted = !muted;
}

void Controller::turnOff() {
    isOn = !isOn;

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
        selector.selectLED(pinIndex, 3 - layerIndex);
        break;
    case 1:
        selector.randomLED(stepIndex % 128);
        break;
    case 2:
        selector.selectColumn(pinIndex);
        break;
    case 3:
        selector.selectLED(pinIndex, layerIndex);
        break;
    case 4:
        selector.selectVerticalLayer(layerIndex, false);
        break;
    case 5:
        selector.selectVerticalLayer(layerIndex, true);
        break;
    default:
        selector.selectLayer(layerIndex);
        break;
    }
}
