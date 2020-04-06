/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

#include "../../../IGraphical.hpp"

sdl::component::Text::Text(
    engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths, SDL_Renderer* renderer)
    : engine::component::AText(entity, text, paths)
{
    font = TTF_OpenFont(paths[LIBTYPE::GRAPHIC].c_str(), 100);

    if (!font)
        throw std::runtime_error(std::string("SDL: Can't load font: ", SDL_GetError()).c_str());

    color = SDL_Color {255, 255, 255, 0};
    sprite = TTF_RenderText_Blended(font, text.c_str(), color);

    if (!sprite)
        throw std::runtime_error(std::string("SDL: Can't render text: ", SDL_GetError()).c_str());

    texture = SDL_CreateTextureFromSurface(renderer, sprite);

    if (!texture)
        throw std::runtime_error(std::string("SDL: Can't create texture from surface: ", SDL_GetError()).c_str());

    SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
    SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
}

sdl::component::Text::~Text()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sprite);
    TTF_CloseFont(font);
}
