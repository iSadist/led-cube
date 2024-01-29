#include "variables.h"

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

void set_pins(bool pins[4]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LAYER_PINS[i], pins[i] ? HIGH : LOW);
  }
}



void setBasePins(bool pins[2]) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(GROUND_PINS[i], pins[i] ? HIGH : LOW);
  }
}

// Select the layer to be active. 0 is the bottom layer, 3 is the top layer.
void setBase(int layer) {
  if (layer < 0 || layer > 3) {
    return;
  }

  if (layer == 0) {
    bool pins[] = { true, false };
    setBasePins(pins);
    return;
  }

  if (layer == 1) {
    bool pins[] = { false, true };
    setBasePins(pins);
    return;
  }

  if (layer == 2) {
    bool pins[] = { false, false };
    setBasePins(pins);
    return;
  }

  if (layer == 3) {
    bool pins[] = { true, true };
    setBasePins(pins);
    return;
  }
}

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

  bool pins0[] = {false, false, true, false};
  set_pins(pins0);

  baseSweep();

  bool pins1[] = {true, true, false, false};
  set_pins(pins1);

  baseSweep();
}
