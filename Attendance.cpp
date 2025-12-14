#include "Attendance.h"
#include <iostream>
#include <fstream>

using namespace std;

// تحويل الوقت لدقائق
int Attendance::timeToMinutes(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

// Check-In
void Attendance::checkIn() {
    ofstream file("attendance.txt", ios::app);

    string name, date, timeIn;

    cout << "Employee Name: ";
    cin >> name;
    cout << "Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Check-In Time (HH:MM): ";
    cin >> timeIn;

    file << name << " " << date << " " << timeIn << " -" << endl;
    file.close();

    cout << "Check-In saved successfully.\n";
}

// Check-Out (Merge Technique)
void Attendance::checkOut() {
    ifstream file("attendance.txt");
    ofstream temp("temp.txt");

    string name, date, timeOut;
    cout << "Employee Name: ";
    cin >> name;
    cout << "Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Check-Out Time (HH:MM): ";
    cin >> timeOut;

    string n, d, in, out;

    while (file >> n >> d >> in >> out) {
        if (n == name && d == date && out == "-") {
            temp << n << " " << d << " " << in << " " << timeOut << endl;
        } else {
            temp << n << " " << d << " " << in << " " << out << endl;
        }
    }

    file.close();
    temp.close();

    remove("attendance.txt");
    rename("temp.txt", "attendance.txt");

    cout << "Check-Out updated successfully.\n";
}

// Search
void Attendance::searchEmployee() {
    ifstream file("attendance.txt");
    string name;

    cout << "Enter employee name: ";
    cin >> name;

    string n, d, in, out;
    bool found = false;

    while (file >> n >> d >> in >> out) {
        if (n == name) {
            cout << n << " " << d << " " << in << " " << out << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No records found.\n";

    file.close();
}

// Daily Report
void Attendance::dailyReport() {
    ifstream file("attendance.txt");
    string date;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    string n, d, in, out;

    while (file >> n >> d >> in >> out) {
        if (d == date && out != "-") {
            int start = timeToMinutes(in);
            int end = timeToMinutes(out);
            int hours = ((end - start) / 60) * -1;

            cout << "Name: " << n
                 << " | Hours Worked: " << hours << endl;
        }
    }

    file.close();
}
