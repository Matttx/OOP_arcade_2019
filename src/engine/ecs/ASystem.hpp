/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ASYSTEM_HPP
#define OOP_ARCADE_2019_ECS_ASYSTEM_HPP

namespace engine {
namespace ecs {
/**
 * @class World
 *
 */
class World;
} // namespace ecs
} // namespace engine

namespace engine {

namespace ecs {
/**
 * @brief ASystem
 *
 */
class ASystem {
  public:
    /**
     * @brief Construct a new ASystem object
     *
     * @param world : the world object to set in the constructor
     */
    explicit ASystem(World& world);
    /**
     * @brief Destroy the ASystem object
     *
     */
    virtual ~ASystem() = 0;

  public:
    /**
     * @brief Get the World object
     *
     * @return World& : return a reference to a world get
     */
    World& getWorld() const;

  public:
    /**
     * @brief init : pure virtual function for child class in order to init the system
     *
     */
    virtual void init() = 0;
    /**
     * @brief update : pure virtual function for child class in order to update the system
     *
     */
    virtual void update() = 0;
    /**
     * @brief render : pure virtual function for child class in order to render the system
     *
     */
    virtual void render() = 0;

  private:
    /**
     * @brief _world : reference to a World
     *
     */
    World& _world;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ASYSTEM_HPP
