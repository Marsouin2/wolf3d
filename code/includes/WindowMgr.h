#include <SDL2/SDL.h>
#include <iostream>

class WindowMgr 
{
private:
    int _height;
    int _width;
    SDL_Window* _window;
public:
    //WindowMgr() = delete; // nique le ctor sans param
    //WindowMgr(const int &rHeight, const int &rWidth);
    virtual ~WindowMgr();

    SDL_Window* getWindow() { return _window; }
    int drawWindow(void);
    void deleteWindow(void);
};