#pragma once
#include "Sensor.hpp"

/**
 * @class TemperatureSensor
 * @brief Represents a temperature sensor in the vehicle, extending the Sensor class.
 *
 * This class is responsible for monitoring the temperature of critical components or environments.
 */
class TemperatureSensor : public Sensor {
public:
    /**
     * @brief Construct a new Temperature Sensor object.
     * 
     * @param val Initial temperature measurement.
     * @param type Description of the sensor type, typically "Temperature".
     */
    TemperatureSensor(int val, std::string type);

    /**
     * @brief Copy constructor for TemperatureSensor.
     * 
     * @param Instance The TemperatureSensor instance to copy from.
     */
    TemperatureSensor(const TemperatureSensor& Instance);

    /**
     * @brief Move constructor for TemperatureSensor.
     * 
     * @param Instance The TemperatureSensor instance to move from.
     */
    TemperatureSensor(TemperatureSensor&& Instance);

    /**
     * @brief Copy assignment operator.
     * 
     * @param Instance The TemperatureSensor instance to assign from.
     * @return Reference to the current instance.
     */
    TemperatureSensor& operator=(const TemperatureSensor& Instance);

    /**
     * @brief Move assignment operator.
     * 
     * @param Instance The TemperatureSensor instance to move assign from.
     * @return Reference to the current instance.
     */
    TemperatureSensor& operator=(TemperatureSensor&& Instance);

    /**
     * @brief Get the current temperature measurement.
     * 
     * @return int Current temperature.
     */
    int get_value() const override;

    /**
     * @brief Update the sensor's temperature value.
     * 
     * @param new_value The new temperature to be set.
     */
    void update_value(int new_value) override;

    /**
     * @brief Get the type of the sensor.
     * 
     * @return std::string The sensor type, "Temperature".
     */
    std::string get_type() override;

    /**
     * @brief Check if the temperature sensor is functional.
     * 
     * @return true If the sensor operates within normal parameters.
     * @return false If the sensor fails operational checks.
     */
    bool is_functional() override;

    /**
     * @brief Check if the temperature is within the optimal range.
     * 
     * @return true If the temperature is within safe operational limits.
     * @return false Otherwise.
     */
    bool in_optimal_range() override;

    /**
     * @brief Destructor for TemperatureSensor.
     */
    virtual ~TemperatureSensor();
};
