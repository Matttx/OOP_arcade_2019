/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_UNIVERSE_HPP
#define OOP_ARCADE_2019_ECS_UNIVERSE_HPP

/**
 * @brief Universe class, container of worlds
 */

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
/**
 * @class Class of Universe
 *
 */
class Universe {
  public:
    /**
     * @brief Constructor of Universe
     *
     * @param core Core that the universe belongs to
     */
    explicit Universe(core::Core& core);
    /**
     * @brief Destructor of Universe
     *
     */
    ~Universe();

  public:
    /**
     * @brief Get the Core object
     *
     * @return core::Core& : Reference of the core
     */
    core::Core& getCore() const;
    /**
     * @brief Get the Event Bus object
     *
     * @return eventbus::EventBus& : Reference of the event bus
     */
    eventbus::EventBus& getEventBus() const;

  public:
    /**
     * @brief init : Initialize the universe
     *
     */
    void init();
    /**
     * @brief update : Update the universe
     *
     */
    void update();
    /**
     * @brief render : Render the universe
     *
     */
    void render();

  public:
    /**
     * @brief Create a world
     *
     * @param name : Name of the world
     * @return World& : Reference of the created world
     */
    World& createWorld(const std::string& name);
    /**
     * @brief hasWorld : Check if the universe has the specified world
     *
     * @param name : Name of the world
     *
     * @return true : Universe has the world
     * @return false : Universe doesn't have the world
     */
    bool hasWorld(const std::string& name) const;
    /**
     * @brief hasCurrentWorld : Check if there is a current world
     *
     * @return true : There is a current world
     * @return false : There is not a current world
     */
    bool hasCurrentWorld() const;
    /**
     * @brief Get the specified world
     *
     * @param name : Name of the world
     *
     * @return World& : Reference to the world
     */
    World& getWorld(const std::string& name) const;
    /**
     * @brief Get the current world
     *
     * @return World& : Reference to the current world
     */
    World& getCurrentWorld() const;
    /**
     * @brief Get world names
     *
     * @return std::vector<std::string> : Vector of world names
     */
    std::vector<std::string> getWorldNames() const;
    /**
     * @brief Set the current world
     *
     * @param name : Name of the world
     */
    void setCurrentWorld(const std::string& name);
    /**
     * @brief deleteWorld : Delete the specified world
     *
     * @param name : Name of the world
     */
    void deleteWorld(const std::string& name);

  private:
    /**
     * @brief _core : Reference of the core
     *
     */
    core::Core& _core;
    /**
     * @brief _eventBus : Event bus instance
     *
     */
    eventbus::EventBus _eventBus;
    /**
     * @brief _worlds : Map of worlds
     * Key: World name
     * Value: World
     *
     */
    std::map<std::string, std::reference_wrapper<World>> _worlds;
    /**
     * @brief _current : Name of the current world
     *
     */
    std::string _current;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_UNIVERSE_HPP
