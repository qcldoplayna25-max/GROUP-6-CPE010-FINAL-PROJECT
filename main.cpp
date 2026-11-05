#ifndef SALESTRACKER_H
#define SALESTRACKER_H

#include <string>
#include <vector>
#include <queue>
#include <stack>

struct Employee {
    int id;
    std::string name;
    double totalSales;

    Employee(int empId = 0, std::string empName = "", double sales = 0.0)
        : id(empId), name(empName), totalSales(sales) {}
};

struct Transaction {
    int employeeId;
    std::string employeeName;
    double amount;
};

class SalesTracker {
private:
    std::vector<Employee> employees;
    std::queue<int> evaluationQueue;           // Queue for FIFO evaluation processing
    std::stack<Transaction> undoStack;        // Stack for LIFO sales undo functionality
    std::vector<Transaction> transactionHistory; // Chronological transaction log

    // Helper functions
    Employee* findEmployeeById(int id);
    bool employeeExists(int id);

public:
    SalesTracker() = default;

    void addEmployee();
    void displayEmployees();
    void recordSale();
    void searchEmployee();
    void rankEmployees();
    void addToEvaluationQueue();
    void processEvaluation();
    void showTransactionHistory();
    void undoLastSale();
    void showSalesReport();
};

#endif // SALESTRACKER_H
