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

Render::Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths) : engine::component::ARender(entity, paths)
{
    renderer = SDL_CreateRenderer(window, -1, 0);
    sprite = IMG_Load(paths[LIBTYPE::GRAPHIC]);
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    std::cout << "x = " << texture->x << " y = " << texture->y << " w = " << texture->w << " h = " << texture->h << std::endl;
}