#ifndef UP_SWEEP_H
#define UP_SWEEP_H

#include <Arduino.h>

#include "Pattern.h"
#include "List.h"

// A single frame in a sequence. All 64 LEDs are represented in the pattern from
// bottom to top, left to right, front to back.
struct Frame {
    bool pattern[64];
};

// The sequences are stored like this because the memory is too small on
// the Arduino to store all the sequences as separate JSON files.

List<Frame> upSweepFrames();
List<Frame> downSweepFrames();
List<Frame> frontSweepFrames();

#endif // UP_SWEEP_H
