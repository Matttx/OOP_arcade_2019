/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include "../../engine/component/ARender.hpp"
#include "../../engine/component/Animations.hpp"
#include "../../engine/component/Size.hpp"
#include "../../engine/component/Transform.hpp"
#include "../../engine/core/Core.hpp"
#include "component/Action.hpp"
#include "component/User.hpp"
#include "system/User.hpp"

emulator::Game::Game(engine::ecs::Universe& universe)
    : game::AGame("emulator", universe)
{
}

emulator::Game::~Game() = default;

void emulator::Game::init()
{
    auto& mainWorld = this->getUniverse().createWorld("emulator");

    this->initBackground(mainWorld);
    this->initTitle(mainWorld);
    this->initControls(mainWorld);
    this->initGraphicalMenu(mainWorld);
    this->initGameMenu(mainWorld);
    this->initSelector(mainWorld);

    mainWorld.addSystem<emulator::system::User>();
    mainWorld.addSystem<engine::system::AAnimations>();
    mainWorld.addSystem<engine::system::AAudio>();
    mainWorld.addSystem<engine::system::ARender>();

    this->getUniverse().setCurrentWorld("emulator");
}

void emulator::Game::destroy()
{
    this->getUniverse().deleteWorld("emulator");
}

void emulator::Game::initMusic(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> paths = {"./assets/emulator/music.txt",
        "./assets/emulator/music.wav", "./assets/emulator/music.debug"};

    auto& music = mainWorld.createEntity();

    music.addComponent<engine::component::AAudio>(paths);
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

void emulator::Game::initTitle(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> paths = {"./assets/emulator/arcade.txt",
        "./assets/emulator/arcade-animate.png",
        "./assets/emulator/arcade.debug"};
    std::map<std::string, engine::type::Animation> list;

    list["default"] = {0, 5, 100};

    auto& title = mainWorld.createEntity();

    title.addComponent<engine::component::Animations>(list);
    title.getComponent<engine::component::Animations>().currentAnimation =
        "default";
    title.getComponent<engine::component::Animations>().currentFrame = 0;
    title.addComponent<engine::component::ARender>(paths);
    title.addComponent<engine::component::Size>(586, 139);
    title.addComponent<engine::component::Transform>(
        engine::type::Vector2D {667, 50}, 10);
}

void emulator::Game::initControls(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> exitPaths = {"./assets/emulator/exit.txt",
        "./assets/emulator/exit.png", "./assets/emulator/exit.debug"};
    const std::vector<std::string> previousPaths = {
        "./assets/emulator/previous.txt", "./assets/emulator/previous.png",
        "./assets/emulator/previous.debug"};
    const std::vector<std::string> confirmPaths = {
        "./assets/emulator/confirm.txt", "./assets/emulator/confirm.png",
        "./assets/emulator/confirm.debug"};

    auto& exit = mainWorld.createEntity();

    exit.addComponent<engine::component::ARender>(exitPaths);
    exit.addComponent<engine::component::Size>(269, 98);
    exit.addComponent<engine::component::Transform>(
        engine::type::Vector2D {20, 20}, 10);

    auto& previous = mainWorld.createEntity();

    previous.addComponent<engine::component::ARender>(previousPaths);
    previous.addComponent<engine::component::Size>(401, 98);
    previous.addComponent<engine::component::Transform>(
        engine::type::Vector2D {20, 1080 - 98 - 20}, 10);

    auto& confirm = mainWorld.createEntity();

    confirm.addComponent<engine::component::ARender>(confirmPaths);
    confirm.addComponent<engine::component::Size>(392, 98);
    confirm.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1920 - 392 - 20, 1080 - 98 - 20}, 10);
}

void emulator::Game::initGraphicalMenu(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> framePaths = {
        "./assets/emulator/graphical.txt", "./assets/emulator/graphical.png",
        "./assets/emulator/graphical.debug"};
    const std::vector<std::string> buttonPaths = {
        "./assets/emulator/button.txt", "./assets/emulator/button.png",
        "./assets/emulator/button.debug"};
    const std::vector<std::string> fontPaths = {"./assets/emulator/font.txt",
        "./assets/emulator/font.ttf", "./assets/emulator/font.debug"};

    auto& frame = mainWorld.createEntity();

    frame.addComponent<engine::component::ARender>(framePaths);
    frame.addComponent<engine::component::Size>(818, 666);
    frame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {71, 240}, 10);

    auto graphicalNames = mainWorld.getUniverse().getCore().getGraphicals();
    int i = 0;

    for (const auto& graphicalName : graphicalNames) {
        auto& button = mainWorld.createEntity();
        auto& text = mainWorld.createEntity();

        button.addComponent<emulator::component::Action>(
            [graphicalName](engine::ecs::Universe& universe) {
                universe.getCore().setCurrentGraphical(graphicalName.first);
            });
        button.addComponent<engine::component::ARender>(buttonPaths);
        button.addComponent<engine::component::Size>(518, 136);
        button.addComponent<engine::component::Transform>(
            engine::type::Vector2D {71 + 150, 240 + 170 + 150 * i}, 20);
        mainWorld.addToGroup(button, "graphicals");

        int textWidth = 40 * graphicalName.second.size();
        int textHeight = 50;

        text.addComponent<engine::component::AText>(
            graphicalName.second, fontPaths);
        text.addComponent<engine::component::Size>(textWidth, textHeight);
        text.addComponent<engine::component::Transform>(
            engine::type::Vector2D {
                71 + 150 + ((518 - textWidth) / 2), 240 + 170 + 30 + 150 * i},
            30);

        i++;
    }
}

void emulator::Game::initGameMenu(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> framePaths = {"./assets/emulator/game.txt",
        "./assets/emulator/game.png", "./assets/emulator/game.debug"};
    const std::vector<std::string> buttonPaths = {
        "./assets/emulator/button.txt", "./assets/emulator/button.png",
        "./assets/emulator/button.debug"};
    const std::vector<std::string> fontPaths = {"./assets/emulator/font.txt",
        "./assets/emulator/font.ttf", "./assets/emulator/font.debug"};

    auto& frame = mainWorld.createEntity();

    frame.addComponent<engine::component::ARender>(framePaths);
    frame.addComponent<engine::component::Size>(818, 666);
    frame.addComponent<engine::component::Transform>(
        engine::type::Vector2D {1031, 240}, 10);

    auto gameNames = mainWorld.getUniverse().getCore().getGames();
    int i = 0;

    for (const auto& gameName : gameNames) {
        auto& button = mainWorld.createEntity();
        auto& text = mainWorld.createEntity();

        button.addComponent<emulator::component::Action>(
            [gameName](engine::ecs::Universe& universe) {
                universe.getCore().setCurrentGame(gameName.first);
            });
        button.addComponent<engine::component::ARender>(buttonPaths);
        button.addComponent<engine::component::Size>(518, 136);
        button.addComponent<engine::component::Transform>(
            engine::type::Vector2D {1031 + 150, 240 + 170 + 150 * i}, 20);
        mainWorld.addToGroup(button, "games");

        int textWidth = 40 * gameName.second.size();
        int textHeight = 50;

        text.addComponent<engine::component::AText>(gameName.second, fontPaths);
        text.addComponent<engine::component::Size>(textWidth, textHeight);
        text.addComponent<engine::component::Transform>(
            engine::type::Vector2D {
                1031 + 150 + ((518 - textWidth) / 2), 240 + 170 + 30 + 150 * i},
            30);

        i++;
    }
}

void emulator::Game::initSelector(engine::ecs::World& mainWorld)
{
    const std::vector<std::string> paths = {"./assets/emulator/selector.txt",
        "./assets/emulator/selector.png", "./assets/emulator/selector.debug"};

    auto& selector = mainWorld.createEntity();

    selector.addComponent<emulator::component::User>();
    selector.addComponent<engine::component::ARender>(paths);
    selector.addComponent<engine::component::Size>(687, 74);
    selector.addComponent<engine::component::Transform>(
        engine::type::Vector2D {0, 0}, 20);
}
