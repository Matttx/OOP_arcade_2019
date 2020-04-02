/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include "../../engine/component/Size.hpp"
#include "../../engine/component/Transform.hpp"

game::emulator::Game::Game(engine::ecs::Universe& universe)
    : AGame("emulator", universe)
{
}

game::emulator::Game::~Game() = default;

void game::emulator::Game::init()
{
    auto& universe = this->getUniverse();

    auto& world = universe.createWorld("main");

    auto& background = world.createEntity();
    auto& gameFrame = world.createEntity();
    auto& graphicalFrame = world.createEntity();

    const std::vector<std::string> backgroundPaths = {
        "./assets/emulator/background.txt", "./assets/emulator/background.png",
        "./assets/emulator/background.debug"};
    const std::vector<std::string> framePaths = {"./assets/emulator/frame.txt",
        "./assets/emulator/frame.png", "./assets/emulator/frame.debug"};
    const std::vector<std::string> buttonPaths = {
        "./assets/emulator/button.txt", "./assets/emulator/button.png",
        "./assets/emulator/button.debug"};
    const std::vector<std::string> selectorPaths = {
        "./assets/emulator/selector.txt", "./assets/emulator/selector.png",
        "./assets/emulator/selector.debug"};

    background.addComponent<engine::component::ARender>(backgroundPaths);
    background.addComponent<engine::component::Transform>(
        engine::type::Vector2D {0, 0}, 0);
    background.addComponent<engine::component::Size>(1920, 1080);
    gameFrame.addComponent<engine::component::ARender>(framePaths);
    gameFrame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {100, (1080 - 800) / 2}, 10);
    gameFrame.addComponent<engine::component::Size>(800, 800);
    graphicalFrame.addComponent<engine::component::ARender>(framePaths);
    graphicalFrame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1920 - 800 - 50, (1080 - 800) / 2}, 10);
    graphicalFrame.addComponent<engine::component::Size>(800, 800);

    universe.setCurrentWorld("main");
}

void game::emulator::Game::destroy()
{
}
