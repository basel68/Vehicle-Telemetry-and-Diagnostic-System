#include "SpeedSensor.hpp"
SpeedSensor::SpeedSensor(int val,std::string type):Sensor(val,type)
{
}
SpeedSensor::SpeedSensor(const SpeedSensor& Instance):Sensor(Instance.value,Instance.type){

}
SpeedSensor::SpeedSensor(SpeedSensor&& Instance):Sensor(Instance.value,Instance.type){
    Instance.value=0;
}
SpeedSensor& SpeedSensor::operator=(const SpeedSensor& Instance){
    Sensor::operator=(Instance);
    return *this;
}
SpeedSensor& SpeedSensor::operator=(SpeedSensor&& Instance){
    Sensor::operator=(Instance);
    return *this;
}
SpeedSensor::~SpeedSensor()
{
}
int SpeedSensor::get_value() const{
    return value;
}
int SpeedSensor::set_value(int new_value){
    return value=new_value;
}
void SpeedSensor::update_value(int new_value){
    Sensor::update_value(new_value);
    if(is_functional()){
        if(in_optimal_range()){
            logger.log(type+" sensor is in optimal range",LogLevel::INFO);
        }
        else{
          notifyObservers(type+" is too high!",LogLevel::WARNING);  
        }
    }
    else{
         notifyObservers(type+" sensor is malfunctioning",LogLevel::ERROR); 
    }
}
std::string SpeedSensor::get_type(){
    return type;
}
bool SpeedSensor::is_functional(){
    return (value >= 0 && value <= 300); // Assuming speed is measured in km/h
}
bool SpeedSensor::in_optimal_range(){
    return (value >= 0 && value <= 200); 
}