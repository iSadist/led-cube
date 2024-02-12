#include "Animator.h"
#include <Arduino.h>

Animator::Animator() {
    this->currentFrame = 0;
    this->maxFrames = 8;
}

Animator::~Animator() {}

void Animator::addFrame(Pattern p) {
}

void Animator::updateFrame(int stepIndex) {
    currentFrame = (stepIndex / 100) % maxFrames;
}

void Animator::playFrame() {
    updateCube();
}

void Animator::updateCube() {
    // Switch on the current frame
    switch (currentFrame) {
        // case 0:
        //     // code for frame 0
        //     break;
        // case 1:
        //     // code for frame 1
        //     break;
        // ...
        default:
            // code for default case
            break;
    }
}