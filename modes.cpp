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
    int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15};
  for (int i = 0; i < executionTime; i++) {
    selectLED(pins, 16, 0);
  }

  for (int i = 0; i < executionTime / 2; i++) {
    selectLED(pins, 16, 0);
    selectLED(pins, 16, 1);
  }

  for (int i = 0; i < executionTime / 3; i++) {
    selectLED(pins, 16, 0);
    selectLED(pins, 16, 1);
    selectLED(pins, 16, 2);
  }

  for (int i = 0; i < executionTime / 4; i++) {
    selectLED(pins, 16, 0);
    selectLED(pins, 16, 1);
    selectLED(pins, 16, 2);
    selectLED(pins, 16, 3);
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