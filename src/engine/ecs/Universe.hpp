/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_UNIVERSE_HPP
#define OOP_ARCADE_2019_ECS_UNIVERSE_HPP

namespace engine {
namespace ecs {
class World;
} // namespace ecs
} // namespace engine

#include <functional>
#include <map>

#include "World.hpp"

namespace engine {

namespace ecs {

class Universe {
  public:
    Universe();
    ~Universe();

  public:
    void init();
    void update();
    void render();

  public:
    World& createWorld(const std::string& name);
    bool hasWorld(const std::string& name) const;
    World& getWorld(const std::string& name) const;
    World& getCurrentWorld() const;
    void setCurrentWorld(const std::string& name);
    void deleteWorld(const std::string& name);

  private:
    std::map<std::string, std::reference_wrapper<World>> _worlds;
    std::string _current;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_UNIVERSE_HPP
