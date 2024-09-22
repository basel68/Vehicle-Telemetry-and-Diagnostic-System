#include "RadarSensor.hpp"

RadarSensor::RadarSensor(int val,std::string type):Sensor(val,type)
{
}
RadarSensor::RadarSensor(const RadarSensor& Instance):Sensor(Instance.value,Instance.type){

}
RadarSensor::RadarSensor(RadarSensor&& Instance):Sensor(Instance.value,Instance.type){
    Instance.value=0;
}
RadarSensor& RadarSensor::operator=(const RadarSensor& Instance){
    Sensor::operator=(Instance);
    return *this;
}
RadarSensor& RadarSensor::operator=(RadarSensor&& Instance){
    Sensor::operator=(Instance);
    return *this;
}
std::string RadarSensor::get_type(){
    return type;
}
bool RadarSensor::is_functional(){
    return value>=0;
}
int RadarSensor::get_value() const{
    return value;
}
void RadarSensor::update_value(int new_value){
    Sensor::update_value(new_value);
    if(is_functional()){
        
        if(in_optimal_range()){
            logger.log(type+" sensor is in optimal range",LogLevel::INFO);
        }
        else{
        
          notifyObservers(type+" sensor detected a close object",LogLevel::WARNING);  
        }
    }
    else{
         notifyObservers(type+" sensor is malfunctioning",LogLevel::ERROR); 
    }
}
bool RadarSensor::in_optimal_range(){
    return value>50;
}
RadarSensor::~RadarSensor()
{
}

