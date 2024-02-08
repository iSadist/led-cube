#ifndef FILE_READER_H
#define FILE_READER_H

#include <Arduino.h>

#include "List.h"
#include "Sequences.h"
#include "Pattern.h"

class FileReader
{
private:
    Pattern convertToPattern(Frame frame);
    Sequence convertToSequence(List<Frame> frames);
public:
    FileReader();
    ~FileReader();

    /**
     * Reads all the sequences from the folder.
     * 
     * @param folder_path The path to the folder to read the sequences from.
     * @return List<Sequence> The list of sequences read from the folder.
     */
    List<Sequence> readSequences(String folder_path);
};

#endif // FILE_READER_H