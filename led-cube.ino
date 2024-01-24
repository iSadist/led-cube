int GROUND_PINS[] = {1, 2};
int LAYER_PINS[] = {12, 11, 10, 9};
int INHERIT_PIN = 13;

int DELAY_MS = 50;

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


// I want a function that takes in an array of 4 booleans and sets the pins to HIGH or LOW
// Example: {true, false, false, false} -> {HIGH, LOW, LOW, LOW}


void set_pins(bool pins[4]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LAYER_PINS[i], pins[i] ? HIGH : LOW);
  }
}

void setup() {
  setup_pins();
}

void loop() {
  bool pins0[] = {false, false, false, false};
  set_pins(pins0);
  delay(DELAY_MS);

  bool pins1[] = {true, false, false, false};
  set_pins(pins1);
  delay(DELAY_MS);

  bool pins2[] = {false, true, false, false};
  set_pins(pins2);
  delay(DELAY_MS);

  bool pins3[] = {true, true, false, false};
  set_pins(pins3);
  delay(DELAY_MS);

  bool pins4[] = {false, false, true, false};
  set_pins(pins4);
  delay(DELAY_MS);

  bool pins5[] = {true, false, true, false};
  set_pins(pins5);
  delay(DELAY_MS);

  bool pins6[] = {false, true, true, false};
  set_pins(pins6);
  delay(DELAY_MS);

  bool pins7[] = {true, true, true, false};
  set_pins(pins7);
  delay(DELAY_MS);

  bool pins8[] = {false, false, false, true};
  set_pins(pins8);
  delay(DELAY_MS);

  bool pins9[] = {true, false, false, true};
  set_pins(pins9);
  delay(DELAY_MS);

  bool pins10[] = {false, true, false, true};
  set_pins(pins10);
  delay(DELAY_MS);

  bool pins11[] = {true, true, false, true};
  set_pins(pins11);
  delay(DELAY_MS);

  bool pins12[] = {false, false, true, true};
  set_pins(pins12);
  delay(DELAY_MS);

  bool pins13[] = {true, false, true, true};
  set_pins(pins13);
  delay(DELAY_MS);

  bool pins14[] = {false, true, true, true};
  set_pins(pins14);
  delay(DELAY_MS);

  bool pins15[] = {true, true, true, true};
  set_pins(pins15);
  delay(DELAY_MS);
}
