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
/**
 * @class Text
 * 
 */
class Text : public engine::component::AText {
  public:
    /**
     * @brief Construct a new Text object
     * 
     * @param entity : the entity of the component
     * @param text : the text to display
     * @param paths : vector of paths of fonts
     * @param renderer : the renderer in order to create other SDL objects
     */
    Text(engine::ecs::Entity& entity, const std::string& text,
        const std::vector<std::string>& paths, SDL_Renderer* renderer);    /**
     * @brief Destroy the Text object
     * 
     */
    ~Text() override;
    /**
     * @brief sprite : correspond to the sprite load
     * 
     */
    SDL_Surface *sprite;
    /**
     * @brief texture : correspond to the texture to display
     * 
     */
    SDL_Texture *texture;
    /**
     * @brief color : the color of the text
     * 
     */
    SDL_Color color;
    /**
     * @brief font : the font of the text
     * 
     */
    TTF_Font* font;
    /**
     * @brief srcRect : the position x and y on the sprite
     * 
     */
    SDL_Rect srcRect {0, 0, 0, 0};
    /**
     * @brief dstRect : the position x and y on the screen
     * 
     */
    SDL_Rect dstRect {0, 0, 0, 0};
};
}
}

#endif // OOP_ARCADE_2019_TEXT_HPP
