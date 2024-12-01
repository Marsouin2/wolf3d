#include "../includes/SingletonFileReader.h"

std::vector<char> SingletonFileReader::readAndGetFileContent(const std::string &rFilename)
{
    std::vector<char> retVal;

    std::ifstream file;
    char caracter;

    file.open(rFilename);
    if (!file)
    {
        std::cerr << "SingletonFileReader::readAndGetFileContent() - The file could not be opened !" << std::endl;
    }
    else
    {
        while (file >> caracter)
        {
            retVal.push_back(caracter);
        }
        std::cout << "SingletonFileReader::readAndGetFileContent() - The map has been successfully read !" << std::endl;
    }

    // Don't forget to close the file after opened it ;)
    file.close();

    return retVal;
}
