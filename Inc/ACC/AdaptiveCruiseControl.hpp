#pragma once
#include "Observer.hpp"
#include "SpeedSensor.hpp"
#include "RadarSensor.hpp"

/**
 * @class AdaptiveCruiseControl
 * @brief Manages the adaptive cruise control feature of the vehicle.
 *
 * This class integrates with speed and radar sensors to adjust vehicle speed automatically.
 */
class AdaptiveCruiseControl : public Observer {
private:
    SpeedSensor speed; ///< Speed sensor object.
    RadarSensor radar; ///< Radar sensor object.

public:
    /**
     * @brief Construct a new Adaptive Cruise Control object.
     * 
     * @param speed_instance Reference to a speed sensor.
     * @param radar_instance Reference to a radar sensor.
     */
    AdaptiveCruiseControl(SpeedSensor& speed_instance, RadarSensor& radar_instance);

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
     * @brief Adjust the speed of the vehicle based on sensor readings.
     */
    void adjustSpeed();

   
};
