#include "Animator.h"
#include "pin-selection.h"

#include <Arduino.h>

Animator::Animator() {
    this->sequence = List<Pattern>();
    this->currentFrame = 0;
}

Animator::Animator(Sequence sequence) {
    this->sequence = sequence.patterns;
    this->currentFrame = 0;
}

Animator::~Animator() {}

void Animator::addFrame(Pattern p) {
    sequence.push_back(p);
}

void Animator::updateFrame(int stepIndex) {
    currentFrame = (stepIndex / 100) % sequence.size();
}

void Animator::playFrame() {
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