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

class Render : public engine::system::ARender {
    public:
        Render(engine::ecs::World& world, SDL_Renderer& renderer);
        ~Render() override = default;

        void init() override;
        void update() override;
        void render() override;
    private:
        SDL_Renderer &_renderer;
};

} // Namespace system
} // Namespace sdl

#endif /* !RENDER_HPP_ */