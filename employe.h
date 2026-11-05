#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>

class Employee {
private:
    int id;
    std::string name;
    std::string department;
    double totalSales;
    int transactionCount; 

public:
    
    Employee() : id(0), name(""), department(""), totalSales(0.0), transactionCount(0) {}

    
    Employee(int id, const std::string& name, const std::string& position)
        : id(id), name(name), position(position), totalSales(0.0), transactionCount(0) {}

    
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getDepartment() const { return department; }
    double getTotalSales() const { return totalSales; }
    int getTransactionCount() const { return transactionCount; }

    
    double getAverageSale() const {
        return transactionCount > 0 ? totalSales / transactionCount : 0.0;
    }

    
    
    friend class SalesTracker;
};


struct SaleTransaction {
    int employeeId;
    double amount;
    std::string date;
};

#endif
