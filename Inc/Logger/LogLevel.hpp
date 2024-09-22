#pragma once

/**
 * @enum LogLevel
 * @brief Defines severity levels for logging purposes.
 *
 * This enumeration is used throughout the system to categorize the severity of log messages.
 * It helps in filtering and handling logs appropriately based on their importance and urgency.
 */
enum class LogLevel {
    ERROR,   ///< Indicates a serious error, the application may not be able to continue running.
    WARNING, ///< Indicates a potential issue that should be taken care of.
    INFO     ///< Indicates informational messages that report normal operation or system status.
};
