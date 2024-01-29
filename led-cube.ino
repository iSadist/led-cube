#include "variables.h"
#include "pin-selection.h"

// Make a data structure to 4x4x4 cube leds

// Add constants for the blinking patterns

// DOCS
void turn_off() {}

// DOCS
void turn_on() {}

// DOCS - switch pattern to 
void switch_pattern() {}

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

// DOCS - blink many lights at ones (in serial really quickly)
void blink_lights() {}

// DOCS - blink a single light
void blink_light(int index, int layer) {}

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

// Main loop function
void loop() {
  setPin(0);
  baseSweep();

  setPin(1);
  baseSweep();

  setPin(2);
  baseSweep();

  setPin(3);
  baseSweep();

  setPin(4);
  baseSweep();

  setPin(5);
  baseSweep();

  setPin(6);
  baseSweep();

  setPin(7);
  baseSweep();

  setPin(8);
  baseSweep();

  setPin(9);
  baseSweep();

  setPin(10);
  baseSweep();

  setPin(11);
  baseSweep();

  setPin(12);
  baseSweep();

  setPin(13);
  baseSweep();

  setPin(14);
  baseSweep();

  setPin(15);
  baseSweep();
}
