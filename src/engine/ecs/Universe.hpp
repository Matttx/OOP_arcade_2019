/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_UNIVERSE_HPP
#define OOP_ARCADE_2019_ECS_UNIVERSE_HPP

namespace engine {
namespace core {
class Core;
} // namespace core
} // namespace engine

#include <functional>
#include <map>

#include "../eventbus/EventBus.hpp"
#include "World.hpp"

namespace engine {

namespace ecs {

class Universe {
  public:
    explicit Universe(core::Core& core);
    ~Universe();

  public:
    core::Core& getCore() const;
    eventbus::EventBus& getEventBus() const;

  public:
    void init();
    void update();
    void render();

  public:
    World& createWorld(const std::string& name);
    bool hasWorld(const std::string& name) const;
    bool hasCurrentWorld() const;
    World& getWorld(const std::string& name) const;
    World& getCurrentWorld() const;
    void setCurrentWorld(const std::string& name);
    void deleteWorld(const std::string& name);

  private:
    core::Core &_core;
    eventbus::EventBus _eventBus;
    std::map<std::string, std::reference_wrapper<World>> _worlds;
    std::string _current;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_UNIVERSE_HPP
