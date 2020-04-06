/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ASYSTEM_HPP
#define OOP_ARCADE_2019_ECS_ASYSTEM_HPP

/**
 * @file ASystem.hpp
 * @brief Class for system implementation
 */

namespace engine {
namespace ecs {
class World;
} // namespace ecs
} // namespace engine

namespace engine {

namespace ecs {
/**
 * @brief Abstract class of system
 *
 */
class ASystem {
  public:
    /**
     * @brief Constructor of ASystem
     *
     * @param world : World that the system belongs to
     */
    explicit ASystem(World& world);
    /**
     * @brief Destructor of ASystem
     *
     */
    virtual ~ASystem() = 0;

  public:
    /**
     * @brief Get the world
     *
     * @return World& : Reference of the world
     */
    World& getWorld() const;

  public:
    /**
     * @brief init : Initialize the system
     *
     */
    virtual void init() = 0;
    /**
     * @brief update : Update the system
     *
     */
    virtual void update() = 0;
    /**
     * @brief render : Render the system
     *
     */
    virtual void render() = 0;

  private:
    /**
     * @brief _world : Reference of the world
     *
     */
    World& _world;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ASYSTEM_HPP
