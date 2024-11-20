#include "../includes/WindowMgr.h"

WindowMgr::WindowMgr(const int &rHeight, const int &rWidth) : _height(rHeight), _width(rWidth)
{
    if (-1 == drawWindow())
    {
        deleteWindow();
    }
}

WindowMgr::~WindowMgr(void)
{
    deleteWindow();
}

void WindowMgr::deleteWindow(void)
{
    SDL_DestroyWindow(_window);
}

int WindowMgr::drawWindow(void)
{
    int retVal = 0;
    // Création de la fenêtre
    _window = SDL_CreateWindow("wolf3d",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               _width, _height, SDL_WINDOW_SHOWN);
    if (!_window) 
    {
        std::cout << "Erreur de création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        retVal = -1;
    }

    return retVal;
}
