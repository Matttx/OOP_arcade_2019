/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

#include "../../../IGraphical.hpp"

sdl::component::Text::Text(engine::ecs::Entity& entity, const std::string& text,
    const std::vector<std::string>& paths, SDL_Renderer* renderer)
    : engine::component::AText(entity, text, paths)
{
    font = TTF_OpenFont(paths[LIBTYPE::GRAPHIC].c_str(), 30);
    color = SDL_Color {255, 255, 255, 255};
    sprite = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    srcRect.x = 0;
    srcRect.y = 0;
    dstRect.x = 0;
    dstRect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
}
