#include"Vehicle.hpp"

Vehicle::Vehicle()
{
    sensors.push_back(std::make_shared<Battery>(100, "Battery", 26));
    sensors.push_back(std::make_shared<RadarSensor>(100, "Radar"));
    sensors.push_back(std::make_shared<TemperatureSensor>(25, "Temperature"));
    sensors.push_back(std::make_shared<SpeedSensor>(0, "Speed"));
}
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);  
}

void Vehicle::update_sensors(){
    for(auto &sensor:sensors){
        sensor->update_value(getRandomNumber(0,260));
    }
}
void Vehicle::start_diagnostics(){
    for(auto &sensor:sensors){
        sensor->attach(&Diagnostics::getInstance());
    }
}

 void Vehicle::start_ACC(){
    
    std::array<std::shared_ptr<Sensor>,2> ref;
    for(auto &sensor:sensors){

        if(sensor->get_type()=="Speed")
            ref[0]=sensor;
        else if(sensor->get_type()=="Radar")
            ref[1]=sensor;
        
    }
    acc=std::make_shared<AdaptiveCruiseControl>(*(std::dynamic_pointer_cast<SpeedSensor>(ref[0])),*(std::dynamic_pointer_cast<RadarSensor>(ref[1])));
    ref[0]->attach(acc.get());
    ref[1]->attach(acc.get());
 }
void Vehicle::display_dashboard() {
    for(auto &sensor:sensors){
        if(sensor->get_type()=="Battery"){
            
            std::cout << "Battery Level: " << sensor->get_value() << "%, Temperature: " << std::dynamic_pointer_cast<Battery>(sensor)->get_temperature()<< " °C\n";
        }
        else if(sensor->get_type()=="Radar"){
            std::cout << "Radar Distance: " <<sensor->get_value()<< " meters\n";
        }
        else if(sensor->get_type()=="Speed"){
            std::cout << "Current Speed: " << sensor->get_value() << " km/h\n";
        }
        else{
            std::cout << "Engine Temperature: " <<sensor->get_value() << " °C\n";
        }
    }
    Diagnostics::status();
    
    
}

Vehicle::~Vehicle()
{
}

int main(){

    Vehicle car;
    car.start_diagnostics();
    car.start_ACC();
     car.update_sensors();
     
    while (1)
    {

        car.update_sensors();
        for (long i = 0; i < 2000000000; i++);
        
        
    }
    Diagnostics::status();
    // car.display_dashboard();
    return 0;
}
