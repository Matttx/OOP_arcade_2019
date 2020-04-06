/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#ifndef SYSTEM_RENDER_HPP_
#define SYSTEM_RENDER_HPP_

#include <SDL2/SDL.h>

#include "../../../../engine/system/ARender.hpp"

namespace sdl {
namespace system {
/**
 * @class Render that inherits from ARender
 *
 */
class Render : public engine::system::ARender {
  public:
    /**
     * @brief Construct a new Render object
     *
     * @param world : the world of the entity
     * @param renderer : the renderer in order to create other SDL components
     */
    Render(engine::ecs::World& world, SDL_Renderer& renderer);
    /**
     * @brief Destroy the Render object
     *
     */
    ~Render() override = default;

    /**
     * @brief init : init the Render system
     *
     */
    void init() override;
    /**
     * @brief update : update the Render system
     *
     */
    void update() override;
    /**
     * @brief render : render the Render system
     *
     */
    void render() override;

  private:
    /**
     * @brief _renderer : reference to a renderer in order to give it in parameter to use it in other SDL contexts
     *
     */
    SDL_Renderer& _renderer;
};

} // Namespace system
} // Namespace sdl

#endif /* !RENDER_HPP_ */