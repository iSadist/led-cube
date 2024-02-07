#ifndef PATTERN_H
#define PATTERN_H

#include "List.h"

using namespace std;

// An object that represents the LED cube 4x4x4 pattern and the state of each LED

struct LED {
    int pin;
    int layer;
    bool state;
};

struct Pattern
{
    List<LED> leds;
};

struct Sequence {
    List<Pattern> patterns;
};

#endif