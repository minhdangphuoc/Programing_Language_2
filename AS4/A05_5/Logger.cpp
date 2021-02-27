#include "Logger.h"
#include <iostream>
void Logger::information(std::string desc, bool echo) {
    if (!echo) {
        return;
    }
    std::cout << desc;
}
