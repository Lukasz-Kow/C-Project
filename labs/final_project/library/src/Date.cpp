#include "Date.h"
#include <iostream>

std::string Date::getDate() {
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string date(11, '\0');
    strftime(&date[0], date.size(), "%Y-%m-%d", localtime(&now));
    return date.substr(0, date.size() - 1);
}