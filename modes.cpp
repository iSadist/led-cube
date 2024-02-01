#include <Arduino.h>
#include "pin-selection.h"
#include "variables.h"

/**
 * Fills the layers of the LED cube in an animation.
 * 
 * @param executionTime The amount of time to execute the sweep for.
 * @return None
*/
void fullLayerFill(int executionTime) {
  for (int i = 0; i < executionTime; i++) {
    selectLayer(0);
  }

  for (int i = 0; i < executionTime / 2; i++) {
    selectLayer(0);
    selectLayer(1);
  }

  for (int i = 0; i < executionTime / 3; i++) {
    selectLayer(0);
    selectLayer(1);
    selectLayer(2);
  }

  for (int i = 0; i < executionTime / 4; i++) {
    selectLayer(0);
    selectLayer(1);
    selectLayer(2);
    selectLayer(3);
  }
}

void fullLayerReverseFill(int executionTime) {
  for (int i = 0; i < executionTime / 4; i++) {
    selectLayer(0);
    selectLayer(1);
    selectLayer(2);
    selectLayer(3);
  }

  for (int i = 0; i < executionTime / 3; i++) {
    selectLayer(0);
    selectLayer(1);
    selectLayer(2);
  }

  for (int i = 0; i < executionTime / 2; i++) {
    selectLayer(0);
    selectLayer(1);
  }

  for (int i = 0; i < executionTime; i++) {
    selectLayer(0);
  }
}

/**
 * Randomly selects an LED on the LED cube. Uses delay in between.
 * 
 * @param amount The amount of times to randomly select an LED.
 * @return None
*/
void randomLEDMode(int amount) {
  for (int i = 0; i < amount; i++) {
    randomLED();
    delay(DELAY_MS);
  }
}

/**
 * Sweeps the layers of the LED cube.
 * 
 * @param executionTime The amount of time to execute the sweep for.
 * @return None
*/
void fullLayerSweep(int executionTime) {
  for (int i = 0; i < executionTime; i++) {
    selectLayer(0);
  }

  for (int i = 0; i < executionTime; i++) {
    selectLayer(1);
  }

  for (int i = 0; i < executionTime; i++) {
    selectLayer(2);
  }

  for (int i = 0; i < executionTime; i++) {
    selectLayer(3);
  }
}

/**
 * Sweeps the vertical layers of the LED cube.
 * 
 * @param executionTime The amount of time to execute the sweep for.
 * @param isParallel Whether or not the layers are parallel.
 * @return None
*/
void fullVerticalLayerSweep(int executionTime, bool isParallel) {
  for (int i = 0; i < executionTime; i++) {
    selectVerticalLayer(0, isParallel);
  }

  for (int i = 0; i < executionTime; i++) {
    selectVerticalLayer(1, isParallel);
  }

  for (int i = 0; i < executionTime; i++) {
    selectVerticalLayer(2, isParallel);
  }

  for (int i = 0; i < executionTime; i++) {
    selectVerticalLayer(3, isParallel);
  }
}