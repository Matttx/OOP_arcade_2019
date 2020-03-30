/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main_test2
*/

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event e;
    int x = 288;
    int y = 208;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("Pacman Experiments",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
        480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * sprite = IMG_Load("assets/sprite.png");
    SDL_Texture * spriteTexture = SDL_CreateTextureFromSurface(renderer,
        sprite);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0.5);
    SDL_RenderClear(renderer);

    while (!quit)
    {
        SDL_Delay(20);
        Uint32 ticks = SDL_GetTicks();
        Uint32 pacSprite = (ticks / 500) % 2;
        SDL_Rect pacmanSrcRect = { 2 * 32, 0, 32, 32 };
        SDL_Rect pacmanDstRect = { x, y, 32, 32 };

        SDL_PollEvent(&e);
        // User requests quit
        if(e.type == SDL_QUIT)
        {
            quit = true;
        } else if (e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym)
            {
                case SDLK_UP:
                    y -= 3;
                    pacSprite = (ticks / 500) % 2;
                    pacmanSrcRect = { static_cast<int>(pacSprite + 5) * 32, 0, 32, 32 };
                    break;
                case SDLK_DOWN:
                    y += 3;
                    pacSprite = (ticks / 500) % 2;
                    pacmanSrcRect = { static_cast<int>(pacSprite + 7) * 32, 0, 32, 32 };
                    break;
                case SDLK_LEFT:
                    x -= 3;
                    pacSprite = (ticks / 500) % 2;
                    pacmanSrcRect = { static_cast<int>(pacSprite + 3) * 32, 0, 32, 32 };
                    break;
                case SDLK_RIGHT:
                    pacSprite = (ticks / 500) % 2;
                    pacmanSrcRect = { static_cast<int>(pacSprite) * 32, 0, 32, 32 };
                    x += 3;
                    break;
                default:
                    break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, spriteTexture, &pacmanSrcRect, &pacmanDstRect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(spriteTexture);
    SDL_FreeSurface(sprite);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}