#include "Sales-Tracker.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    SalesTracker tracker;
    int choice = 0;

    do {
        cout << "\n+++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "      EMPLOYEE SALES TRACKER\n";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "1. Add employee\n";
        cout << "2. Display employees\n";
        cout << "3. Record sale\n";
        cout << "4. Search employee\n";
        cout << "5. Rank employees\n";
        cout << "6. Sales quota analysis\n";
        cout << "7. Add employee to evaluation queue\n";
        cout << "8. Process evaluation queue\n";
        cout << "9. Show transaction history\n";
        cout << "10. Undo last sale\n";
        cout << "11. Show sales report\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                tracker.addEmployee();
                break;
            case 2:
                tracker.displayEmployees();
                break;
            case 3:
                tracker.recordSale();
                break;
            case 4:
                tracker.searchEmployee();
                break;
            case 5:
                tracker.rankEmployees();
                break;
            case 6:
                tracker.countEmployeesMeetingQuota();
                break;
            case 7:
                tracker.addToEvaluationQueue();
                break;
            case 8:
                tracker.processEvaluation();
                break;
            case 9:
                tracker.showTransactionHistory();
                break;
            case 10:
                tracker.undoLastSale();
                break;
            case 11:
                tracker.showSalesReport();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
