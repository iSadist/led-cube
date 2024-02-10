#include "pin-selection.h"
#include "Arduino.h"
#include "variables.h"

/**
 * Low level function that sets the base pins for a given layer of the LED cube.
*/
void setBasePins(bool pins[2]) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(GROUND_PINS[i], pins[i] ? HIGH : LOW);
  }
}

/**
 * Low level function that sets the layer pins for a given layer of the LED cube.
*/
void set_pins(bool pins[4]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LAYER_PINS[i], pins[i] ? HIGH : LOW);
  }
}

/**
 * Sets the layer pins for a given layer of the LED cube.
 * 
 * @param pin The pin for which to set the layer pins.
 *           Valid values are 0 to 15.
*/
void setPin(int pin) {
  if (pin < 0 || pin > 15) {
    return;
  }

  // Map the pin connections on the board
  int pinMap[] = {0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15, 8, 9, 10, 11};
  pin = pinMap[pin];

  bool pins[4];
  for (int i = 0; i < 4; i++) {
    pins[i] = pin % 2;
    pin /= 2;
  }

  set_pins(pins);
}

/**
 * Sets the base pins for a given layer of the LED cube.
 * 
 * @param layer The layer for which to set the base pins.
 *              Valid values are 0, 1, 2, and 3.
 */
void setBase(int layer) {
  if (layer < 0 || layer > 3) {
    return;
  }

  // Correct for the connections on the board are differently placed.
  int pinMap[] = {1, 2, 3, 0};
  layer = pinMap[layer];

  bool pins[2] = { false, false };
  pins[0] = layer & 1; // Check the least significant bit
  pins[1] = layer & 2; // Check the second least significant bit

   setBasePins(pins);
}

void selectLED(int pin, int layer) {
  // Set the layer pins
  setPin(pin);

  // Set the ground pins
  setBase(layer);
}

/**
 * Selects an array of LED on the LED cube for a specified layer.
 * 
 * @param pin The pins to select.
 * @param pinSize The size of the pin array.
 * @param layer The layer to select the pins on.
 * 
 * @return None
*/
void selectLED(int pin[], int pinSize, int layer) {
  // Loop over the pins and select them for the specified layer
  for (int i = 0; i < pinSize; i++) {
    selectLED(pin[i], layer);
  }
}

/**
 * Selects all the lights on a layer.
 * 
 * @param layer The layer to select the lights on.
 * @return None
*/
void selectLayer(int layer) {
  int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15};
  selectLED(pins, 16, layer);
}

/**
 * Selects all the lights on a vertical layer.
 * 
 * @param layer The layer to select the lights on.
 * @param isParallel Whether or not the layer is parallel to the front side or not.
 * @return None
*/
void selectVerticalLayer(int layer, bool isParallel) {
  if (isParallel) {
    int columns[] = { layer * 4, layer * 4 + 1, layer * 4 + 2, layer * 4 + 3 };

    for (int i = 0; i < 4; i++) {
      selectColumn(columns[i]);
    }
  } else {
    int columns[] = { layer, layer + 4, layer + 8, layer + 12 };

    for (int i = 0; i < 4; i++) {
      selectColumn(columns[i]);
    }
  }
}

void selectColumn(int column) {
  selectLED(column, 0);
  selectLED(column, 1);
  selectLED(column, 2);
  selectLED(column, 3);
}

void selectOuterLayer() {
  selectLayer(0);
  selectLayer(3);
  selectColumn(0);
  selectColumn(1);
  selectColumn(2);
  selectColumn(3);
  selectColumn(5);
  selectColumn(8);
  selectColumn(9);
  selectColumn(12);
  selectColumn(13);
  selectColumn(14);
  selectColumn(15);
}

void selectInnerCore() {
  int pins[] = { 6, 7, 10, 11 };
  selectLED(pins, 4, 1);
  selectLED(pins, 4, 2);
}

/**
 * Selects a random LED on the LED cube.
*/
void randomLED() {
  int pin = random(0, 16);
  int layer = random(0, 4);
  selectLED(pin, layer);
}

/**
 * Randomly selects an LED on the LED cube.
 * 
 * @param amount The amount of times to randomly select an LED.
 * @return None
*/
void randomLEDs(int amount) {
  for (int i = 0; i < amount; i++) {
    randomLED();
  }
}