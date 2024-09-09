#include "Logger.h"
#include <fstream>
#include <iostream>

void Logger::log(const std::string& message) {
    std::ofstream logFile("logs/server.log", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    } else {
        std::cerr << "Unable to open log file" << std::endl;
    }
}
