/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.hpp
*/

#ifndef OOP_ARCADE_2019_GAME_HPP
#define OOP_ARCADE_2019_GAME_HPP

#include "../../../engine/component/Animations.hpp"
#include "../../../engine/component/Motion.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../../../engine/event/Collision.hpp"
#include "../../../graphical/IGraphical.hpp"
#include "../../AGame.hpp"

#define DEFAULT_POSITION (500)
#define DEFAULT_SIZE_BLOCK (40)
#define MAP_PATH ("./src/game/pacman/map/map.txt")

enum DIRECTION {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    COUNT
};

static const std::map<int, std::pair<int, int>> NEXT_DIRECTION {
    {LEFT, {- DEFAULT_SIZE_BLOCK / 4, 0}},
    {RIGHT, {DEFAULT_SIZE_BLOCK / 4, 0}},
    {TOP, {0, - DEFAULT_SIZE_BLOCK / 4}},
    {BOTTOM, {0, DEFAULT_SIZE_BLOCK / 4}}
};

// Initialisation of assets' paths
static const std::vector<std::string> BG_PATH = {"", "./assets/pacman/background.png", "./assets/pacman/background.png"};
static const std::vector<std::string> PACMAN_PATH = {"C", "./assets/pacman/pacman.png", "./assets/pacman/pacman.png"};
static const std::map<std::string, engine::type::Animation> PACMAN_ANIMATION =
    {
        {"living", engine::type::Animation(1, 1, 0)}
    };
static const std::vector<std::string> GHOST_PATH = {"n", "./assets/pacman/ghost.png", "./assets/pacman/ghost.png"};
static const std::map<std::string, engine::type::Animation> GHOST_ANIMATION =
    {
        {"living", engine::type::Animation(1, 1, 0)}
    };
static const std::vector<std::string> WALL_PATH = {"□", "./assets/pacman/wall.png", "./assets/pacman/wall.png"};
static const std::vector<std::string> PACGUMS_PATH = {".", "./assets/pacman/pacgums.png", "./assets/pacman/pacgums.png"};
static const std::vector<std::string> VOID_PATH = {" ", "./assets/pacman/void.png", "./assets/pacman/void.png"};
static const std::vector<std::string> SPECIALPACGUMS_PATH = {"o", "./assets/pacman/special_pacgums.png", "./assets/pacman/special_pacgums.png"};


// Class Game
namespace game {
class Game : public game::AGame {
  public:
    Game(engine::ecs::Universe& universe);
    ~Game() override = default;

  public:
    void init() override;
    void destroy() override;

  public:
    static std::vector<bool> isCollide(const engine::component::Motion& motion);
    void receiveCollision(engine::event::Collision& event);
    void initEntity(engine::ecs::World& world);

  public:
    int nbPacGums;
};
}

#endif // OOP_ARCADE_2019_GAME_HPP
