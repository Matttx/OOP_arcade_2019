/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include "../../engine/component/Size.hpp"
#include "../../engine/component/Transform.hpp"
#include "component/Action.hpp"
#include "component/User.hpp"
#include "system/User.hpp"

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
    auto& gameBtn1 = world.createEntity();
    auto& gameBtn2 = world.createEntity();
    auto& graphicalBtn1 = world.createEntity();
    auto& graphicalBtn2 = world.createEntity();
    auto& graphicalBtn3 = world.createEntity();
    auto& selector = world.createEntity();

    world.addToGroup(gameBtn1, "games");
    world.addToGroup(gameBtn2, "games");
    world.addToGroup(graphicalBtn1, "graphicals");
    world.addToGroup(graphicalBtn2, "graphicals");
    world.addToGroup(graphicalBtn3, "graphicals");

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

    gameBtn1.addComponent<game::emulator::component::Action>([](engine::ecs::Universe& universe) {
      (void) universe;
      std::cout << "gameBtn1 callback!" << std::endl;
    });
    gameBtn1.addComponent<engine::component::ARender>(buttonPaths);
    gameBtn1.addComponent<engine::component::Transform>(
        engine::type::Vector2D {200, 200}, 20);
    gameBtn1.addComponent<engine::component::Size>(600, 150);

    gameBtn2.addComponent<game::emulator::component::Action>([](engine::ecs::Universe& universe) {
      (void) universe;
      std::cout << "gameBtn2 callback!" << std::endl;
    });
    gameBtn2.addComponent<engine::component::ARender>(buttonPaths);
    gameBtn2.addComponent<engine::component::Transform>(
        engine::type::Vector2D {200, 400}, 20);
    gameBtn2.addComponent<engine::component::Size>(600, 150);

    graphicalBtn1.addComponent<game::emulator::component::Action>([](engine::ecs::Universe& universe) {
      (void) universe;
      std::cout << "graphicalBtn1 callback!" << std::endl;
    });
    graphicalBtn1.addComponent<engine::component::ARender>(buttonPaths);
    graphicalBtn1.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1170, 200}, 20);
    graphicalBtn1.addComponent<engine::component::Size>(600, 150);

    graphicalBtn2.addComponent<game::emulator::component::Action>([](engine::ecs::Universe& universe) {
      (void) universe;
      std::cout << "graphicalBtn2 callback!" << std::endl;
    });
    graphicalBtn2.addComponent<engine::component::ARender>(buttonPaths);
    graphicalBtn2.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1170, 400}, 20);
    graphicalBtn2.addComponent<engine::component::Size>(600, 150);

    graphicalBtn3.addComponent<game::emulator::component::Action>([](engine::ecs::Universe& universe) {
      (void) universe;
      std::cout << "graphicalBtn3 callback!" << std::endl;
    });
    graphicalBtn3.addComponent<engine::component::ARender>(buttonPaths);
    graphicalBtn3.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1170, 600}, 20);
    graphicalBtn3.addComponent<engine::component::Size>(600, 150);

    selector.addComponent<game::emulator::component::User>();
    selector.addComponent<engine::component::ARender>(selectorPaths);
    selector.addComponent<engine::component::Transform>(
        engine::type::Vector2D {0, 0}, 30);
    selector.addComponent<engine::component::Size>(690, 240);

    world.addSystem<game::emulator::system::User>();
    world.addSystem<engine::system::ARender>();

    universe.setCurrentWorld("main");
}

void game::emulator::Game::destroy()
{
}
