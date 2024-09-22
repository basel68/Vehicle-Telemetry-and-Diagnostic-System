#pragma once
#include "Sensor.hpp"

/**
 * @class SpeedSensor
 * @brief Represents a speed sensor in the vehicle, extending the Sensor class.
 *
 * This class is responsible for measuring and reporting the vehicle's speed.
 */
class SpeedSensor : public Sensor {
public:
    /**
     * @brief Construct a new Speed Sensor object.
     * 
     * @param val Initial speed measurement.
     * @param type Description of the sensor type, typically "Speed".
     */
    SpeedSensor(int val, std::string type);

    /**
     * @brief Copy constructor for SpeedSensor.
     * 
     * @param Instance The SpeedSensor instance to copy from.
     */
    SpeedSensor(const SpeedSensor& Instance);

    /**
     * @brief Move constructor for SpeedSensor.
     * 
     * @param Instance The SpeedSensor instance to move from.
     */
    SpeedSensor(SpeedSensor&& Instance);

    /**
     * @brief Copy assignment operator.
     * 
     * @param Instance The SpeedSensor instance to assign from.
     * @return Reference to the current instance.
     */
    SpeedSensor& operator=(const SpeedSensor& Instance);

    /**
     * @brief Move assignment operator.
     * 
     * @param Instance The SpeedSensor instance to move assign from.
     * @return Reference to the current instance.
     */
    SpeedSensor& operator=(SpeedSensor&& Instance);

    /**
     * @brief Get the current speed measurement.
     * 
     * @return int Current speed of the vehicle.
     */
    int get_value() const override;

    /**
     * @brief Set a new speed value for the sensor.
     * 
     * @param new_value The new speed to be set.
     * @return int The updated speed value.
     */
    int set_value(int new_value);

    /**
     * @brief Update the sensor's speed value.
     * 
     * @param new_value The new speed value.
     */
    void update_value(int new_value) override;

    /**
     * @brief Get the type of the sensor.
     * 
     * @return std::string The sensor type, "Speed".
     */
    std::string get_type() override;

    /**
     * @brief Check if the speed sensor is functional.
     * 
     * @return true If the sensor operates within normal parameters.
     * @return false If the sensor fails operational checks.
     */
    bool is_functional() override;

    /**
     * @brief Check if the speed is within the optimal range.
     * 
     * @return true If the speed is within safe operating limits.
     * @return false Otherwise.
     */
    bool in_optimal_range() override;

    /**
     * @brief Destructor for SpeedSensor.
     */
    virtual ~SpeedSensor();
};
