/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Movement.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP
#define OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Movement that inherits from ASystem
 * 
 */
class Movement : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new Movement object
     * 
     * @param world 
     */
    explicit Movement(ecs::World& world);
    /**
     * @brief Destroy the Movement object
     * 
     */
    ~Movement() override;

  public:
    /**
     * @brief init : init the system movement 
     * 
     */
    void init() override;
    /**
     * @brief update : update the system movement
     * 
     */
    void update() override;
    /**
     * @brief render : render the system movement
     * 
     */
    void render() override;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP
