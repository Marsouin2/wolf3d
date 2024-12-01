#include <iostream>

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

    void doSomething() { std::cout << "Je suis le singleton" << std::endl; }
};