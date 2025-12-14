#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// تحويل الوقت من HH:MM لدقائق
int timeToMinutes(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

// تسجيل الحضور
void checkIn() {
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

// تسجيل الانصراف (Merge Technique)
void checkOut() {
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

// البحث عن موظف
void searchEmployee() {
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

// التقرير اليومي
void dailyReport() {
    ifstream file("attendance.txt");
    string date;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    string n, d, in, out;

    while (file >> n >> d >> in >> out) {
        if (d == date && out != "-") {
            int start = timeToMinutes(in);
            int end = timeToMinutes(out);
            int hours = (end - start) / 60;

            cout << "Name: " << n
                 << " | Hours Worked: " << hours << endl;
        }
    }

    file.close();
}

// المينيو
int main() {
    int choice;

    do {
        cout << "\n--- Attendance System ---\n";
        cout << "1. Check-In\n";
        cout << "2. Check-Out\n";
        cout << "3. Search Employee\n";
        cout << "4. Daily Report\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkIn();
            break;
        case 2:
            checkOut();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            dailyReport();
            break;
        case 5:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
