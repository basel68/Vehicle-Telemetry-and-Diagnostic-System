#pragma once 
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "LogLevel.hpp"

/**
 * @class Logger
 * @brief Provides logging functionalities for the system.
 *
 * This class supports logging messages with various severity levels.
 */
class Logger {
private:
    Logger();    
public:
    /**
     * @brief Get the singleton instance of Logger.
     * 
     * @return Logger& Singleton instance.
     */
    static Logger& get_instance();

    /**
     * @brief Log a message with a specific severity level.
     * 
     * @param message Message to log.
     * @param level Severity level of the message.
     */
    void log(std::string message,LogLevel level);

    /**
     * @brief Destructor for Logger.
     */
    virtual ~Logger();
};
