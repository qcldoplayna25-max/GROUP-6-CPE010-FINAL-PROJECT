#include "Sales-tracker.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

int SalesTracker::findEmployeeIndex(int id) const {
    // LINEAR SEARCH: checks employee IDs one by one.
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void SalesTracker::addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "\nEmployee storage is full.\n";
        return;
    }

    Employee e;
    cout << "\n--- ADD EMPLOYEE ---\n";
    cout << "Employee ID: ";
    cin >> e.id;
    if (cin.fail()) {
        cout << "Invalid ID. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (findEmployeeIndex(e.id) != -1) {
        cout << "That employee ID already exists.\n";
        return;
    }

    cout << "Employee name: ";
    getline(cin, e.name);
    cout << "Position: ";
    getline(cin, e.position);

    e.totalSales = 0.0;
    e.transactionCount = 0;
    employees[employeeCount++] = e;

    cout << "Employee added successfully!\n";
}

void SalesTracker::displayEmployees() const {
    cout << "\n--- EMPLOYEE LIST ---\n";
    if (employeeCount == 0) {
        cout << "No employees recorded yet.\n";
        return;
    }

    cout << left << setw(12) << "ID"
         << setw(25) << "NAME"
         << setw(20) << "POSITION"
         << right << setw(15) << "TOTAL SALES" << '\n';
    cout << string(72, '-') << '\n';

    for (int i = 0; i < employeeCount; ++i) {
        cout << left << setw(12) << employees[i].id
             << setw(25) << employees[i].name.substr(0, 23)
             << setw(20) << employees[i].position.substr(0, 18)
             << right << "PHP " << fixed << setprecision(2)
             << employees[i].totalSales << '\n';
    }
}

void SalesTracker::recordSale() {
    int id;
    double amount;
    string date;

    cout << "\n--- RECORD SALE ---\n";
    cout << "Employee ID: ";
    cin >> id;

    int index = findEmployeeIndex(id);
    if (index == -1) {
        cout << "Employee not found.\n";
        return;
    }

    cout << "Sale amount (PHP): ";
    cin >> amount;
    if (cin.fail() || amount <= 0) {
        cout << "Please enter a valid amount greater than zero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Sale date (e.g. 2026-11-04): ";
    getline(cin, date);

    SaleTransaction sale{id, amount, date};
    employees[index].totalSales += amount;
    employees[index].transactionCount++;

    transactionHistory.push_back(sale);
    undoStack.push(sale);

    cout << "Sale recorded successfully!\n";
}

void SalesTracker::searchEmployee() const {
    int id;
    cout << "\n--- SEARCH EMPLOYEE ---\n";
    cout << "Enter employee ID: ";
    cin >> id;

    int index = findEmployeeIndex(id);
    if (index == -1) {
        cout << "Employee not found.\n";
        return;
    }

    const Employee& e = employees[index];
    cout << "\nEmployee found!\n";
    cout << "ID: " << e.id << '\n';
    cout << "Name: " << e.name << '\n';
    cout << "Position: " << e.position << '\n';
    cout << "Total sales: PHP " << fixed << setprecision(2) << e.totalSales << '\n';
    cout << "Number of transactions: " << e.transactionCount << '\n';
}

void SalesTracker::mergeEmployees(int left, int mid, int right) {
    array<Employee, MAX_EMPLOYEES> temp;

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (employees[i].totalSales >= employees[j].totalSales) {
            temp[k++] = employees[i++];
        } else {
            temp[k++] = employees[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = employees[i++];
    }

    while (j <= right) {
        temp[k++] = employees[j++];
    }

    for (int x = left; x <= right; x++) {
        employees[x] = temp[x];
    }
}
void SalesTracker::mergeSortEmployees(int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortEmployees(left, mid);
    mergeSortEmployees(mid + 1, right);

    mergeEmployees(left, mid, right);
}

void SalesTracker::rankEmployees() {
    if (employeeCount == 0) {
        cout << "\nNo employees to rank.\n";
        return;
    }

     mergeSortEmployees(0, employeeCount - 1);

    cout << "\n--- SALES PERFORMANCE RANKING ---\n";
    for (int i = 0; i < employeeCount; ++i) {
        cout << i + 1 << ". " << employees[i].name
             << " (ID: " << employees[i].id << ") - PHP "
             << fixed << setprecision(2) << employees[i].totalSales << '\n';
    }
}

void SalesTracker::addToEvaluationQueue() {
    void SalesTracker::countEmployeesMeetingQuota() {
    if (employeeCount == 0) {
        cout << "\nNo employees available.\n";
        return;
    }

    double quota;

    cout << "\n--- SALES QUOTA ANALYSIS ---\n";
    cout << "Enter sales quota (PHP): ";
    cin >> quota;

    if (cin.fail() || quota < 0) {
        cout << "Invalid quota.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Sort employees by total sales in descending order.
    mergeSortEmployees(0, employeeCount - 1);

    // BINARY SEARCH: find the number of employees
    // whose total sales are greater than or equal to the quota.
    int low = 0;
    int high = employeeCount;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (employees[mid].totalSales >= quota) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << "\nSales Quota: PHP " << fixed
         << setprecision(2) << quota << '\n';

    cout << "Employees meeting quota: "
         << low << " out of " << employeeCount << '\n';

    cout << "Employees below quota: "
         << employeeCount - low << '\n';
}
    int id;
    cout << "\n--- ADD EMPLOYEE TO EVALUATION QUEUE ---\n";
    cout << "Employee ID: ";
    cin >> id;

    if (findEmployeeIndex(id) == -1) {
        cout << "Employee not found.\n";
        return;
    }

    evaluationQueue.push(id);
    cout << "Employee added to the evaluation queue.\n";
}

void SalesTracker::processEvaluation() {
    cout << "\n--- PROCESS EVALUATION QUEUE ---\n";
    if (evaluationQueue.empty()) {
        cout << "The evaluation queue is empty.\n";
        return;
    }

    int id = evaluationQueue.front();
    evaluationQueue.pop();

    int index = findEmployeeIndex(id);
    if (index != -1) {
        const Employee& e = employees[index];
        cout << "Evaluating: " << e.name << " (ID: " << e.id << ")\n";
        cout << "Total sales: PHP " << fixed << setprecision(2)
             << e.totalSales << '\n';
        cout << "Transactions: " << e.transactionCount << '\n';
    }
}

void SalesTracker::showTransactionHistory() const {
    cout << "\n--- SALES TRANSACTION HISTORY ---\n";
    if (transactionHistory.empty()) {
        cout << "No transactions recorded.\n";
        return;
    }

    int number = 1;
    for (const auto& sale : transactionHistory) {
        int index = findEmployeeIndex(sale.employeeId);
        string employeeName = (index == -1) ? "Unknown" : employees[index].name;

        cout << number++ << ". Employee: " << employeeName
             << " | ID: " << sale.employeeId
             << " | Amount: PHP " << fixed << setprecision(2) << sale.amount
             << " | Date: " << sale.date << '\n';
    }
}

void SalesTracker::undoLastSale() {
    cout << "\n--- UNDO LAST SALE ---\n";
    if (undoStack.empty()) {
        cout << "There is no sale to undo.\n";
        return;
    }

    SaleTransaction lastSale = undoStack.top();
    undoStack.pop();

    int index = findEmployeeIndex(lastSale.employeeId);
    if (index != -1) {
        employees[index].totalSales -= lastSale.amount;
        employees[index].transactionCount--;
    }

    // Remove the most recent matching transaction from the linked list.
    for (auto it = transactionHistory.end(); it != transactionHistory.begin();) {
        --it;
        if (it->employeeId == lastSale.employeeId &&
            it->amount == lastSale.amount &&
            it->date == lastSale.date) {
            transactionHistory.erase(it);
            break;
        }
    }

    cout << "The latest sale was undone successfully.\n";
}

void SalesTracker::showSalesReport() const {
    cout << "\n--- OVERALL SALES REPORT ---\n";
    if (employeeCount == 0) {
        cout << "No employee data available.\n";
        return;
    }

    double total = 0.0;
    int totalTransactions = 0;
    int topIndex = 0;

    for (int i = 0; i < employeeCount; ++i) {
        total += employees[i].totalSales;
        totalTransactions += employees[i].transactionCount;
        if (employees[i].totalSales > employees[topIndex].totalSales) {
            topIndex = i;
        }
    }

    cout << "Number of employees: " << employeeCount << '\n';
    cout << "Total sales: PHP " << fixed << setprecision(2) << total << '\n';
    cout << "Total transactions: " << totalTransactions << '\n';
    cout << "Top performer: " << employees[topIndex].name
         << " (PHP " << employees[topIndex].totalSales << ")\n";
}
