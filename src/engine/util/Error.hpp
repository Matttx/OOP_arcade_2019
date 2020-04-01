/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error.hpp
*/

#ifndef OOP_ARCADE_2019_ERROR_HPP
#define OOP_ARCADE_2019_ERROR_HPP

#include <exception>
#include <string>

namespace engine {

namespace util {

class Error : public std::exception {
  public:
    Error(const std::string& subject, const std::string& message);
    ~Error() override;

  public:
    const char* what() const noexcept override;

  private:
    std::string _what;
};

} // namespace util

} // namespace engine

#endif // OOP_ARCADE_2019_ERROR_HPP
