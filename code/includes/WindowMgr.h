#include <SDL2/SDL.h>
#include <iostream>

#ifndef WINDOWMGR_H_
#define WINDOWMGR_H_

class WindowMgr 
{
private:
    int _height;
    int _width;
    SDL_Window* _window;
public:
    //WindowMgr() = delete; // nique le ctor sans param
    //WindowMgr(const int &rHeight, const int &rWidth);
    WindowMgr(const int &rHeight, const int &rWidth);
    virtual ~WindowMgr();

    SDL_Window* getWindow() { return _window; }
    int drawWindow(void);
    void deleteWindow(void);
};

#endif // WINDOWMGR_H_