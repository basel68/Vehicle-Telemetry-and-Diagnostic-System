#include "Logger.hpp"
Logger::Logger()
{
    std::cout << "-------------------------------------------------------"<<std::endl;
    std::cout<<"Logger Started working..."<<std::endl;
    std::cout << "-------------------------------------------------------"<<std::endl;
}
Logger& Logger::get_instance(){
    static Logger instance;
    return instance;

}
void Logger::log(std::string message,LogLevel level){
        // Get current time
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    // Create a buffer to hold the formatted time
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    std::string log="LogLevel:";
    switch (level)
    {
    case LogLevel::INFO:
        log+="INFO";
        break;
    case LogLevel::ERROR:
        log+="ERROR";
        break;
    case LogLevel::WARNING:
        log+="WARNING";
        break;
    default:
        break;
    }
    // Print the message with a timestamp
    std::cout << "[" << buffer << "] " << message <<  " [" << log << "]"<< std::endl;
}
Logger::~Logger()
{
}
// int main(){
//     Logger x=Logger::get_instance();
//     x.log("gg",LogLevel::INFO);
//     return 0;
// }