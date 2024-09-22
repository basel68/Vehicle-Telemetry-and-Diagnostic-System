#include "TemperatureSensor.hpp"
TemperatureSensor::TemperatureSensor(int val,std::string type):Sensor(val,type)
{
}
TemperatureSensor::TemperatureSensor(const TemperatureSensor& Instance):Sensor(Instance.value,Instance.type){

}
TemperatureSensor::TemperatureSensor(TemperatureSensor&& Instance):Sensor(Instance.value,Instance.type){
    Instance.value=0;
}
TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& Instance){
    Sensor::operator=(Instance);
    return *this;
}
TemperatureSensor& TemperatureSensor::operator=(TemperatureSensor&& Instance){
    Sensor::operator=(Instance);
    return *this;
}

int TemperatureSensor::get_value() const{
    return value;
}
void TemperatureSensor::update_value(int new_value){
    Sensor::update_value(new_value);
    if(is_functional()){
        if(in_optimal_range()){
            logger.log(type+" sensor is in optimal range",LogLevel::INFO);
        }
        else{
            if(value>=30)
                notifyObservers("temperature is high ",LogLevel::WARNING);  
            else{
                notifyObservers("temperature is low ",LogLevel::WARNING);  
          }
        }
    }
    else{
         notifyObservers(type+" sensor is malfunctioning",LogLevel::ERROR); 
    }
}
std::string TemperatureSensor::get_type(){
    return type;
}
bool TemperatureSensor::is_functional(){
    return value<35 && value>15;
}
bool TemperatureSensor::in_optimal_range(){
    return value<30 && value>20;
}
TemperatureSensor::~TemperatureSensor()
{
}
