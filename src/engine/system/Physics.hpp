/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
#define OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Physics that inherits from ASystem
 * 
 */
class Physics : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new Physics object
     * 
     * @param world 
     */
    explicit Physics(ecs::World& world);
    /**
     * @brief Destroy the Physics object
     * 
     */
    ~Physics() override;

  public:
    /**
     * @brief init : init the Physics system
     * 
     */
    void init() override;
    /**
     * @brief update : update the Physics system
     * 
     */
    void update() override;
    /**
     * @brief render : render the Physics system
     * 
     */
    void render() override;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
