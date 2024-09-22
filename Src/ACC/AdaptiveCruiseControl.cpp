#include "AdaptiveCruiseControl.hpp"
 AdaptiveCruiseControl::AdaptiveCruiseControl(SpeedSensor& speed_instance,RadarSensor& radar_instance):speed{speed_instance},radar{radar_instance}{

 }
 void AdaptiveCruiseControl::adjustSpeed() {
            std::cout << "-------------------------------------------------------"<<std::endl;
            std::cout << "Adjusting speed...\n";
            // reduce speed
            speed.set_value(speed.get_value() - 5);
        
    }
void AdaptiveCruiseControl::update(const std::string& message,LogLevel level){
    adjustSpeed();
    std::cout<<"AdaptiveCruiseControl handled this diagnostics issue->"<<message<<std::endl;
    std::cout << "-------------------------------------------------------"<<std::endl;
}
 void AdaptiveCruiseControl::update(const std::string& message){
    
 }
