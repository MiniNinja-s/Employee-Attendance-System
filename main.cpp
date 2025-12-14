#include <iostream>
#include "Attendance.h"

using namespace std;

int main() {
    Attendance system;
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
            system.checkIn();
            break;
        case 2:
            system.checkOut();
            break;
        case 3:
            system.searchEmployee();
            break;
        case 4:
            system.dailyReport();
            break;
        case 5:
            cout << "As-salamu alaykum!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
