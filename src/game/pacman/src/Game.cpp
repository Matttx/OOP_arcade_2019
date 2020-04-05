/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include <fstream>
#include <iostream>

#include "../../../engine/component/AAI.hpp"
#include "../../../engine/component/AUser.hpp"
#include "../../../engine/component/Animations.hpp"
#include "../../../engine/component/Hitbox.hpp"
#include "../../../engine/component/Motion.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/Transform.hpp"
#include "../../../engine/system/Movement.hpp"
#include "../../../engine/system/Physics.hpp"
#include "component/AI.hpp"
#include "component/User.hpp"
#include "system/AI.hpp"
#include "system/User.hpp"

static void initSpecialPacGums(engine::ecs::World& world, int x, int y);
static void initVoid(engine::ecs::World& world, int x, int y);
static void initGhost(engine::ecs::World& world, int x, int y);
static void initPacGums(engine::ecs::World& world, int x, int y);
static void initWall(engine::ecs::World& world, int x, int y);
static void initPacman(engine::ecs::World& world, int x, int y);
static void initBackGround(engine::ecs::World& world);
//static void errorMapHandler();

game::Game::Game(engine::ecs::Universe& universe): AGame("PACMAN", universe)
{
}

extern "C"  game::IGame* create(engine::ecs::Universe* universe) {
    return new game::Game(*universe);
}

void game::Game::init()
{
    auto& world = getUniverse().createWorld("main");
    initBackGround(world);
    initEntity(world);
    world.addSystem<pacman::system::AI>();
    world.addSystem<pacman::system::User>();
    world.addSystem<engine::system::Physics>();
    world.addSystem<engine::system::AAnimations>();
    world.addSystem<engine::system::Movement>();
    world.addSystem<engine::system::AAudio>();
    world.addSystem<engine::system::ARender>();
    auto& eventBus = world.getUniverse().getEventBus();
    eventBus.subscribe(*this, &Game::receiveCollision);
    getUniverse().setCurrentWorld("main");

}
void game::Game::destroy()
{
    getUniverse().deleteWorld("main");
}

std::vector<bool> game::Game::isCollide(
    const engine::component::Motion& motion)
{
    std::vector<bool> vec = {false, false, false, false};
    if (motion.velocity.x > 0) {
        vec[DIRECTION::RIGHT] = true;
    }
    if (motion.velocity.x < 0) {
        vec[DIRECTION::LEFT] = true;
    }
    if (motion.velocity.y > 0) {
        vec[DIRECTION::BOTTOM] = true;
    }
    if (motion.velocity.y < 0) {
        vec[DIRECTION::TOP] = true;
    }
    return vec;
}

void game::Game::receiveCollision(engine::event::Collision& collision)
{
    if (!collision.entity1.getWorld().hasGroup(collision.entity1, "wall") &&
        !collision.entity1.getWorld().hasGroup(collision.entity2, "wall"))
        return;
    if (collision.entity1.hasComponents<engine::component::Motion, pacman::component::User>()) {
        auto& motion = collision.entity1.getComponent<engine::component::Motion>();
        auto& transform = collision.entity1.getComponent<engine::component::Transform>();

        motion.velocity.x -= motion.acceleration.x;
        motion.velocity.y -= motion.acceleration.y;

        transform.position.x -= motion.velocity.x;
        transform.position.y -= motion.velocity.y;

        motion.velocity.x = 0;
        motion.acceleration.x = 0;
        motion.velocity.y = 0;
        motion.acceleration.y = 0;
    }
    if (collision.entity2.hasComponents<engine::component::Motion, pacman::component::User>()) {
        auto& motion2 = collision.entity2.getComponent<engine::component::Motion>();
        auto& transform2 = collision.entity2.getComponent<engine::component::Transform>();

        motion2.velocity.x -= motion2.acceleration.x;
        motion2.velocity.y -= motion2.acceleration.y;

        transform2.position.x -= motion2.velocity.x;
        transform2.position.y -= motion2.velocity.y;

        motion2.velocity.x = 0;
        motion2.acceleration.x = 0;
        motion2.velocity.y = 0;
        motion2.acceleration.y = 0;
    }
    if (collision.entity2.hasComponents<engine::component::Motion, pacman::component::AI>()) {
        std::srand(time(nullptr));
        int rand = 0;
        auto& motion = collision.entity2.getComponent<engine::component::Motion>();
        auto& transform = collision.entity2.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        motion.velocity.x -= motion.acceleration.x;
        motion.velocity.y -= motion.acceleration.y;
        transform.position.x -= motion.velocity.x;
        transform.position.y -= motion.velocity.y;
        motion.velocity.x = NEXT_DIRECTION.at(rand).first;
        motion.velocity.y = NEXT_DIRECTION.at(rand).second;
    }
    if (collision.entity1.hasComponents<engine::component::Motion, pacman::component::AI>()) {
        std::srand(time(nullptr));
        int rand = 0;
        auto& motion = collision.entity1.getComponent<engine::component::Motion>();
        auto& transform = collision.entity1.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        motion.velocity.x -= motion.acceleration.x;
        motion.velocity.y -= motion.acceleration.y;
        transform.position.x -= motion.velocity.x;
        transform.position.y -= motion.velocity.y;
        motion.velocity.x = NEXT_DIRECTION.at(rand).first;
        motion.velocity.y = NEXT_DIRECTION.at(rand).second;
    }
}

/*void errorMapHandler()
{
    std::ifstream file;
    file.open(MAP_PATH);
    if (!file.is_open())
        throw std::exception();
    std::string string;
    int y = 0;
    for (; getline(file, string); y++) {
        if (y == 0) {
            for (const auto& i : string) {
                if (i != '1') {
                    file.close();
                    throw std::exception();
                }
            }
        }
        for (const auto& i : string) {
            if (i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5') {
                file.close();
                throw std::exception();
            }
        }
        if (string[0] != '1') {
            int i = 0;
            for (; string[i] == '0'; i++);
            if (string[i] != '1') {
                file.close();
                throw std::exception();
            }
        }
        if (string[string.size()] != '1') {
            int i = 0;
            for (i = string.size() - 1; string[i] == '0'; i--);
            if (string[i] != '1') {
                file.close();
                throw std::exception();
            }
        }
        if (y == 20) {
            for (const auto& i : string) {
                if (string[i] != '1') {
                    file.close();
                    throw std::exception();
                }
            }
        }
    }
    if (y != 20) {
        file.close();
        throw std::exception();
    }
}*/

void game::Game::initEntity(engine::ecs::World& world)
{
    std::ifstream file;
    std::string string;
    //errorMapHandler();
    file.open(MAP_PATH);
    for (int y = 0; getline(file, string); y++) {
        for (size_t x = 0; x < string.size(); x++) {
            switch (string[x]) {
                case '1':
                    initWall(world, x, y);
                    break;
                case '2':
                    initPacGums(world, x, y);
                    nbPacGums ++;
                    break;
                case '3':
                    initPacman(world, x, y);
                    break;
                case '4':
                    initGhost(world, x, y);
                    break;
                case '5':
                    initSpecialPacGums(world, x, y);
                    nbPacGums++;
                    break;
                default:
                    initVoid(world, x, y);
                    break;
            }
        }
    }
    file.close();
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
    pacman.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION, y * DEFAULT_SIZE_BLOCK + 1), 2);
    pacman.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 0), engine::type::Vector2D(0, 0));
    pacman.addComponent<engine::component::Hitbox>(38, 38);
    pacman.addComponent<engine::component::Size>(40, 40);
}

static void initWall(engine::ecs::World& world, int x, int y)
{
    auto& wall = world.createEntity();
    wall.addComponent<engine::component::ARender>(WALL_PATH);
    wall.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION, y * DEFAULT_SIZE_BLOCK), 5);
    wall.addComponent<engine::component::Hitbox>(38, 38);
    wall.addComponent<engine::component::Size>(40, 40);
    world.addToGroup(wall, "wall");
}

static void initPacGums(engine::ecs::World& world, int x, int y)
{
    auto& pacGums = world.createEntity();
    pacGums.addComponent<engine::component::ARender>(PACGUMS_PATH);
    pacGums.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + 16 + DEFAULT_POSITION ,y * DEFAULT_SIZE_BLOCK + 16), 1);
    pacGums.addComponent<engine::component::Hitbox>(8, 8);
    pacGums.addComponent<engine::component::Size>(8, 8);
    world.addToGroup(pacGums, "pacGums");
}

static void initGhost(engine::ecs::World& world, int x, int y)
{
    auto& ghost = world.createEntity();
    ghost.addComponent<pacman::component::AI>();
    ghost.addComponent<engine::component::ARender>(GHOST_PATH);
    ghost.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK), 2);
    ghost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 0), engine::type::Vector2D(0, 0));
    ghost.addComponent<engine::component::Hitbox>(38, 38);
    ghost.addComponent<engine::component::Size>(40, 40);
    ghost.getComponent<pacman::component::AI>().startPosX = x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION;
    ghost.getComponent<pacman::component::AI>().startPosY = y * DEFAULT_SIZE_BLOCK;
    world.addToGroup(ghost, "ghost");
}

static void initVoid(engine::ecs::World& world, int x, int y)
{
    auto& empty = world.createEntity();
    empty.addComponent<engine::component::ARender>(VOID_PATH);
    empty.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK), 0);
    empty.addComponent<engine::component::Hitbox>(40, 40);
    empty.addComponent<engine::component::Size>(40,  40);
}

static void initSpecialPacGums(engine::ecs::World& world, int x, int y)
{
    auto& specialPacGums = world.createEntity();
    specialPacGums.addComponent<engine::component::ARender>(SPECIALPACGUMS_PATH);
    specialPacGums.addComponent<engine::component::Transform>(engine::type::Vector2D(x * DEFAULT_SIZE_BLOCK + 20 - 8 + DEFAULT_POSITION,y * DEFAULT_SIZE_BLOCK + 20 - 8), 1);
    specialPacGums.addComponent<engine::component::Hitbox>(16, 16);
    specialPacGums.addComponent<engine::component::Size>(16, 16);
    world.addToGroup(specialPacGums, "specialPacGums");
}