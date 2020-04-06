/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus.hpp
*/

/**
 * @brief Event bus, manager of events
 */

#ifndef OOP_ARCADE_2019_EVENTBUS_EVENTBUS_HPP
#define OOP_ARCADE_2019_EVENTBUS_EVENTBUS_HPP

#include <functional>
#include <map>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "AEvent.hpp"

namespace engine {

namespace eventbus {

/**
 * @brief Callback signature
 */
template<typename T, typename E>
using Callback = void (T::*)(E&);

/**
 * @brief Class of EventBus
 */
class EventBus {
  public:
    /**
     * @brief Interface of CallbackHandler
     */
    class ICallbackHandler {
      public:
        /**
         * @brief Destructor of ICallbackHandler
         */
        virtual ~ICallbackHandler() = 0;

        /**
         * @brief Call the subscriber callback
         *
         * @param event Reference of the event
         */
        virtual void call(AEvent& event) = 0;
    };

    /**
     * @brief Class of CallbackHandler
     *
     * @tparam T Type of the subscriber
     * @tparam E Type of the subscribed event
     */
    template<typename T, typename E>
    class CallbackHandler : public ICallbackHandler {
      public:
        /**
         * @brief Constructor of CallbackHandler
         *
         * @param subscriber Subscriber
         * @param callback Subscribed event
         */
        CallbackHandler(T& subscriber, Callback<T, E> callback) : _subscriber(subscriber), _callback(callback) {};
        /**
         * @brief Destructor of CallbackHandler
         */
        ~CallbackHandler() override = default;

        /**
         * @brief Call the subscriber callback
         *
         * @param event Reference of the event
         */
        void call(AEvent& event) override
        {
            (this->_subscriber.*this->_callback)(static_cast<E&>(event));
        }

      private:
        /**
         * @brief Reference of the subscriber
         */
        T& _subscriber;
        /**
         * @brief Callback
         */
        Callback<T, E> _callback;
    };

  public:
    /**
     * @brief Constructor of EventBus
     */
    EventBus();
    /**
     * @brief Destructor of EventBus
     */
    ~EventBus();

  public:
    /**
     * @brief Associate a subscriber to an event
     *
     * @tparam T Type of the subscriber
     * @tparam E Type of the subscribed event
     *
     * @param subscriber Subscriber
     * @param callback Subscribed event
     */
    template<typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback)
    {
        std::type_index id = typeid(E);
        auto* cbHandler = new CallbackHandler<T, E>(subscriber, callback);

        this->_cbHandlers[id].emplace_back(*cbHandler);
    }

    /**
     * @brief Unsubscribe all current subscribers
     */
    void unsubscribe()
    {
        this->_cbHandlers.clear();
    }

    /**
     * @brief Publish an event to associated subscribers
     *
     * @tparam E Type of the event
     *
     * @param event Event
     */
    template<typename E>
    void publish(E& event)
    {
        std::type_index id = typeid(E);

        if (this->_cbHandlers.count(id) == 0)
            return;

        auto& cbHandler = this->_cbHandlers.at(id);

        for (const auto& handler : cbHandler)
            handler.get().call(event);
    }

  private:
    /**
     * @brief Map of callbacks
     * Key: Event identifier
     * Value: Vector of callback
     */
    std::map<std::type_index, std::vector<std::reference_wrapper<ICallbackHandler>>> _cbHandlers;
};

} // namespace eventbus

} // namespace engine

#endif // OOP_ARCADE_2019_EVENTBUS_EVENTBUS_HPP
