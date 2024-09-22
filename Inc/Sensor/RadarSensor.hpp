#pragma once
#include "Sensor.hpp"

/**
 * @class RadarSensor
 * @brief Represents a radar sensor in the vehicle, extending the Sensor class.
 *
 * This class handles distance measurement functionalities to detect objects and calculate the distance to them.
 */
class RadarSensor : public Sensor {
public:
    /**
     * @brief Construct a new Radar Sensor object.
     * 
     * @param val Initial distance measurement.
     * @param type Description of the sensor type, typically "Radar".
     */
    RadarSensor(int val, std::string type);

    /**
     * @brief Copy constructor for RadarSensor.
     * 
     * @param Instance The RadarSensor instance to copy from.
     */
    RadarSensor(const RadarSensor& Instance);

    /**
     * @brief Move constructor for RadarSensor.
     * 
     * @param Instance The RadarSensor instance to move from.
     */
    RadarSensor(RadarSensor&& Instance);

    /**
     * @brief Copy assignment operator.
     * 
     * @param Instance The RadarSensor instance to assign from.
     * @return Reference to the current instance.
     */
    RadarSensor& operator=(const RadarSensor& Instance);

    /**
     * @brief Move assignment operator.
     * 
     * @param Instance The RadarSensor instance to move assign from.
     * @return Reference to the current instance.
     */
    RadarSensor& operator=(RadarSensor&& Instance);

    /**
     * @brief Update the radar's distance measurement.
     * 
     * @param new_value The new distance value.
     */
    void update_value(int new_value) override;

    /**
     * @brief Get the current distance measurement.
     * 
     * @return int Current distance to the closest object.
     */
    int get_value() const override;

    /**
     * @brief Get the type of the sensor.
     * 
     * @return std::string The sensor type, "Radar".
     */
    std::string get_type() override;

    /**
     * @brief Check if the radar sensor is functional.
     * 
     * @return true If the radar operates within normal parameters.
     * @return false If the radar fails operational checks.
     */
    bool is_functional() override;

    /**
     * @brief Check if the radar's measurements are within the optimal range.
     * 
     * @return true If the measurements are within safe operational limits.
     * @return false Otherwise.
     */
    bool in_optimal_range() override;

    /**
     * @brief Destructor for RadarSensor.
     */
    virtual ~RadarSensor();
};
