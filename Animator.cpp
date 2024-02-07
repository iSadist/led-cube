#include "Animator.h"
#include "pin-selection.h"

#include <Arduino.h>

Animator::Animator() {}

Animator::~Animator() {}

Animator::addFrame(Pattern p) {
    sequence.push_back(p);
}

Animator::updateFrame(int stepIndex) {
    currentFrame = (stepIndex / 100) % sequence.size();
}

Animator::playFrame() {
    updateCube();
}

void Animator::updateCube() {
    Pattern p = sequence.at(currentFrame);
    List<LED> leds = p.leds;

    for (int i = 0; i < leds.size(); i++) {
        LED led = leds.at(i);
        selectLED(led.pin, led.layer);
    }
}