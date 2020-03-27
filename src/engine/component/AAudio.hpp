/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_AAUDIO_HPP
#define OOP_ARCADE_2019_AAUDIO_HPP

#include <vector>
#include <string>

namespace engine { namespace component {
class AAudio : public engine::ecs::AComponent {
public:
    AAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
    virtual ~AAudio() = 0;
private:
    std::vector<std::string> _paths;
};
} }

#endif // OOP_ARCADE_2019_AAUDIO_HPP
