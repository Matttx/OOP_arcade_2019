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
/**
 * @class Error that inherits from std::exception
 * 
 */
class Error : public std::exception {
  public:
    /**
     * @brief Construct a new Error object
     * 
     * @param subject : the subject of the error
     * @param message : the error message
     */
    Error(const std::string& subject, const std::string& message);
    /**
     * @brief Destroy the Error object
     * 
     */
    ~Error() override;

  public:
    /**
     * @brief what : function that say the origin of the error
     * 
     * @return const char* : the error message
     */
    const char* what() const noexcept override;

  private:
    /**
     * @brief _what : error message
     * 
     */
    std::string _what;
};

} // namespace util

} // namespace engine

#endif // OOP_ARCADE_2019_ERROR_HPP
