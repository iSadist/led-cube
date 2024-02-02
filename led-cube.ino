#include "Arduino.h"
#include "variables.h"
#include "pin-selection.h"
#include "modes.h"

void setup_pins() {
  // Loop over LAYER_PINS and GROUND_PINS and set them to OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(LAYER_PINS[i], OUTPUT);
    pinMode(GROUND_PINS[i], OUTPUT);
  }

  pinMode(INHERIT_PIN, OUTPUT);
}

// Main setup function
void setup() {
  setup_pins();
  Serial.begin(9600); // Serial monitor
}

/**
 * Main loop function for the Arduino.
 * This function is called repeatedly by the Arduino.
 * 
 * @param None
 * @return None
 */
void loop() {
  cubeLoop();
}

/**
 * Main loop function for the LED lights.
 * This function is called repeatedly by the Arduino.
 * 
 * @param None
 * @return None
 */
void cubeLoop() {
  fullLayerSweep(200);
  fullLayerFill(200);
  fullLayerReverseFill(200);
  fullVerticalLayerSweep(200, true);
  fullVerticalLayerSweep(200, false);
  randomLEDMode(50);
}
