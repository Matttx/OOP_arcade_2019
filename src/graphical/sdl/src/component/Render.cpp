/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#include "Render.hpp"

#include "../../../IGraphical.hpp"

using namespace sdl;
using namespace component;

Render::Render(engine::ecs::Entity& entity,
    const std::vector<std::string>& paths, SDL_Renderer* renderer)
    : engine::component::ARender(entity, paths)
{
    sprite = IMG_Load(paths[LIBTYPE::GRAPHIC].c_str());

    if (!sprite)
        throw std::runtime_error(
            std::string("SDL: Can't load image: ", SDL_GetError()).c_str());

    texture = SDL_CreateTextureFromSurface(renderer, sprite);

    if (!texture)
        throw std::runtime_error(std::string(
            "SDL: Can't create texture from surface: ", SDL_GetError())
                                     .c_str());

    SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
    SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
}

Render::~Render()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sprite);
}