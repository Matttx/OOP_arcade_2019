/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#ifndef RENDER_HPP_
#define RENDER_HPP_

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/ecs/Entity.hpp"
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace sdl {

namespace component {

class Render : public engine::component::ARender {
    public:
        Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths, SDL_Renderer *renderer);
        ~Render() override;
        SDL_Surface *sprite;
        SDL_Texture *texture;
        SDL_Rect srcRect;
        SDL_Rect dstRect;
    protected:
    private:
};

} // Namespace component
} // Namespace sdl

#endif /* !RENDER_HPP_ */
