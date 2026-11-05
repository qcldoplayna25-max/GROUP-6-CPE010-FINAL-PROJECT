#include "Salestracker.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    SalesTracker tracker;
    int choice;

    do {
        cout << "\n============================================\n";
        cout << "       EMPLOYEE SALES PERFORMANCE TRACKER\n";
        cout << "============================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Record Employee Sale\n";
        cout << "4. Search Employee\n";
        cout << "5. Employees Rank By Sales\n";
        cout << "6. Add Employee to Evaluation Queue\n";
        cout << "7. Process Next Evaluation\n";
        cout << "8. View Sales Transaction History\n";
        cout << "9. Undo Last Sale\n";
        cout << "10. View Overall Sales Report\n";
        cout << "0. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: tracker.addEmployee(); break;
            case 2: tracker.displayEmployees(); break;
            case 3: tracker.recordSale(); break;
            case 4: tracker.searchEmployee(); break;
            case 5: tracker.rankEmployees(); break;
            case 6: tracker.addToEvaluationQueue(); break;
            case 7: tracker.processEvaluation(); break;
            case 8: tracker.showTransactionHistory(); break;
            case 9: tracker.undoLastSale(); break;
            case 10: tracker.showSalesReport(); break;
            case 0: cout << "\nThank you for using the system!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
