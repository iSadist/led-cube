#ifndef FILE_READER_H
#define FILE_READER_H

#include <Arduino.h>

#include "List.h"
#include "Pattern.h"

class FileReader
{
private:

public:
    FileReader();
    ~FileReader();

    /**
     * Gets the names of all the files in the folder.
     * 
     * @param folder_path The path to the folder to get the file names from.
     * @return List<String> The list of file names in the folder.
     
    */
    List<String> getFileNames(String folder_path);
    
    /**
     * Reads the contents of a file.
     * 
     * @param file_path The path to the file to read.
     * @return String The contents of the file.
     */
    String readFile(String file_path);

    /**
     * Reads the sequence from a file content.
     * 
     * @param file_content The content of a file.
     * @return Sequence The sequence read from the file.
     */
    Sequence readSequence(String file_content);


    /**
     * Reads all the sequences from the folder.
     * 
     * @param folder_path The path to the folder to read the sequences from.
     * @return List<Sequence> The list of sequences read from the folder.
     */
    List<Sequence> readSequences(String folder_path);
};

#endif // FILE_READER_H