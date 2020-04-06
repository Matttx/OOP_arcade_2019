/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error.hpp
*/

#ifndef OOP_ARCADE_2019_ERROR_HPP
#define OOP_ARCADE_2019_ERROR_HPP

/**
 * @brief Error
 */

#include <exception>
#include <string>

namespace engine {

namespace util {
/**
 * @class Class of Error
 *
 */
class Error : public std::exception {
  public:
    /**
     * @brief Constructor of Error
     *
     * @param subject : Subject
     * @param message : Error message
     */
    Error(const std::string& subject, const std::string& message);
    /**
     * @brief Destructor of Error
     *
     */
    ~Error() override;

  public:
    /**
     * @brief what : Return the full error message
     *
     * @return const char* : Full error message
     */
    const char* what() const noexcept override;

  private:
    /**
     * @brief _what : Full error message
     *
     */
    std::string _what;
};

} // namespace util

} // namespace engine

#endif // OOP_ARCADE_2019_ERROR_HPP
