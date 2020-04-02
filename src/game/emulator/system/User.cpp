/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/Transform.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../component/User.hpp"

game::emulator::system::User::User(engine::ecs::World& world) : AUser(world)
{
}

game::emulator::system::User::~User()
{
}

void game::emulator::system::User::init()
{
    auto &eventBus = this->getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &User::inputHandler);
}

void game::emulator::system::User::update()
{
    auto entities = this->getWorld().getEntities<game::emulator::component::User>();
    auto &games = this->getWorld().getGroup("games");
    auto &graphicals = this->getWorld().getGroup("graphicals");

    for (const auto& entity : entities) {
        auto &user = entity.get().getComponent<game::emulator::component::User>();
        auto &transform = entity.get().getComponent<engine::component::Transform>();
        auto &size = entity.get().getComponent<engine::component::Size>();

        if (user.step == component::User::CHOOSE_GAME) {
            if ((unsigned long) user.buttonIndex < games.size()) {
                auto &button = games[user.buttonIndex].get();
                auto &buttonTransform = button.getComponent<engine::component::Transform>();
                auto &buttonSize = button.getComponent<engine::component::Size>();
                int deltaX = (buttonSize.width - size.width) / 2;
                int deltaY = (buttonSize.height - size.height) / 2;

                transform.position.x = buttonTransform.position.x + deltaX;
                transform.position.y = buttonTransform.position.y + deltaY;
            }
        } else {
            if ((unsigned long) user.buttonIndex < graphicals.size()) {
                auto &button = graphicals[user.buttonIndex].get();
                auto &buttonTransform = button.getComponent<engine::component::Transform>();
                auto &buttonSize = button.getComponent<engine::component::Size>();
                int deltaX = (buttonSize.width - size.width) / 2;
                int deltaY = (buttonSize.height - size.height) / 2;

                transform.position.x = buttonTransform.position.x + deltaX;
                transform.position.y = buttonTransform.position.y + deltaY;
            }
        }
    }
}

void game::emulator::system::User::render()
{
}

void game::emulator::system::User::inputHandler(engine::event::Input& input)
{
    auto entities = this->getWorld().getEntities<game::emulator::component::User>();
    auto &games = this->getWorld().getGroup("games");
    auto &graphicals = this->getWorld().getGroup("graphicals");

    for (const auto& entity : entities) {
        auto &user = entity.get().getComponent<game::emulator::component::User>();

        if (input.code == engine::event::Input::KEY_UP)
            user.buttonIndex = user.buttonIndex - 1;
        if (input.code == engine::event::Input::KEY_DOWN)
            user.buttonIndex = user.buttonIndex + 1;

        if (user.step == component::User::CHOOSE_GAME) {
            if (user.buttonIndex < 0)
                user.buttonIndex = (int) games.size() - 1;
            user.buttonIndex %= games.size();

            if (input.code == engine::event::Input::KEY_ENTER) {
                user.step = component::User::CHOOSE_GRAPHICAL;
                user.buttonIndex = 0;
            }
        } else {
            if (user.buttonIndex < 0)
                user.buttonIndex = (int) graphicals.size() - 1;
            user.buttonIndex %= graphicals.size();

            if (input.code == engine::event::Input::KEY_BACKSPACE) {
                user.step = component::User::CHOOSE_GAME;
                user.buttonIndex = 0;
            }
        }
    }
}
