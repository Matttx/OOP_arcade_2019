/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#ifndef RENDER_HPP_
#define RENDER_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <vector>

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace sdl {

namespace component {
/**
 * @class Render 
 * 
 */
class Render : public engine::component::ARender {
    public:
        /**
         * @brief Construct a new Render object
         * 
         * @param entity : the entity of the component 
         * @param paths : vector of paths of sprite
         * @param renderer : a SDL_renderer in order to create other SDL components
         */
        Render(engine::ecs::Entity &entity, const std::vector<std::string> &paths,
        SDL_Renderer *renderer);
        /**
         * @brief Destroy the Render object
         * 
         */
        ~Render() override;
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
         * @brief srcRect : the position x and y on the sprite
         * 
         */
        SDL_Rect srcRect {0, 0, 0, 0};
        /**
         * @brief dstRect : the position x and y on the screen
         * 
         */
        SDL_Rect dstRect {0, 0, 0, 0};
    protected:
    private:
};

} // Namespace component
} // Namespace sdl

#endif /* !RENDER_HPP_ */
