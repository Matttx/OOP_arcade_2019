/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#include <iostream>
#include "Render.hpp"
#include "../../../IGraphical.hpp"

using namespace sdl;
using namespace component;

Render::Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths, SDL_Window* window) : engine::component::ARender(entity, paths)
{
    renderer = SDL_CreateRenderer(window, -1, 0);
    sprite = IMG_Load(paths[LIBTYPE::GRAPHIC].c_str());
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    srcRect = {0, 0};
    dstRect = {0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &srcRect->w, &srcRect->h);
    SDL_QueryTexture(texture, NULL, NULL, &dstRect->w, &dstRect->h);
}

Render::~Render()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sprite);
    SDL_DestroyRenderer(renderer);
}