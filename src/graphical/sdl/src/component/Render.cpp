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

Render::Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths, SDL_Renderer* renderer) : engine::component::ARender(entity, paths)
{
    sprite = IMG_Load(paths[LIBTYPE::GRAPHIC].c_str());
    if (sprite == nullptr)
        SDL_Log("IMG_Load: %s", SDL_GetError());
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    if (texture == nullptr)
        SDL_Log("SDL_CreateTextureFromSurface: %s", SDL_GetError());
    srcRect = {0, 0, 0, 0};
    dstRect = {0, 0, 0, 0};
    if (SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h) == -1)
        SDL_Log("SDL_QueryTexture #1: %s", SDL_GetError());
    if (SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h) == -1)
        SDL_Log("SDL_QueryTexture #2: %s", SDL_GetError());
}

Render::~Render()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sprite);
}