#include "Diagnostics.hpp"
#include <iostream>


std::map<std::string,std::string> Diagnostics::curr_status={};
Diagnostics::Diagnostics() {}

Diagnostics& Diagnostics::getInstance() {
    static Diagnostics instance;
    return instance;
}
void Diagnostics::update(const std::string& message,LogLevel level){
    std::cout << "-------------------------------------------------------"<<std::endl;
    std::string diag_message="[Diagnostics]->"+message;
    logger.log(diag_message,level);
    int end=message.find(" ");
    std::string type=message.substr(0,end);
    curr_status[type]=message;
    std::cout << "-------------------------------------------------------"<<std::endl;
    
}

void Diagnostics::status(){
    std::cout << "-------------------------------------------------------"<<std::endl;
    std::cout<<"Diagnostics current status:"<<std::endl;
    for(auto& [type,message]:curr_status){
        std::cout<<message<<std::endl;
    }
    std::cout << "-------------------------------------------------------"<<std::endl;
}
void Diagnostics::update(const std::string& message) {
   std::string diag_message="Diagnostics->"+message;
   logger.log(diag_message,LogLevel::INFO);
}


