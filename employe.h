#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>

class Employee {
private:
    int id;
    std::string name;
    std::string position;
    double totalSales;
    int transactionCount; // Matches salesCount / transactionCount in the tracker

public:
    // Default Constructor
    Employee() : id(0), name(""), position(""), totalSales(0.0), transactionCount(0) {}

    // Parameterized Constructor
    Employee(int id, const std::string& name, const std::string& position)
        : id(id), name(name), position(position), totalSales(0.0), transactionCount(0) {}

    // Getters
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getPosition() const { return position; }
    double getTotalSales() const { return totalSales; }
    int getTransactionCount() const { return transactionCount; }

    // Utility function to calculate average sale per transaction
    double getAverageSale() const {
        return transactionCount > 0 ? totalSales / transactionCount : 0.0;
    }

    // Friend class to allow SalesTracker to directly access or modify data members 
    // (such as adding sales and updating records) without breaking encapsulation.
    friend class SalesTracker;
};

// SaleTransaction struct used for transaction history and the undo stack
struct SaleTransaction {
    int employeeId;
    double amount;
    std::string date;
};

#endif
