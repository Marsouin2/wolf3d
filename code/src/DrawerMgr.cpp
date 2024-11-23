#include "../includes/DrawerMgr.h"

DrawerMgr::DrawerMgr(SDL_Window *rWindow)
{
    if (!rWindow)
        std::cout << "Window is null !" << std::endl;
    else
        _renderer = SDL_CreateRenderer(rWindow, -1, SDL_RENDERER_ACCELERATED);


    if (!_renderer)
    {
        std::cout << "le renderer est null" << std::endl;
    }

    setBackgroundBlack();
}

DrawerMgr::~DrawerMgr()
{
    destroyRenderer();
}

void DrawerMgr::setBackgroundBlack(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

int DrawerMgr::createRenderer(SDL_Window *rWindow)
{
    _renderer = SDL_CreateRenderer(rWindow, -1, SDL_RENDERER_ACCELERATED);

    return 0;
}

void DrawerMgr::destroyRenderer(void)
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
}

void DrawerMgr::drawHorizontalLine(const int &length, const int &startPosX, const int &startPosY)
{
    int tempoStartPosX = startPosX;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);  // bleu
    while (tempoStartPosX != (startPosX + length))
    {
        SDL_RenderDrawPoint(_renderer, tempoStartPosX, startPosY);
        tempoStartPosX++;
    }
}

void DrawerMgr::drawVerticalLine(const int &length, const int &startPosX, const int &startPosY)
{
    int tempoStartPosY = startPosY;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);  // bleu
    while (tempoStartPosY != (startPosY + length))
    {
        SDL_RenderDrawPoint(_renderer, startPosX, tempoStartPosY);
        tempoStartPosY++;
    }
}

void DrawerMgr::renderWindow(void)
{
    SDL_RenderPresent(_renderer);
}
