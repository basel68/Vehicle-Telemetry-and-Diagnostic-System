#include "Battery.hpp"

Battery::Battery(int val,std::string type,int temp):Sensor(val,type),temp_(temp){
}
Battery::Battery(const Battery& Instance):Sensor(Instance.value,Instance.type),temp_(Instance.temp_){

}
Battery::Battery(Battery&& Instance):Sensor(Instance.value,Instance.type),temp_(Instance.temp_){
    Instance.value=0;
    Instance.temp_=0;
}
Battery& Battery::operator=(const Battery& Instance){
    Sensor::operator=(Instance);
    if(this!=&Instance){
        temp_=Instance.temp_;
    }
    return *this;
    
}
Battery& Battery::operator=(Battery&& Instance){
    Sensor::operator=(Instance);
    if(this!=&Instance){
        temp_=Instance.temp_;
        Instance.temp_=0;
    }
    return *this;
}
bool Battery::is_charged(){
    return value>19?true:false;
}
int Battery::get_value() const{
    return value;
}
int Battery::get_temperature(){
    return temp_;
}
std::string Battery::get_type(){
    return type;
}
void Battery::update_value(int new_value){
    Sensor::update_value(new_value);
    if(is_functional()){
        if(in_optimal_range()){
            logger.log(type+" sensor is in optimal range",LogLevel::INFO);
        }
        else{
        
          notifyObservers(type+" is about to die",LogLevel::WARNING);  
        }
    }
    else{
         notifyObservers(type+" sensor is malfunctioning",LogLevel::ERROR); 
    }
}
bool Battery::is_functional(){
    if(value==0){
        std::cout<<"System will stop working:Battery is down"<<std::endl;
        exit(EXIT_FAILURE);
        }
    return value>0 && value<=100 && temp_<35;
}
bool Battery::in_optimal_range(){
    return is_charged();
}
Battery::~Battery()
{
}