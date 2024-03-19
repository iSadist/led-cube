#include <Arduino.h>
#include "Controller.h"
#include "PinSelector.h"

Controller::Controller(/* args */) {
    currentMode = 0;
    stepIndex = 0;
    speedMultiplier = 1;
    muted = false;
    selector = PinSelector();
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

void Controller::setMode(int mode) {
    currentMode = mode;
}

void Controller::nextMode() {
    currentMode++;
    currentMode %= 8;
}

void Controller::increaseSpeed() {
    speedMultiplier += 1;

    if (speedMultiplier > 5) {
        speedMultiplier = 1;
    }
}

int Controller::getSpeed() {
    switch (speedMultiplier) {
    case 1:
        return 50;
    case 2:
        return 100;
    case 3:
        return 200;
    case 4:
        return 300;
    case 5:
        return 400;
    default:
        return 50;
    }
}

void Controller::getModePattern(int mode, int stepIndex) {
    int pinIndex = stepIndex / (this->maxStepIndex / this->getSpeed()) % 16;
    int layerIndex = stepIndex / (this->maxStepIndex / this->getSpeed()) % 4;

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
    case 6:
        selector.selectOuterLayer();
        break;
    case 7:
        selector.selectInnerCore();
        break;
    default:
        selector.selectLayer(layerIndex);
        break;
    }
}
