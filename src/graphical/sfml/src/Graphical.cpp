/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include "../../../engine/event/Input.hpp"
#include "../../AGraphical.hpp"
#include "component/Audio.hpp"
#include "component/Render.hpp"
#include "system/Audio.hpp"
#include "system/Render.hpp"

sfml::Graphical::Graphical(engine::eventbus::EventBus& eventBus)
    : graphical::AGraphical("sfml", LIBTYPE::GRAPHIC, eventBus)
{
    _window = nullptr;
}

sfml::Graphical::~Graphical()
{
    destroy();
}

extern "C" sfml::Graphical* create(engine::eventbus::EventBus* eventBus)
{
    return new sfml::Graphical(*eventBus);
}

void sfml::Graphical::init()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
}

void sfml::Graphical::dispatchEvent()
{
    sf::Event event {};
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            for (auto& i : KEYCORRESPONDENCE) {
                if (sf::Keyboard::isKeyPressed(i.first)) {
                    auto input = new engine::event::Input(i.second);
                    getEventBus().publish(*input);
                    delete input;
                }
            }
        }
    }
}

void sfml::Graphical::destroy()
{
    delete _window;
}

engine::component::AAudio& sfml::Graphical::createAudio(
    engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    return *(new sfml::component::Audio(entity, paths));
}

engine::component::ARender& sfml::Graphical::createRender(
    engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    return *(new sfml::component::Render(entity, paths));
}

engine::component::AText& sfml::Graphical::createText(
    engine::ecs::Entity &entity, const std::string &text, const std::vector<std::string> &paths)
{
    return *(new sfml::component::Text(entity, text, paths));
}

engine::system::AAudio& sfml::Graphical::createAudioSystem(
    engine::ecs::World& world)
{
    return *(new sfml::system::Audio(world));
}

engine::system::ARender& sfml::Graphical::createRenderSystem(
    engine::ecs::World& world)
{
    return *(new sfml::system::Render(world, *_window));
}
