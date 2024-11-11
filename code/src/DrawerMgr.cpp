#include "../includes/DrawerMgr.h"

DrawerMgr::~DrawerMgr()
{
    destroyRenderer();
}

int DrawerMgr::createRenderer(WindowMgr *rWindow)
{
    _renderer = SDL_CreateRenderer(rWindow->getWindow(), -1, SDL_RENDERER_ACCELERATED);

    return 0;
}

void DrawerMgr::destroyRenderer()
{
    SDL_DestroyRenderer(_renderer);
}

void DrawerMgr::setWindowBackground(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void DrawerMgr::drawPixel(void)
{
    // Dessin d'un pixel bleu au centre de l'écran
    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);  // bleu
    SDL_RenderDrawPoint(_renderer, 400, 300);           // centre de la fenêtre (800x600)
    SDL_RenderPresent(_renderer);
}