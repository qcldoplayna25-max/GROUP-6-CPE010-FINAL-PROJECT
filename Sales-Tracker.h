#ifndef SALES_TRACKER_H
#define SALES_TRACKER_H

#include "employe.h"
#include <array>
#include <queue>
#include <list>
#include <stack>
#include <string>

class SalesTracker {
private:
    static const int MAX_EMPLOYEES = 100;

    std::array<Employee, MAX_EMPLOYEES> employees;
    int employeeCount = 0;

    std::queue<int> evaluationQueue;
    std::list<SaleTransaction> transactionHistory;
    std::stack<SaleTransaction> undoStack;

    int findEmployeeIndex(int id) const;
    void mergeSortEmployees(int left, int right);
    void mergeEmployees(int left, int mid, int right);

public:
    void addEmployee();
    void displayEmployees() const;
    void recordSale();
    void searchEmployee() const;
    void rankEmployees();
    void countEmployeesMeetingQuota();
    void addToEvaluationQueue();
    void processEvaluation();
    void showTransactionHistory() const;
    void undoLastSale();
    void showSalesReport() const;
};

#endif
