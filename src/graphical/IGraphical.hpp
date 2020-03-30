/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_IGRAPHICAL_HPP
#define OOP_ARCADE_2019_IGRAPHICAL_HPP

#include <AAudio.hpp>
#include <ARender.hpp>
#include <string>

#include "../engine/system/AAudio.hpp"
#include "../engine/system/ARender.hpp"

namespace graphical {

enum LIBTYPE { TEXT, GRAPHIC, DEBUG };

class IGraphical {
    virtual ~IGraphical() = 0;

    virtual void init() = 0;
    virtual void dispatchEvent() = 0;
    virtual void destroy() = 0;

    virtual std::string getName() const = 0;
    virtual LIBTYPE getType() const = 0;

    virtual engine::component::AAudio& createAudio(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;
    virtual engine::component::ARender& createRender(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;

    virtual engine::system::AAudio& createAudioSystem(
        engine::ecs::World& world) = 0;
    virtual engine::system::ARender& createRenderSystem(
        engine::ecs::World& world) = 0;
};
} // namespace graphical

#endif // OOP_ARCADE_2019_IGRAPHICAL_HPP
