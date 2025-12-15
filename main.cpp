#include <iostream>
#include "Attendance.h"

using namespace std;

int main() {
    Attendance system;
    int choice;

    do {
        cout << "\n--- Attendance Control System ---\n";
        cout << "1. Mark Attendance\n";
        cout << "2. Mark Departure\n";
        cout << "3. Find Employee\n";
        cout << "4. View Daily Report\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
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