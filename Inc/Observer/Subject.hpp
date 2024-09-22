#pragma once

#include "Observer.hpp"
#include <vector>
#include <algorithm>
#include <memory>

/**
 * @class Subject
 * @brief Base class for subjects that notify observers of changes.
 *
 * This class maintains a list of observers and notifies them of changes.
 */
class Subject {
protected:
    std::vector<Observer*> observers; ///< List of observers.

public:
 
    void attach(Observer* observer);

    /**
     * @brief Notify all attached observers of a change.
     * 
     * @param message Message indicating the change.
     */
    void notifyObservers(const std::string& message);

    /**
     * @brief Notify all attached observers of a change with a specific log level.
     * 
     * @param message Message indicating the change.
     * @param level Log level of the message.
     */
    void notifyObservers(const std::string& message, LogLevel level);

    /**
     * @brief Destructor for Subject.
     */
    virtual ~Subject();
};


