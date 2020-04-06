/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Close.hpp
*/

/**
 * @brief Close event
 */

#ifndef OOP_ARCADE_2019_SRC_ENGINE_EVENT_CLOSE_HPP
#define OOP_ARCADE_2019_SRC_ENGINE_EVENT_CLOSE_HPP

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {
/**
 * @class Class of Close
 *
 */
class Close : public eventbus::AEvent {
  public:
    /**
     * @brief Constructor of Close
     *
     */
    Close();
    /**
     * @brief Destructor of Close
     *
     */
    ~Close() override;
};

} // namespace event

} // namespace engine

#endif // OOP_ARCADE_2019_SRC_ENGINE_EVENT_CLOSE_HPP
