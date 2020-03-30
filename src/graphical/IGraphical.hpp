/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_IGRAPHICAL_HPP
#define OOP_ARCADE_2019_IGRAPHICAL_HPP

#include <string>


enum LIBTYPE { TEXT, GRAPHIC, DEBUG };

class IGraphical {
    virtual ~IGraphical() = 0;

    virtual void init() = 0;
    virtual void dispatchEvent() = 0;
    virtual void destroy() = 0;

    virtual std::string getName() const = 0;
    virtual LIBTYPE getType() const = 0;

    virtual engine::component::AAudio createAudio(
        const std::vector<std::string>& paths) = 0;
    virtual engine::component::ARender createRender(
        const std::vector<std::string>& paths) = 0;

    virtual engine::system::AAudio createAudioSystem(
        engine::ecs::World& world) = 0;
    virtual engine::system::ARender createRenderSystem(
        engine::ecs::World& world) = 0;
};

#endif // OOP_ARCADE_2019_IGRAPHICAL_HPP
