#ifndef PIN_SELECTION_FUNCTIONS_H
#define PIN_SELECTION_FUNCTIONS_H

void setBasePins(bool pins[2]);
void set_pins(bool pins[4]);
void setPin(int pin);
void setBase(int layer);

void selectLED(int pin, int layer);
void selectLED(int pin[], int pinSize, int layer);
void selectLayer(int layer);
void selectVerticalLayer(int layer, bool isParallel);

void selectColumn(int column);

void selectOuterLayer();
void selectInnerCore();

void randomLED(int index);
void randomLEDs(int amount);

#endif // PIN_SELECTION_FUNCTIONS_H