#pragma once

#include <iostream>
#include "Sensor.hpp"
#include <map>
#include "AdaptiveCruiseControl.hpp"
/**
 * @class Diagnostics
 * @brief Manages diagnostic reporting for the vehicle.
 *
 * This class collects and reports on system health and errors.
 */
class Diagnostics : public Observer {
private:
    static std::map<std::string, std::string> curr_status; ///< Current status of various system components.
    Diagnostics();
public:
    /**
     * @brief Get the singleton instance of Diagnostics.
     * 
     * @return Diagnostics& Singleton instance.
     */
    static Diagnostics& getInstance();

    /**
     * @brief Respond to updates from observed subjects.
     * 
     * @param message Message detailing the update.
     */
    void update(const std::string& message) override;

    /**
     * @brief Respond to updates from observed subjects with log level.
     * 
     * @param message Message detailing the update.
     * @param level Severity level of the message.
     */
    void update(const std::string& message, LogLevel level) override;

    /**
     * @brief Display current system status.
     */
    static void status();

    // Disallow copying and assignment
    Diagnostics(const Diagnostics&) = delete;
    Diagnostics& operator=(const Diagnostics&) = delete;


};
