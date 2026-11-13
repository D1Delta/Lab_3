//
// Created by student on 13.11.2026.
//

#ifndef TIME_H
#define TIME_H
class Time {
public:
    Time(int seconds);
    void setSeconds(int seconds);
    void print();
    ~Time();
private:
    int seconds;
};
#endif //TIME_H
