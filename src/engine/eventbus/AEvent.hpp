/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AEvent.hpp
*/

/**
 * @brief Class for event implementation
 */

#ifndef OOP_ARCADE_2019_AEVENT_HPP
#define OOP_ARCADE_2019_AEVENT_HPP

namespace engine {

namespace eventbus {
/**
 * @class Class of AEvent
 *
 */
class AEvent {
  public:
    /**
     * @brief Constructor of AEvent
     *
     */
    AEvent();
    /**
     * @brief Destructor of AEvent
     *
     */
    virtual ~AEvent() = 0;
};

} // namespace eventbus

} // namespace engine

#endif // OOP_ARCADE_2019_AEVENT_HPP
