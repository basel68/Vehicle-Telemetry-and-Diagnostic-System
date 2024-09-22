#pragma once
#include <string>
#include "LogLevel.hpp"

/**
 * @class Observer
 * @brief Interface for observer classes.
 *
 * This class defines the observer interface for objects that need to receive updates from subjects.
 */
class Observer {
public:
    /**
     * @brief Update the observer with a message.
     * 
     * @param message Message to update the observer with.
     */
    virtual void update(const std::string& message) = 0;

    /**
     * @brief Update the observer with a message and a log level.
     * 
     * @param message Message to update the observer with.
     * @param level Log level of the message.
     */
    virtual void update(const std::string& message, LogLevel level) = 0;

  
};
