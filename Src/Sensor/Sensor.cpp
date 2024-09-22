#include "Sensor.hpp"

Logger logger=Logger::get_instance();
Sensor::Sensor(int val,std::string type):value(val),type(type)
{
}

Sensor::Sensor(const Sensor& Instance):value{Instance.value},type{Instance.type}{

}
Sensor::Sensor(Sensor&& Instance):value{Instance.value},type{Instance.type}{
    Instance.value=0;
}
Sensor& Sensor::operator=(const Sensor& Instance){
    if(this!=&Instance){
        value=Instance.value;
        type=Instance.type;
    }
    return *this;
}
Sensor& Sensor::operator=(Sensor&& Instance){
    if(this!=&Instance){
        value=Instance.value;
        type=Instance.type;
        Instance.value=0;
        Instance.type="";
    }
    return *this;
}
void Sensor::update_value(int new_value){
    std::cout << "-------------------------------------------------------"<<std::endl;
    value=new_value;
    logger.log(type+" sensor updated successfuly",LogLevel::INFO);
    std::cout << "-------------------------------------------------------"<<std::endl;
}
Sensor::~Sensor()
{
}