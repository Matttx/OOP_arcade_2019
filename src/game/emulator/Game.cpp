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
    const std::vector<std::string> gameFramePaths = {
        "./assets/emulator/game_frame.txt", "./assets/emulator/game_frame.png",
        "./assets/emulator/game_frame.debug"};
    const std::vector<std::string> graphicalFramePaths = {
        "./assets/emulator/graphical_frame.txt",
        "./assets/emulator/graphical_frame.png",
        "./assets/emulator/graphical_frame.debug"};

    background.addComponent<engine::component::ARender>(backgroundPaths);
    background.addComponent<engine::component::Transform>(
        engine::type::Vector2D {0, 0}, 0);
    background.addComponent<engine::component::Size>(1920, 1080);
    gameFrame.addComponent<engine::component::ARender>(gameFramePaths);
    gameFrame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {50, 50}, 10);
    gameFrame.addComponent<engine::component::Size>(800, 500);
    graphicalFrame.addComponent<engine::component::ARender>(
        graphicalFramePaths);
    graphicalFrame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1920 - 800 - 50, 50}, 10);
    graphicalFrame.addComponent<engine::component::Size>(800, 500);
}

void game::emulator::Game::destroy()
{
}
