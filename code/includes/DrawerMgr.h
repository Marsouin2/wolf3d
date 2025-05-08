/*#include <SDL2/SDL.h>

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
    void drawVerticalLine(const int &length, const int &startPosX, const int &startPosY);
    void drawHorizontalLine(const int &length, const int &startPosX, const int &startPosY);
    
    // Display all what has been drawer since last renderWindow()
    void setWindowBackground(void);
    void renderWindow(void);
    void destroyRenderer(); // pareil ici 
};*/