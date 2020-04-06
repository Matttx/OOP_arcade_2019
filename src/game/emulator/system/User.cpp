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
#include "../../../engine/event/Close.hpp"
#include "../component/Action.hpp"
#include "../component/User.hpp"

emulator::system::User::User(engine::ecs::World &world) : AUser(world)
{
}

emulator::system::User::~User()
{
}

void emulator::system::User::init()
{
    auto &eventBus = this->getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &User::inputManager);
}

void emulator::system::User::update()
{
    this->updateUserGame();
    this->updateUserGraphical();
}

void emulator::system::User::updateUserGame()
{
    auto userEntities = this->getWorld().getEntities<emulator::component::User>();
    auto &buttonEntities = this->getWorld().getGroup("games");

    for (const auto &userEntity : userEntities) {
        auto &user = userEntity.get().getComponent<emulator::component::User>();

        if (user.step != component::User::USERSTEP::GAME)
            continue;

        auto &transform = userEntity.get().getComponent<engine::component::Transform>();
        auto &size = userEntity.get().getComponent<engine::component::Size>();

        if ((unsigned long)(user.index) < buttonEntities.size()) {
            auto &button = buttonEntities.at(user.index).get();
            auto &buttonTransform = button.getComponent<engine::component::Transform>();
            auto &buttonSize = button.getComponent<engine::component::Size>();
            int deltaX = (buttonSize.width - size.width) / 2;
            int deltaY = (buttonSize.height - size.height) / 2;

            transform.position.x = buttonTransform.position.x + deltaX;
            transform.position.y = buttonTransform.position.y + deltaY;
        }
    }
}

void emulator::system::User::updateUserGraphical()
{
    auto userEntities = this->getWorld().getEntities<emulator::component::User>();
    auto &buttonEntities = this->getWorld().getGroup("graphicals");

    for (const auto &userEntity : userEntities) {
        auto &user = userEntity.get().getComponent<emulator::component::User>();

        if (user.step != component::User::USERSTEP::GRAPHICAL)
            continue;

        auto &transform = userEntity.get().getComponent<engine::component::Transform>();
        auto &size = userEntity.get().getComponent<engine::component::Size>();

        if ((unsigned long)(user.index) < buttonEntities.size()) {
            auto &button = buttonEntities.at(user.index).get();
            auto &buttonTransform = button.getComponent<engine::component::Transform>();
            auto &buttonSize = button.getComponent<engine::component::Size>();
            int deltaX = (buttonSize.width - size.width) / 2;
            int deltaY = (buttonSize.height - size.height) / 2;

            transform.position.x = buttonTransform.position.x + deltaX;
            transform.position.y = buttonTransform.position.y + deltaY;
        }
    }
}

void emulator::system::User::render()
{
}

void emulator::system::User::inputManager(engine::event::Input &input)
{
    auto userEntities = this->getWorld().getEntities<emulator::component::User>();
    int gameCount = this->getWorld().getGroup("games").size();
    int graphicalCount = this->getWorld().getGroup("graphicals").size();

    for (const auto &userEntity : userEntities) {
        auto &user = userEntity.get().getComponent<emulator::component::User>();

        if (input.code == engine::event::Input::KEY_UP)
            user.index = user.index - 1;
        if (input.code == engine::event::Input::KEY_DOWN)
            user.index = user.index + 1;

        if (user.step == component::User::GAME) {
            if (user.index < 0)
                user.index = gameCount - 1;

            this->inputManagerGame(input, user);
            user.index %= gameCount;
        } else if (user.step == component::User::GRAPHICAL) {
            if (user.index < 0)
                user.index = graphicalCount - 1;
            user.index %= graphicalCount;

            this->inputManagerGraphical(input, user);
        }
    }

    if (input.code == engine::event::Input::KEY_ESCAPE) {
        auto close = new engine::event::Close();

        this->getWorld().getUniverse().getEventBus().publish(*close);

        delete close;
    }
}

void emulator::system::User::inputManagerGame(engine::event::Input &input, emulator::component::User &user)
{
    auto userEntities = this->getWorld().getEntities<emulator::component::User>();
    auto &buttonEntities = this->getWorld().getGroup("games");

    if (input.code == engine::event::Input::KEY_BACKSPACE) {
        user.step = component::User::GRAPHICAL;
        user.index = 0;
    }

    if (input.code == engine::event::Input::KEY_ENTER) {
        auto &action = buttonEntities.at(user.index).get().getComponent<emulator::component::Action>();

        action.callback(this->getWorld().getUniverse());
    }
}

void emulator::system::User::inputManagerGraphical(engine::event::Input &input, emulator::component::User &user)
{
    auto userEntities = this->getWorld().getEntities<emulator::component::User>();
    auto &buttonEntities = this->getWorld().getGroup("graphicals");

    if (input.code == engine::event::Input::KEY_ENTER) {
        auto &action = buttonEntities.at(user.index).get().getComponent<emulator::component::Action>();

        user.step = component::User::GAME;
        user.index = 0;

        action.callback(this->getWorld().getUniverse());
    }
}
