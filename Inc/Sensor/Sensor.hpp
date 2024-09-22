#pragma once
#include "Subject.hpp"
#include "Logger.hpp"
#include <string>

/**
 * @brief Abstract base class representing a generic sensor.
 * 
 * Sensor class serves as a base for various types of sensors within the vehicle,
 * providing fundamental attributes and operations that all sensors must implement.
 */
class Sensor : public Subject {
protected:
    int value; ///< Current value reported by the sensor.
    std::string type; ///< Type of the sensor.

public:
    /**
     * @brief Construct a new Sensor object.
     * 
     * @param val Initial value of the sensor.
     * @param type Type description of the sensor.
     */
    Sensor(int val, std::string type);

    /**
     * @brief Copy constructor.
     * 
     * @param Instance Reference to the sensor instance to be copied.
     */
    Sensor(const Sensor& Instance);

    /**
     * @brief Move constructor.
     * 
     * @param Instance R-value reference to the sensor instance to be moved.
     */
    Sensor(Sensor&& Instance);

    /**
     * @brief Copy assignment operator.
     * 
     * @param Instance Reference to the sensor instance to be copied.
     * @return Sensor& Reference to the copied sensor object.
     */
    Sensor& operator=(const Sensor& Instance);

    /**
     * @brief Move assignment operator.
     * 
     * @param Instance R-value reference to the sensor instance to be moved.
     * @return Sensor& Reference to the moved sensor object.
     */
    Sensor& operator=(Sensor&& Instance);

    /**
     * @brief Get the current sensor value.
     * 
     * @return int Current sensor value.
     */
    virtual int get_value() const = 0;

    /**
     * @brief Update the sensor's value.
     * 
     * @param new_value New value to update the sensor to.
     */
    virtual void update_value(int new_value);

    /**
     * @brief Get the type of the sensor.
     * 
     * @return std::string Sensor type.
     */
    virtual std::string get_type() = 0;

    /**
     * @brief Check if the sensor is currently functional.
     * 
     * @return bool True if the sensor is functional, otherwise false.
     */
    virtual bool is_functional() = 0;

    /**
     * @brief Check if the sensor's value is within the optimal range.
     * 
     * @return bool True if the value is in the optimal range, otherwise false.
     */
    virtual bool in_optimal_range() = 0;

    /**
     * @brief Virtual destructor for the Sensor class.
     */
    virtual ~Sensor();
};

extern Logger logger;



