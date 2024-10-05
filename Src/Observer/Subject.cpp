#include "Subject.hpp"



    void Subject::attach(Observer * observer) {
        observers.push_back(observer);
    }

   

    void Subject::notifyObservers(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
     void Subject::notifyObservers(const std::string& message,LogLevel level) {
        for (auto observer : observers) {
            observer->update(message,level);
        }
    }
    
 Subject::~Subject(){
    
 }

