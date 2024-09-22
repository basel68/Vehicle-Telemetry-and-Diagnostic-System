#pragma once
#include "Sensor.hpp"
#include <cstdlib>

/**
 * @class Battery
 * @brief Represents a battery sensor in the vehicle, extending the Sensor class.
 *
 * This class handles battery-specific sensor data such as charge level and temperature.
 */
class Battery : public Sensor {
private:
    int temp_; ///< Current temperature of the battery.

public:
    /**
     * @brief Construct a new Battery object.
     * 
     * @param val Initial charge level of the battery.
     * @param type Description of the sensor type.
     * @param temp Initial temperature of the battery.
     */
    Battery(int val, std::string type, int temp);

    /**
     * @brief Copy constructor for Battery.
     * 
     * @param Instance The Battery instance to copy from.
     */
    Battery(const Battery& Instance);

    /**
     * @brief Move constructor for Battery.
     * 
     * @param Instance The Battery instance to move from.
     */
    Battery(Battery&& Instance);

    /**
     * @brief Copy assignment operator.
     * 
     * @param Instance The Battery instance to assign from.
     * @return Reference to the current instance.
     */
    Battery& operator=(const Battery& Instance);

    /**
     * @brief Move assignment operator.
     * 
     * @param Instance The Battery instance to move assign from.
     * @return Reference to the current instance.
     */
    Battery& operator=(Battery&& Instance);

    /**
     * @brief Gets the current value of the battery charge level.
     * 
     * @return int Current battery charge level.
     */
    int get_value() const override;

    /**
     * @brief Updates the battery's charge level.
     * 
     * @param new_value The new charge level.
     */
    void update_value(int new_value) override;

    /**
     * @brief Checks if the battery is fully charged.
     * 
     * @return true If the battery is charged above a certain threshold.
     * @return false Otherwise.
     */
    bool is_charged();

    /**
     * @brief Gets the current temperature of the battery.
     * 
     * @return int The current temperature in Celsius.
     */
    int get_temperature();

    /**
     * @brief Gets the type of the sensor.
     * 
     * @return std::string The sensor type.
     */
    std::string get_type() override;

    /**
     * @brief Checks if the battery is functional.
     * 
     * @return true If the battery operates within normal parameters.
     * @return false If the battery fails operational checks.
     */
    bool is_functional() override;

    /**
     * @brief Checks if the battery's temperature is within an optimal range.
     * 
     * @return true If the temperature is within safe operating limits.
     * @return false Otherwise.
     */
    bool in_optimal_range() override;

    /**
     * @brief Destructor for Battery.
     */
    virtual ~Battery();
};
