#ifndef EVENT_DISPATCHER
#define EVENT_DISPATCHER

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class InternalEventDispatcher 
{
public:
    static void addListener(std::string event, std::function<void()> listenerCallback) { callbackMap[event].push_back(listenerCallback); }
    static void broadcastEvent(std::string event) { for (auto& function : callbackMap[event]) { function(); } }
    // static void removeListener(std::string event, std::function<void()> listenerCallback) { if (!callbackMap[event].empty()) {  callbackMap[event].erase(std::remove(callbackMap[event].begin(), callbackMap[event].end(), listenerCallback), callbackMap[event].end()); } }
private:
    static std::unordered_map<std::string, std::vector<std::function<void()>>> callbackMap;
};

template<typename T>
class InternalOneInputEventDispatcher 
{
public:
    // One-parameter methods
    static void addListener(std::string event, std::function<void(T)> listenerCallback) { callbackMap[event].push_back(listenerCallback); }
    static void broadcastEvent(std::string event, T data) { for (auto& function : callbackMap[event]) { function(data); } }
    // static void removeListener(std::string event, std::function<void(T)> listenerCallback) { if (!callbackMap[event].empty()) {  callbackMap[event].erase(std::remove(callbackMap[event].begin(), callbackMap[event].end(), listenerCallback), callbackMap[event].end()); } }
private:
    static std::unordered_map<std::string, std::vector<std::function<void(T)>>> callbackMap;
};

template<typename T, typename U>
class InternalTwoInputEventDispatcher 
{
public:
    static void addListener(std::string event, std::function<void(T, U)> listenerCallback) { callbackMap[event].push_back(listenerCallback); }
    static void broadcastEvent(std::string event, T data1, U data2) { for (auto& function : callbackMap[event]) { function(data1, data2); } }
    // static void removeListener(std::string event, std::function<void(T, U)> listenerCallback) { if (!callbackMap[event].empty()) {  callbackMap[event].erase(std::remove(callbackMap[event].begin(), callbackMap[event].end(), listenerCallback), callbackMap[event].end()); } }
private:
    static std::unordered_map<std::string, std::vector<std::function<void(T, U)>>> callbackMap;
};  

// For EventDispatcher<void>
// std::unordered_map<std::string, std::vector<std::function<void()>>> InternalEventDispatcher::callbackMap;

// For EventDispatcher<T>
template<typename T>
std::unordered_map<std::string, std::vector<std::function<void(T)>>> InternalOneInputEventDispatcher<T>::callbackMap;

// For EventDispatcher<T, U>
template<typename T, typename U>
std::unordered_map<std::string, std::vector<std::function<void(T, U)>>> InternalTwoInputEventDispatcher<T, U>::callbackMap;


class EventDispatcher 
{
public:
    // No-parameter methods
    static void addListener(std::string event, std::function<void()> listenerCallback) { InternalEventDispatcher::addListener(event, listenerCallback); }
    static void broadcastEvent(std::string event) { InternalEventDispatcher::broadcastEvent(event); }
    // static void removeListener(std::string event, std::function<void()> listenerCallback);

    // One-parameter methods
    template<typename T>
    static void addListener(std::string event, std::function<void(T)> listenerCallback) { InternalOneInputEventDispatcher<T>::addListener(event, listenerCallback); }
    template<typename T>
    static void broadcastEvent(std::string event, T data) { InternalOneInputEventDispatcher<T>::broadcastEvent(event, data); }
    // template<typename T>
    // static void removeListener(std::string event, std::function<void(T)> listenerCallback) { InternalOneInputEventDispatcher<T>::removeListener(event, listenerCallback); }

    // Two-parameter methods
    template<typename T, typename U>
    static void addListener(std::string event, std::function<void(T, U)> listenerCallback) { InternalTwoInputEventDispatcher<T, U>::addListener(event, listenerCallback); }
    template<typename T, typename U>
    static void broadcastEvent(std::string event, T data1, U data2) { InternalTwoInputEventDispatcher<T, U>::broadcastEvent(event, data1, data2); }
    // template<typename T, typename U>
    // static void removeListener(std::string event, std::function<void(T, U)> listenerCallback) { InternalTwoInputEventDispatcher<T, U>::removeListener(event, listenerCallback); }
};


#endif