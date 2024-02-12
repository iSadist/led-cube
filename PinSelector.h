#ifndef PIN_SELECTOR_H
#define PIN_SELECTOR_H

class PinSelector {
/**
 * @class PinSelector
 * @brief The PinSelector class is responsible for selecting pins and layers on an LED cube.
 * 
 * The PinSelector class provides methods for setting base pins, layer pins, and selecting LEDs on the LED cube.
 * It also includes methods for selecting random LEDs on the cube.
 */
private:
    /**
     * @brief Low level function that sets the base pins for a given layer of the LED cube.
     * 
     * This function is used internally by the PinSelector class to set the base pins for a specific layer of the LED cube.
     * 
     * @param pins An array of boolean values representing the base pins.
     */
    void setBasePins(bool pins[2]);

    /**
     * @brief Low level function that sets the layer pins for a given layer of the LED cube.
     * 
     * This function is used internally by the PinSelector class to set the layer pins for a specific layer of the LED cube.
     * 
     * @param pins An array of boolean values representing the layer pins.
     */
    void set_pins(bool pins[4]);

    /**
     * @brief Sets the layer pins for a given layer of the LED cube.
     * 
     * This function sets the layer pins for a specific layer of the LED cube.
     * 
     * @param pin The pin for which to set the layer pins. Valid values are 0 to 15.
     */
    void setPin(int pin);

    /**
     * @brief Sets the base pins for a given layer of the LED cube.
     * 
     * This function sets the base pins for a specific layer of the LED cube.
     * 
     * @param layer The layer for which to set the base pins. Valid values are 0, 1, 2, and 3.
     */
    void setBase(int layer);

public:
    /**
     * @brief Default constructor for the PinSelector class.
     */
    PinSelector();

    /**
     * @brief Destructor for the PinSelector class.
     */
    ~PinSelector();

    /**
     * @brief Selects a specific LED on the LED cube.
     * 
     * This function selects a specific LED on the LED cube by specifying the pin and layer.
     * 
     * @param pin The pin number of the LED to select.
     * @param layer The layer number of the LED to select.
     */
    void selectLED(int pin, int layer);

    /**
     * @brief Selects multiple LEDs on the LED cube.
     * 
     * This function selects multiple LEDs on the LED cube by specifying an array of pin numbers, the size of the array, and the layer number.
     * 
     * @param pin An array of pin numbers representing the LEDs to select.
     * @param pinSize The size of the pin array.
     * @param layer The layer number of the LEDs to select.
     */
    void selectLED(int pin[], int pinSize, int layer);

    /**
     * @brief Selects a specific layer on the LED cube.
     * 
     * This function selects a specific layer on the LED cube by specifying the layer number.
     * 
     * @param layer The layer number to select.
     */
    void selectLayer(int layer);

    /**
     * @brief Selects a vertical layer on the LED cube.
     * 
     * This function selects a vertical layer on the LED cube by specifying the layer number and whether it is parallel or not.
     * 
     * @param layer The layer number to select.
     * @param isParallel A boolean value indicating whether the layer is parallel or not.
     */
    void selectVerticalLayer(int layer, bool isParallel);

    /**
     * @brief Selects a specific column on the LED cube.
     * 
     * This function selects a specific column on the LED cube by specifying the column number.
     * 
     * @param column The column number to select.
     */
    void selectColumn(int column);

    /**
     * @brief Selects the outer layer of the LED cube.
     * 
     * This function selects the outer layer of the LED cube.
     */
    void selectOuterLayer();

    /**
     * @brief Selects the inner core of the LED cube.
     * 
     * This function selects the inner core of the LED cube.
     */
    void selectInnerCore();

    /**
     * @brief Selects a random LED on the LED cube.
     * 
     * This function selects a random LED on the LED cube by specifying the index.
     * 
     * @param index The index of the random LED to select.
     */
    void randomLED(int index);

    /**
     * @brief Randomly selects multiple LEDs on the LED cube.
     * 
     * This function randomly selects multiple LEDs on the LED cube by specifying the amount of times to randomly select an LED.
     * 
     * @param amount The amount of times to randomly select an LED.
     */
    void randomLEDs(int amount);
};

#endif
