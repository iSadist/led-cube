#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Pattern.h"

#include "List.h"

// Module that take in an array of Patterns and plays them in sequence
class Animator
{
private:
    int currentFrame;
    List<Pattern> sequence;

    /**
     * Updates the LED cube with the current frame.
    */
    void updateCube();
public:
    Animator();
    Animator(Sequence sequence);
    ~Animator();

    /**
     * Adds a frame to the sequence.
     * 
     * @param p The pattern to add to the sequence.
     * @return None
    */
    void addFrame(Pattern p);

    /**
     * Updates the frame to the next one in the sequence.
     * 
     * @param stepIndex The step index given by the controller.
     * @return None
    */
    void updateFrame(int stepIndex);

    /**
     * Plays the current frame.
     * 
     * @param None
     * @return None
    */
    void playFrame();
};

#endif