#pragma once
#include <vector>
#include "Sensor.hpp"
#include "Battery.hpp"
#include "RadarSensor.hpp"
#include "TemperatureSensor.hpp"
#include "SpeedSensor.hpp"
#include "Diagnostics.hpp"
#include <cstdlib>  
#include <iostream>
#include <memory>
#include <array>

/**
 * @class Vehicle
 * @brief Represents the vehicle system integrating various sensors and features.
 *
 * This class manages a collection of sensors and controls for adaptive cruise control,
 * along with diagnostics for monitoring vehicle performance and safety.
 */
class Vehicle
{
private:
    std::vector<std::shared_ptr<Sensor>> sensors; ///< Collection of sensors installed in the vehicle.
    std::shared_ptr<AdaptiveCruiseControl> acc; ///< Adaptive cruise control system instance.

public:
    /**
     * @brief Construct a new Vehicle object.
     *
     * Initializes the vehicle, setting up sensors and any required subsystems.
     */
    Vehicle();

    /**
     * @brief Update sensor readings.
     *
     * This function cycles through all sensors, updating their readings. This simulates
     * real-time data updates from each sensor.
     */
    void update_sensors();

    /**
     * @brief Display the dashboard.
     *
     * Outputs the current status of all sensors to the standard output, mimicking a vehicle's
     * dashboard display.
     */
    void display_dashboard();

    /**
     * @brief Start the diagnostics system.
     *
     * Attaches the diagnostics system to all sensors, allowing for continuous monitoring
     * and reporting of sensor status.
     */
    void start_diagnostics();

    /**
     * @brief Initialize the adaptive cruise control system.
     *
     * Configures the adaptive cruise control by linking it with the relevant speed and
     * radar sensors.
     */
    void start_ACC();

    /**
     * @brief Destroy the Vehicle object.
     *
     * Cleans up any resources, ensuring proper shutdown of all vehicle systems and sensors.
     */
    ~Vehicle();
};