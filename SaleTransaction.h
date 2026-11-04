#ifndef SALE_TRANSACTION_H
#define SALE_TRANSACTION_H

#include <iostream>
#include <iomanip>
#include <string>

class SaleTransaction {
private:
    int transactionId;
    int employeeId;
    std::string employeeName;
    double amount;

public:
    SaleTransaction()
        : transactionId(0), employeeId(0), employeeName(""), amount(0.0) {}

    SaleTransaction(int transactionId, int employeeId,
                    const std::string& employeeName, double amount)
        : transactionId(transactionId), employeeId(employeeId),
          employeeName(employeeName), amount(amount) {}

    int getTransactionId() const { return transactionId; }
    int getEmployeeId() const { return employeeId; }
    const std::string& getEmployeeName() const { return employeeName; }
    double getAmount() const { return amount; }

    void display() const {
        std::cout << std::left
                  << std::setw(8)  << transactionId
                  << std::setw(8)  << employeeId
                  << std::setw(22) << employeeName
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(14) << amount
                  << std::endl;
    }

    static void printHeader() {
        std::cout << std::left
                  << std::setw(8)  << "Txn #"
                  << std::setw(8)  << "Emp ID"
                  << std::setw(22) << "Employee"
                  << std::right
                  << std::setw(14) << "Amount"
                  << "\n" << std::string(52, '-') << std::endl;
    }
};

#endif // SALE_TRANSACTION_H
