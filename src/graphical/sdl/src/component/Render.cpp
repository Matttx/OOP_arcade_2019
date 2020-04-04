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
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    srcRect.x = 0;
    srcRect.y = 0;
    dstRect.x = 0;
    dstRect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
}

Render::~Render()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sprite);
}