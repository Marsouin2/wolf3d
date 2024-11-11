#include <SDL2/SDL.h>

#include "WindowMgr.h"

class DrawerMgr
{
private:
    SDL_Renderer* _renderer;
public:
    DrawerMgr() = default;
    virtual ~DrawerMgr();

    int createRenderer(WindowMgr*rWindow);
    void drawPixel(); // ici ce serait bien qu'au lieu de prendre un bail SDL ca prenne genre une classe pour abstract SDL
    void setWindowBackground();
    void destroyRenderer(); // pareil ici 
};