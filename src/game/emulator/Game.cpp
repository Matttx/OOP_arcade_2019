/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include "../../engine/component/ARender.hpp"
#include "../../engine/component/Size.hpp"
#include "../../engine/component/Transform.hpp"

emulator::Game::Game(engine::ecs::Universe& universe)
    : game::AGame("emulator", universe)
{
}

emulator::Game::~Game() = default;

void emulator::Game::init()
{
    auto& mainWorld = this->getUniverse().createWorld("main");

    this->initBackground(mainWorld);
    this->initGraphicalMenu(mainWorld);
    this->initGameMenu(mainWorld);
}

void emulator::Game::destroy()
{
}

void emulator::Game::initBackground(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> paths = {"./assets/emulator/background.txt",
        "./assets/emulator/background.png",
        "./assets/emulator/background.debug"};

    auto& background = mainWorld.createEntity();

    background.addComponent<engine::component::ARender>(paths);
    background.addComponent<engine::component::Size>(1920, 1080);
    background.addComponent<engine::component::Transform>(
        engine::type::Vector2D {0, 0}, 0);
}

void emulator::Game::initGraphicalMenu(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> framePaths = {"./assets/emulator/frame.txt",
        "./assets/emulator/frame.png", "./assets/emulator/frame.debug"};
    const std::vector<std::string> buttonPaths = {
        "./assets/emulator/button.txt", "./assets/emulator/button.png",
        "./assets/emulator/button.debug"};

    auto& frame = mainWorld.createEntity();

    frame.addComponent<engine::component::ARender>(framePaths);
    frame.addComponent<engine::component::Size>(800, 800);
    frame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {80, 140}, 10);
}

void emulator::Game::initGameMenu(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> framePaths = {"./assets/emulator/frame.txt",
        "./assets/emulator/frame.png", "./assets/emulator/frame.debug"};
    const std::vector<std::string> buttonPaths = {
        "./assets/emulator/button.txt", "./assets/emulator/button.png",
        "./assets/emulator/button.debug"};

    auto& frame = mainWorld.createEntity();

    frame.addComponent<engine::component::ARender>(framePaths);
    frame.addComponent<engine::component::Size>(800, 800);
    frame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {80, 140}, 10);
}
