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

  if (pin == 0) {
    bool pins[] = { false, false, false, false };
    set_pins(pins);
    return;
  }

  if (pin == 1) {
    bool pins[] = { true, false, false, false };
    set_pins(pins);
    return;
  }

  if (pin == 2) {
    bool pins[] = { false, true, false, false };
    set_pins(pins);
    return;
  }

  if (pin == 3) {
    bool pins[] = { true, true, false, false };
    set_pins(pins);
    return;
  }

  if (pin == 4) {
    bool pins[] = { false, false, true, false };
    set_pins(pins);
    return;
  }

  if (pin == 5) {
    bool pins[] = { true, false, true, false };
    set_pins(pins);
    return;
  }

  if (pin == 6) {
    bool pins[] = { false, true, true, false };
    set_pins(pins);
    return;
  }

  if (pin == 7) {
    bool pins[] = { true, true, true, false };
    set_pins(pins);
    return;
  }

  if (pin == 8) {
    bool pins[] = { true, true, true, true };
    set_pins(pins);
    return;
  }

  if (pin == 9) {
    bool pins[] = { false, true, true, true };
    set_pins(pins);
    return;
  }

  if (pin == 10) {
    bool pins[] = { true, false, true, true };
    set_pins(pins);
    return;
  }

  if (pin == 11) {
    bool pins[] = { false, false, true, true };
    set_pins(pins);
    return;
  }

  if (pin == 12) {
    bool pins[] = { true, true, false, true };
    set_pins(pins);
    return;
  }

  if (pin == 13) {
    bool pins[] = { false, true, false, true };
    set_pins(pins);
    return;
  }

  if (pin == 14) {
    bool pins[] = { true, false, false, true };
    set_pins(pins);
    return;
  }

  if (pin == 15) {
    bool pins[] = { false, false, false, true };
    set_pins(pins);
    return;
  }
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
