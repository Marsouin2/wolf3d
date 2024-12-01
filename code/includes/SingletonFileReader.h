#include <fstream>
#include <iostream>
#include <vector>

class SingletonFileReader
{
private:
    SingletonFileReader() {};

public:
    SingletonFileReader(const SingletonFileReader&) = delete;
    SingletonFileReader& operator=(const SingletonFileReader&) = delete;
    static SingletonFileReader& getInstance()
    {
        static SingletonFileReader instance;
        return instance;
    }

    std::vector<char> readAndGetFileContent(const std::string &rFilename);
};