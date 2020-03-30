/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include "../../AGraphical.hpp"

sfml::Graphical::Graphical(engine::eventbus::EventBus& eventBus)
    : _eventBus(eventBus)
{
}

sfml::Graphical::~Graphical()
{
    destroy();
}

extern "C" sfml::Graphical* createObject(engine::eventbus::EventBus& eventBus)
{
    return new sfml::Graphical(eventBus);
}

void sfml::Graphical::init()
{
}

void sfml::Graphical::dispatchEvent()
{
}

void sfml::Graphical::destroy()
{
}

engine::component::AAudio sfml::Graphical::createAudio(
    ecs::Entity& entity, const std::vector<std::string>& paths)
{
    _audios.emplace_back(entity, paths);
    return _audios.back();
}

engine::component::ARender sfml::Graphical::createRender(
    ecs::Entity& entity, const std::vector<std::string>& paths)
{
    _renders.emplace_back(entity, paths);
    return _renders.back();
}

engine::system::AAudio sfml::Graphical::createAudioSystem(
    engine::ecs::World& world)
{
    _sysAudios.emplace_back(world);
    return _sysAudios.back();
}

engine::system::ARender sfml::Graphical::createRenderSystem(
    engine::ecs::World& world)
{
    _sysRenders.emplace_back(world);
    return _sysRenders.back();
}
