#include "PinSelector.h"

#include <Arduino.h>
#include "variables.h"

PinSelector::PinSelector() {}

PinSelector::~PinSelector() {}

void PinSelector::setBasePins(bool pins[2]) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(GROUND_PINS[i], pins[i] ? HIGH : LOW);
  }
}

void PinSelector::set_pins(bool pins[4]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LAYER_PINS[i], pins[i] ? HIGH : LOW);
  }
}

void PinSelector::setPin(int pin) {
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

void PinSelector::setBase(int layer) {
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

void PinSelector::selectLED(int pin, int layer) {
  // Set the layer pins
  setPin(pin);

  // Set the ground pins
  setBase(layer);
}

void PinSelector::selectLED(int pin[], int pinSize, int layer) {
  // Loop over the pins and select them for the specified layer
  for (int i = 0; i < pinSize; i++) {
    selectLED(pin[i], layer);
  }
}

void PinSelector::selectLayer(int layer) {
  int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15};
  selectLED(pins, 16, layer);
}

void PinSelector::selectVerticalLayer(int layer, bool isParallel) {
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

void PinSelector::selectColumn(int column) {
  selectLED(column, 0);
  selectLED(column, 1);
  selectLED(column, 2);
  selectLED(column, 3);
}

void PinSelector::selectOuterLayer() {
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

void PinSelector::selectInnerCore() {
  int pins[] = { 6, 7, 10, 11 };
  selectLED(pins, 4, 1);
  selectLED(pins, 4, 2);
}

void PinSelector::randomLED(int index) {
  if (index > 0) { return; }

  int pin = random(0, 16);
  int layer = random(0, 4);
  selectLED(pin, layer);
}

void PinSelector::randomLEDs(int amount) {
  for (int i = 0; i < amount; i++) {
    randomLED(0);
  }
}