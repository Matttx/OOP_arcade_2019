/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

#ifndef OOP_ARCADE_2019_ARENDER_HPP
#define OOP_ARCADE_2019_ARENDER_HPP

#include <vector>
#include <string>

namespace engine { namespace component {
class ARender : public engine::ecs::AComponent {
public:
    ARender(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
    virtual ~ARender() = 0;
private:
    std::vector<std::string> _paths;
};
} }

#endif // OOP_ARCADE_2019_ARENDER_HPP
