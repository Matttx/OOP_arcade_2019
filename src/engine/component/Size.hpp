/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_SIZE_HPP
#define OOP_ARCADE_2019_SIZE_HPP

namespace engine { namespace component {
class Size : public engine::ecs::AComponent {
public:
    Size(engine::ecs::Entity& entity, int width, int height);
    ~Size();
    int width;
    int height;
};
} }

#endif // OOP_ARCADE_2019_SIZE_HPP
