// ============================ Time ============================

#include "Time.h"

#include <iostream>


Time::Time(int seconds) {
    this->seconds = seconds;
}
void Time::setSeconds(int seconds) {
    this->seconds = seconds;
}
void Time::print() {
    int total = seconds;
    // Если время превышает сутки, показываем только последние сутки.
    if (total > 86400) {
        total = total - 86400;
    }
    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int secs = total % 60;
    std::cout << hours << ":" << minutes << ":" << secs << std::endl;
}
Time::~Time() {}
