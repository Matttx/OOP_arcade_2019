/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.hpp
*/

#ifndef OOP_ARCADE_2019_TEXT_HPP
#define OOP_ARCADE_2019_TEXT_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

#include "../../../../engine/component/AText.hpp"
namespace sdl {

namespace component {
class Text : public engine::component::AText {
  public:
    Text(engine::ecs::Entity& entity, const std::string& text,
        const std::vector<std::string>& paths, SDL_Renderer* renderer);
    ~Text() override;
    SDL_Surface* sprite;
    SDL_Texture* texture;
    SDL_Color color;
    TTF_Font* font;
    SDL_Rect srcRect {0, 0, 0, 0};
    SDL_Rect dstRect {0, 0, 0, 0};
};
} // namespace component
} // namespace sdl

#endif // OOP_ARCADE_2019_TEXT_HPP
