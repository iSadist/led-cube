#include <Arduino.h>

#include "Controller.h"
#include "EventListener.h"
#include "variables.h"

Controller controller = Controller();
EventListener eventListener = EventListener();

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
  int event = eventListener.listen();

  switch (event) {
  case 0:
    break;
  case 1:
    controller.mute();
    break;
  case 2:
    Serial.println("Next mode");
    controller.nextMode();
    break;
  case 3:
    controller.increaseSpeed();
    break;
  }

  controller.loop();
}
