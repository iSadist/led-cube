int GROUND_PINS[] = {7, 4};
int LAYER_PINS[] = {12, 11, 10, 9};
int INHERIT_PIN = 13;

int BUTTON_PINS[] = {A0, A1, A2};

int DELAY_MS = 500;

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



void setBasePins(bool pins[2]) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(GROUND_PINS[i], pins[i] ? HIGH : LOW);
  }
}

void setup() {
  setup_pins();
  Serial.begin(9600); // Serial monitor
}

void baseSweep() {
  bool basePins[] = { false, false };
  setBasePins(basePins);
  delay(DELAY_MS);

  bool basePins1[] = { true, false };
  setBasePins(basePins1);
  delay(DELAY_MS);

  bool basePins2[] = { false, true };
  setBasePins(basePins2);
  delay(DELAY_MS);

  bool basePins3[] = { true, true };
  setBasePins(basePins3);
  delay(DELAY_MS);
}

void loop() {

  bool pins0[] = {false, false, true, false};
  set_pins(pins0);

  baseSweep();

  bool pins1[] = {true, false, false, false};
  set_pins(pins1);

  baseSweep();
}
