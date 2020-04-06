/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include "../../../engine/event/Close.hpp"
#include "../../../engine/event/Input.hpp"
#include "../../AGraphical.hpp"
#include "component/Audio.hpp"
#include "component/Render.hpp"
#include "component/Text.hpp"
#include "system/Animations.hpp"
#include "system/Audio.hpp"
#include "system/Render.hpp"

sfml::Graphical::Graphical(engine::eventbus::EventBus& eventBus)
    : graphical::AGraphical("sfml", LIBTYPE::GRAPHIC, eventBus)
{
}

sfml::Graphical::~Graphical()
{
    if (_active)
        destroy();
}

extern "C" sfml::Graphical* create(engine::eventbus::EventBus* eventBus)
{
    return new sfml::Graphical(*eventBus);
}

void sfml::Graphical::init()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade");
    _view.reset(sf::FloatRect(0, 0, 1920, 1080));

    _window.setView(_view);
    _window.setMouseCursorVisible(false);

    _active = true;
}

void sfml::Graphical::dispatchEvent()
{
    sf::Event event {};
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            auto input = new engine::event::Input(KEYCORRESPONDENCE.at(event.key.code));

            getEventBus().publish(*input);

            delete input;
        }
        if (event.type == sf::Event::Closed) {
            auto close = new engine::event::Close();

            getEventBus().publish(*close);

            delete close;
        }
    }
}

void sfml::Graphical::destroy()
{
    _window.close();

    _active = false;
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
    engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
{
    return *(new sfml::component::Text(entity, text, paths));
}

engine::system::AAnimations& sfml::Graphical::createAnimationsSystem(engine::ecs::World& world)
{
    return *(new sfml::system::Animations(world));
}

engine::system::AAudio& sfml::Graphical::createAudioSystem(engine::ecs::World& world)
{
    return *(new sfml::system::Audio(world));
}

engine::system::ARender& sfml::Graphical::createRenderSystem(engine::ecs::World& world)
{
    return *(new sfml::system::Render(world, _window));
}
