#include "FileReader.h"

FileReader::FileReader() {}

FileReader::~FileReader() {}

Pattern FileReader::convertToPattern(Frame frame)
{
    Pattern pattern;

    // Loop over each LED in the frame
    for (int i = 0; i < 64; i++)
    {
        bool isOn = frame.pattern[i] == 1;

        if (isOn)
        {
            LED led;
            led.pin = i;
            led.layer = i / 16;
            led.state = isOn;

            pattern.leds.push_back(led);
        }
    }

    return pattern;
}

Sequence FileReader::convertToSequence(List<Frame> frames)
{
    Sequence sequence;

    // Loop over each frame
    for (int i = 0; i < frames.size(); i++)
    {
        Frame frame = frames.at(i);
        Pattern pattern = convertToPattern(frame);
        sequence.patterns.push_back(pattern);
    }

    return sequence;
}

List<Sequence> FileReader::readSequences(String folder_path)
{
    List<Sequence> sequences;
    List<Frame> frames = upSweepFrames();
    List<Frame> frames2 = downSweepFrames();
    List<Frame> frames3 = frontSweepFrames();
    Sequence sequence = convertToSequence(frames);
    sequences.push_back(sequence);
    return sequences;
}