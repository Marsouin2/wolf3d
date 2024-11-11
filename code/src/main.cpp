#include <SDL2/SDL.h>
#include <iostream>

#include "../includes/DrawerMgr.h"
#include "../includes/WindowMgr.h"

// ---- class list :
// ---- class WindowMgr (handle window options) -> creer une interface pour tout type de map
// ---- class RenderMgr ? (le renderer est le bail qui va dessiner sur la window)
// ---- class InputMapParser (parse the map and store its content)
// ---- class InputHandler.h (handle user inputs from keyboard)

int main(int argc, char* argv[]) 
{
    uint8_t retVal = 0;

    if (argc != 1) // for now 1 but should be 2 (map as input)
    {
        std::cerr << "ERROR : usage = ./wolf3d <input_map.map>" << std::endl;
        retVal = -1;
    }
    else
    {
        // Check SDL initialization
        if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        {
            std::cerr << "SDL initialisation encountered a problem ! Error : " << SDL_GetError() << std::endl;
            return 1;
        }
        else
        {
            // everything is good (arg nb and SDL init OK)
            // parser la map en entree et donner les parametres a la classe (resolution etc...)
            WindowMgr windowMgr(800, 600); // QUESTION : creer sur le tas ou la pile la classe WindowMgr ?
            DrawerMgr drawerMgr;

            drawerMgr.setWindowBackground(windowMgr.getWindow())
            drawerMgr.drawPixel(windowMgr.getWindow());
            bool isRunning = true;
            SDL_Event event;
            while (isRunning) 
            {
                while (SDL_PollEvent(&event)) 
                {
                    if (event.type == SDL_QUIT) 
                    {
                        isRunning = false;
                    }
                }
            }
        }
    }

    return retVal;


    // Création du renderer
    /*SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
    {
        std::cerr << "Erreur de création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Couleur de fond : noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Dessin d'un pixel bleu au centre de l'écran
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // bleu
    SDL_RenderDrawPoint(renderer, 400, 300);           // centre de la fenêtre (800x600)
    SDL_RenderPresent(renderer);

    // Boucle d'attente avant la fermeture
    bool isRunning = true;
    SDL_Event event;
    while (isRunning) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                isRunning = false;
            }
        }
    }

    // Nettoyage et fermeture de SDL
    SDL_DestroyRenderer(renderer);
    SDL_Quit();*/

    return 0;
}
