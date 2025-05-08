#include <SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur d'initialisation de SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Erreur lors de la création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Création du rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur lors de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Boucle principale
    bool running = true;
    SDL_Event event;

    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Fond noir
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // noir
        SDL_RenderClear(renderer);

        // Ligne verte verticale
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // vert
        int centerX = WINDOW_WIDTH / 2;
        SDL_RenderDrawLine(renderer, centerX, 0, centerX, WINDOW_HEIGHT);

        // Affichage
        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
