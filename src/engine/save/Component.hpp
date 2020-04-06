/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Component.hpp
*/

/**
 * @brief Component parameters saver
 */

#ifndef OOP_ARCADE_2019_SAVE_COMPONENT_HPP
#define OOP_ARCADE_2019_SAVE_COMPONENT_HPP

#include <functional>
#include <tuple>

#include "../component/Animations.hpp"
#include "../ecs/Entity.hpp"

namespace engine {

namespace save {

/**
 * @brief Class of Component
 *
 * @tparam T Type of component
 * @tparam TArgs Type of component parameters
 */
template<typename T, typename... TArgs>
class Component {
  public:
    /**
     * @brief Constructor of Component
     *
     * @param entity Entity that the component belongs to
     * @param args Component parameters
     */
    explicit Component(ecs::Entity &entity, TArgs... args) : _entity(entity), _args(args...)
    {
    }

    /**
     * @brief Destructor of Component
     */
    ~Component() = default;

  public:
    /**
     * @brief Add the component to the entity
     */
    void addToEntity()
    {
        std::apply(
            [this](auto... args) {
                this->_entity.template addComponent<T>(args...);
            },
            _args);
    }

    /**
     * @brief Remove the component from the entity
     */
    void removeFromEntity()
    {
        _entity.removeComponent<T>();
    }

  private:
    /**
     * @brief Reference of the entity
     */
    ecs::Entity &_entity;
    /**
     * @brief Component parameters
     */
    std::tuple<TArgs...> _args;
};

namespace component {

/**
 * @brief AAudio component saver signature
 */
using AAudio = Component<engine::component::AAudio, std::vector<std::string>>;
/**
 * @brief ARender component saver signature
 */
using ARender = Component<engine::component::ARender, std::vector<std::string>>;
/**
 * @brief AText component saver signature
 */
using AText = Component<engine::component::AText, std::string, std::vector<std::string>>;

} // namespace component

template<>
void component::AAudio::addToEntity();

template<>
void component::ARender::addToEntity();

template<>
void engine::save::component::AText::addToEntity();

} // namespace save

} // namespace engine

#endif // OOP_ARCADE_2019_SAVE_COMPONENT_HPP
