/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include <fstream>

#include "../../../engine/component/AAI.hpp"
#include "../../../engine/component/AUser.hpp"
#include "../../../engine/component/Animations.hpp"
#include "../../../engine/component/Hitbox.hpp"
#include "../../../engine/component/Motion.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/Transform.hpp"
#include "component/AI.hpp"
#include "component/User.hpp"

game::Game::Game(engine::ecs::Universe& universe): AGame("PACMAN", universe)
{
}

void game::Game::init()
{
    auto& world = getUniverse().getCurrentWorld();
    initBackGround(world);
    initEntity(world);
}

static void initEntity(engine::ecs::World& world)
{
    std::ifstream file;
    std::string string;
    file.open(MAP_PATH);
    if (!file.is_open())
        throw std::exception();
    for (int y = 0; getline(file, string); y++) {
        for (int x = 0; x < string.size(); x++) {
            switch (string[x]) {
                case '1':
                    initWall(world, x, y);
                    break;
                case '2':
                    initPacGums(world, x, y);
                    break;
                case '3':
                    initPacman(world, x, y);
                    break;
                case '4':
                    initGhost(world, x, y);
                    break;
                case '5':
                    initSpecialPacGums(world, x, y);
                    break;
                default:
                    initVoid(world, x, y);
                    break;
            }
        }
    }
}

static void initBackGround(engine::ecs::World& world)
{
    auto& bg = world.createEntity();
    bg.addComponent<engine::component::ARender>(BG_PATH);
    bg.addComponent<engine::component::Transform>(engine::type::Vector2D(0, 0), 0);
}

static void initPacman(engine::ecs::World& world, int x, int y)
{
    auto& pacman = world.createEntity();
    pacman.addComponent<pacman::component::User>();
    pacman.addComponent<engine::component::ARender>(PACMAN_PATH);
    pacman.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION, y * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION), 2);
    pacman.addComponent<engine::component::Animations>(PACMAN_ANIMATION);
    pacman.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 0), engine::type::Vector2D(0, 0));
    pacman.addComponent<engine::component::Hitbox>(40, 40);
    pacman.addComponent<engine::component::Size>(40, 40);
}

static void initWall(engine::ecs::World& world, int x, int y)
{
    auto& wall = world.createEntity();
    wall.addComponent<engine::component::ARender>(WALL_PATH);
    wall.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION, y * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION), 2);
    wall.addComponent<engine::component::Hitbox>(40, 40);
    wall.addComponent<engine::component::Size>(40, 40);
    world.addToGroup(wall, "wall");
}

static void initPacGums(engine::ecs::World& world, int x, int y)
{
    auto& pacGums = world.createEntity();
    pacGums.addComponent<engine::component::ARender>(PACGUMS_PATH);
    pacGums.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + 20 - 4 + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK + 20 - 4 + DEFAULT_POSITION), 1);
    pacGums.addComponent<engine::component::Hitbox>(8, 8);
    pacGums.addComponent<engine::component::Size>(8, 8);
    world.addToGroup(pacGums, "pacGums");
}

static void initGhost(engine::ecs::World& world, int x, int y)
{
    auto& ghost = world.createEntity();
    ghost.addComponent<pacman::component::AI>();
    ghost.addComponent<engine::component::ARender>(GHOST_PATH);
    ghost.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION), 2);
    ghost.addComponent<engine::component::Animations>(GHOST_ANIMATION);
    ghost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 0), engine::type::Vector2D(1, 1));
    ghost.addComponent<engine::component::Hitbox>(40, 40);
    ghost.addComponent<engine::component::Size>(40, 40);
    world.addToGroup(ghost, "ghost");
}

static void initVoid(engine::ecs::World& world, int x, int y)
{
    auto& empty = world.createEntity();
    empty.addComponent<engine::component::ARender>(VOID_PATH);
    empty.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION), 0);
    empty.addComponent<engine::component::Hitbox>(40, 40);
    empty.addComponent<engine::component::Size>(40,  40);
}

static void initSpecialPacGums(engine::ecs::World& world, int x, int y)
{
    auto& specialPacGums = world.createEntity();
    specialPacGums.addComponent<engine::component::ARender>(SPECIALPACGUMS_PATH);
    specialPacGums.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + 20 - 8 + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK + 20 - 8 + DEFAULT_POSITION), 1);
    specialPacGums.addComponent<engine::component::Hitbox>(16, 16);
    specialPacGums.addComponent<engine::component::Size>(16, 16);
    world.addToGroup(specialPacGums, "specialPacGums");
}