#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>

using namespace std;

class Attendance {
public:
    void checkIn();
    void checkOut();
    void searchEmployee();
    void dailyReport();

private:
    int timeToMinutes(string time);
};

#endif