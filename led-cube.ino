#include <Arduino.h>
#include "Controller.h"
#include "EventListener.h"
#include "variables.h"
#include "pin-selection.h"
#include "modes.h"

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

  if (event != 0) {
    if (event == 1) {
      controller.mute();
    } else if (event == 2) {
      controller.nextMode();
    } else if (event == 3) {
      controller.turnOff();
    }
  }

  controller.loop();
}
