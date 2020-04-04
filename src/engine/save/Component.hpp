/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Component.hpp
*/

#ifndef OOP_ARCADE_2019_SAVE_COMPONENT_HPP
#define OOP_ARCADE_2019_SAVE_COMPONENT_HPP

#include <functional>
#include <tuple>

#include "../ecs/Entity.hpp"

namespace engine {

namespace save {

template<typename T, typename... TArgs>
class Component {
  public:
    explicit Component(ecs::Entity &entity, TArgs... args)
        : _entity(entity), _args(args...)
    {
    }

    ~Component() = default;

  public:
    void addToEntity()
    {
        std::apply(
            [this](auto... args) {
                this->_entity.template addComponent<T>(args...);
            },
            _args);
    }

    void removeFromEntity()
    {
        _entity.removeComponent<T>();
    }

  private:
    ecs::Entity &_entity;
    std::tuple<TArgs...> _args;
};

namespace component {

using AAudio = Component<engine::component::AAudio, std::vector<std::string>>;
using ARender = Component<engine::component::ARender, std::vector<std::string>>;

} // namespace component

template<>
void component::AAudio::addToEntity();

template<>
void component::ARender::addToEntity();

} // namespace save

} // namespace engine

#endif // OOP_ARCADE_2019_SAVE_COMPONENT_HPP
