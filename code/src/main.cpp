#include <SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* argv[]) 
{
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cerr << "Erreur d'initialisation de SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) 
    {
        std::cerr << "Erreur lors de la création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    const int gameMap[9][12] = 
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };

    // Création du rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
    {
        std::cerr << "Erreur lors de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Boucle principale
    bool running = true;
    SDL_Event event;

    int playerPositionX = WINDOW_WIDTH / 2;
    int playerPositionY = WINDOW_HEIGHT / 2;

    while (running) 
    {
        // Gestion des événements
        while (SDL_PollEvent(&event)) 
        {
            //Select surfaces based on key press
            if (SDL_KEYDOWN == event.type) // key has been pressed (not released yet)
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
                        if (19 < playerPositionY)
                        {
                            playerPositionY -= 20;
                        }
                        break;

                    case SDLK_DOWN:
                        if (580 > playerPositionY)
                        {
                            playerPositionY += 20;
                        }
                        break;

                    case SDLK_LEFT:
                        if (19 < playerPositionX)
                        {
                            playerPositionX -= 20;
                        }
                        break;

                    case SDLK_RIGHT:
                        if (780 > playerPositionX)
                        {
                            playerPositionX += 20;
                        }
                        break;

                    case SDLK_ESCAPE:
                        running = false;
                        break;

                    default :
                        std::cout << "Unknown key has been pressed out : nothing will happens..." << std::endl;
                        break;
                }
            }

            if (event.type == SDL_QUIT) 
            {
                running = false;
            }
        }

        // Fond noir
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // noir
        SDL_RenderClear(renderer);

        // render walls in blue
        for (int i = 0; i < 9; ++i)
        {
            for (int y = 0; y < 12; ++y)
            {
                if (gameMap[i][y] == 1) 
                {
                    // render a wall
                    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
                    //                  x    y   width height
                    SDL_Rect wall = { y*64, i*64, 64, 64 };
                    //SDL_RenderDrawRect( renderer, &player );
                    // Draw filled square
                    SDL_RenderFillRect(renderer, &wall);
                }
            }
        }

        // basic square representing the player
        SDL_SetRenderDrawColor( renderer, 255, 165, 0, 255 );
        //                  x    y   width height
        SDL_Rect player = { playerPositionX, playerPositionY, 12, 12 };
        //SDL_RenderDrawRect( renderer, &player );
        // Draw filled square
        SDL_RenderFillRect(renderer, &player);

        // render line of where the player is looking at (x start, y start, x end, y end)
        SDL_RenderDrawLine(renderer, playerPositionX, playerPositionY, playerPositionX - 64, playerPositionY - 64);

        // Affichage
        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
