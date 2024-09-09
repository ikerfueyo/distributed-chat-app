#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    // Log messages to a file
    static void log(const std::string& message);
};

#endif // LOGGER_H
