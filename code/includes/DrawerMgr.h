#include <SDL2/SDL.h>

#include "WindowMgr.h"

class DrawerMgr
{
private: // attributes
    SDL_Renderer* _renderer;
private: // functions
    void setBackgroundBlack();

public: // attributes
public: // functions
    virtual ~DrawerMgr();
    DrawerMgr(SDL_Window *rWindow);
    int createRenderer(SDL_Window *rWindow);
    void drawPixel(); // ici ce serait bien qu'au lieu de prendre un bail SDL ca prenne genre une classe pour abstract SDL
    void setWindowBackground();
    void destroyRenderer(); // pareil ici 
};