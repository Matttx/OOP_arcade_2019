/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IEvent.hpp
*/

#ifndef OOP_ARCADE_2019_EVENTBUS_IEVENT_HPP
#define OOP_ARCADE_2019_EVENTBUS_IEVENT_HPP

namespace engine {

namespace eventbus {
/**
 * @class IEvent
 * 
 */
class IEvent {
  public:
    /**
     * @brief Destroy the IEvent object
     * 
     */
    virtual ~IEvent() = 0;
};

} // namespace eventbus

} // namespace engine

#endif // OOP_ARCADE_2019_EVENTBUS_IEVENT_HPP
