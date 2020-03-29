/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus.hpp
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

template<typename T, typename E>
using Callback = void (T::*)(E&);

class EventBus {
  public:
    class ICallbackHandler {
      public:
        virtual ~ICallbackHandler() = 0;

        virtual void call(AEvent& event) = 0;
    };

    template<typename T, typename E>
    class CallbackHandler : public ICallbackHandler {
      public:
        CallbackHandler(T& subscriber, Callback<T, E> callback)
            : _subscriber(subscriber), _callback(callback) {};
        ~CallbackHandler() override = default;

        void call(AEvent& event) override
        {
            this->_subscriber->*this->_callback(static_cast<E&>(event));
        }

      private:
        T& _subscriber;
        Callback<T, E> _callback;
    };

  public:
    EventBus();
    ~EventBus();

  public:
    template<typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback)
    {
        std::type_index id = typeid(E);
        auto* cbHandler = new CallbackHandler<T, E>(subscriber, callback);

        this->_cbHandlers[id].emplace_back(*cbHandler);
    }

    void unsubscribe()
    {
        this->_cbHandlers.clear();
    }

    template<typename E>
    void publish(E& event)
    {
        std::type_index id = typeid(E);
        auto& cbHandler = this->_cbHandlers.at(id);

        for (const auto& handler : cbHandler)
            handler.get().call(event);
    }

  private:
    std::map<std::type_index,
        std::vector<std::reference_wrapper<ICallbackHandler>>>
        _cbHandlers;
};

} // namespace eventbus

} // namespace engine

#endif // OOP_ARCADE_2019_EVENTBUS_EVENTBUS_HPP
