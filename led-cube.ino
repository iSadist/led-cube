#include "Arduino.h"
#include "variables.h"
#include "pin-selection.h"
#include "modes.h"

// DOCS - if the user pressed any buttons, take action
void listen_to_input() {}

// DOCS - Return a binary sequence from a digital number. Example: 5 -> 0101, 3 -> 0011, 15 -> 1111
int to_binary(int digital) {
  return 0;
}

// DOCS - Translate the binary number to an array of the pins that should turn on.
//        Send in a boolean if the pins is for the ground selection or layer pins.
int binary_to_pins(int binary, bool is_ground_selection) {
  return 0;
}

void setup_pins() {
  // Loop over LAYER_PINS and GROUND_PINS and set them to OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(LAYER_PINS[i], OUTPUT);
    pinMode(GROUND_PINS[i], OUTPUT);
  }

  pinMode(INHERIT_PIN, OUTPUT);
}

/**
 * Sweeps the base of the LED cube.
 * This function sequentially sets the base of the LED cube to different values,
 * causing a sweeping effect.
 * 
 * @param None
 * @return None
 */
void baseSweep() {
  setBase(0);
  delay(DELAY_MS);
  setBase(1);
  delay(DELAY_MS);
  setBase(2);
  delay(DELAY_MS);
  setBase(3);
  delay(DELAY_MS);
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
