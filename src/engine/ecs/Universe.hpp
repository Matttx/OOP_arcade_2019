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
/**
 * @class Universe
 *
 */
class Universe {
  public:
    /**
     * @brief Construct a new Universe object
     *
     * @param core
     */
    explicit Universe(core::Core& core);
    /**
     * @brief Destroy the Universe object
     *
     */
    ~Universe();

  public:
    /**
     * @brief Get the Core object
     *
     * @return core::Core& : return a reference to the Core object getted
     */
    core::Core& getCore() const;
    /**
     * @brief Get the Event Bus object
     *
     * @return eventbus::EventBus& : return a reference to an EventBus getted
     */
    eventbus::EventBus& getEventBus() const;

  public:
    /**
     * @brief init : init the universe
     *
     */
    void init();
    /**
     * @brief update : update the universe
     *
     */
    void update();
    /**
     * @brief render : render the universe
     *
     */
    void render();

  public:
    /**
     * @brief Create a World object
     *
     * @param name : the name of the world
     * @return World& : return a reference of the world created
     */
    World& createWorld(const std::string& name);
    /**
     * @brief hasWorld : check if the world exist with a name
     *
     * @param name : name of the world
     * @return true : the wordl exists
     * @return false : the world doesn't exist
     */
    bool hasWorld(const std::string& name) const;
    /**
     * @brief hasCurrentWorld : function that check if there is a current world
     *
     * @return true : there is a world
     * @return false : there is not a world
     */
    bool hasCurrentWorld() const;
    /**
     * @brief Get the World object
     *
     * @param name : the name of the world to get
     * @return World& : a reference to the world getted
     */
    World& getWorld(const std::string& name) const;
    /**
     * @brief Get the Current World object
     *
     * @return World& : return a reference to the current world
     */
    World& getCurrentWorld() const;
    /**
     * @brief Get the World Names object
     *
     * @return std::vector<std::string> : return a vector of string that represents the name of all the worlds
     */
    std::vector<std::string> getWorldNames() const;
    /**
     * @brief Set the Current World object
     *
     * @param name : the world to set current
     */
    void setCurrentWorld(const std::string& name);
    /**
     * @brief deleteWorld : delete a world
     *
     * @param name : the world to delete
     */
    void deleteWorld(const std::string& name);

  private:
    /**
     * @brief _core : a reference to the core
     *
     */
    core::Core& _core;
    /**
     * @brief _eventBus : contain an eventbus
     *
     */
    eventbus::EventBus _eventBus;
    /**
     * @brief _worlds : map of string that reprensent the name of the world and reference wrapper to the world
     *
     */
    std::map<std::string, std::reference_wrapper<World>> _worlds;
    /**
     * @brief _current : name of the current universe
     *
     */
    std::string _current;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_UNIVERSE_HPP
