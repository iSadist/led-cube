#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PinSelector.h"

class Controller {
private:
    int currentMode;
    int stepIndex;
    const int maxStepIndex = 12800; 
    bool muted;
    int speedMultiplier;
    PinSelector selector;
public:
    Controller(/* args */);
    ~Controller();

    /**
     * Main loop function for the LED lights.
     * This function is called repeatedly by the Arduino.
     * 
     * @param None
     * @return None
     */
    void loop();

    /**
     * Mutes the speaker.
     * 
     * @param None
     * @return None
     */
    void mute();

    /**
     * Turns off the LED cube.
     * 
     * @param None
     * @return None
     */
    void turnOff();

    /**
     * Increases the speed of the LED cube.
     * 
     * @param None
     * @return None
     */
    void increaseSpeed();

    /**
     * Gets the current speed of the LED cube.
     * 
     * @param None
     * @return The current speed of the LED cube.
     */
    int getSpeed();

    /**
     * Gets the current speed of the LED cube in random mode.
     * 
     * @param None
     * @return The current speed of the LED cube.
     */
    int getSpeedForRandom();

    /**
     * Sets the current mode of the LED cube. Mode 0 is the cube turned off.
     * 
     * @param mode The mode to set the LED cube to.
     * @return None
     */
    void setMode(int mode);

    /**
     * Changes the mode to the next mode.
     * 
     * @param None
     * @return None
     */
    void nextMode();

    /**
     * Gets the mode pattern for the current mode.
     * 
     * @param mode The mode to get the pattern for.
     * @param stepIndex The current step index.
     * @return None
     */
    void getModePattern(int mode, int stepIndex);
};

#endif // CONTROLLER_H