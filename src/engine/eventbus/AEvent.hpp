/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AEvent.hpp
*/

#ifndef OOP_ARCADE_2019_AEVENT_HPP
#define OOP_ARCADE_2019_AEVENT_HPP

namespace engine {

namespace eventbus {
/**
 * @class AEvent
 *
 */
class AEvent {
  public:
    /**
     * @brief Construct a new AEvent object
     *
     */
    AEvent();
    /**
     * @brief Destroy the AEvent object
     *
     */
    virtual ~AEvent() = 0;
};

} // namespace eventbus

} // namespace engine

#endif // OOP_ARCADE_2019_AEVENT_HPP
