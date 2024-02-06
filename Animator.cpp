#include "Animator.h"

#include <Arduino.h>

Animator::Animator(/* args */)
{
}

Animator::~Animator()
{
}

void Animator::updateCube() {
    Pattern p = sequence.get(currentFrame);
    for (int i = 0; i < 64; i++) {
        LED led = p.leds[i];
        digitalWrite(led.pin, led.state);
    }
}