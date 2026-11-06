# GROUP-6-CPE010-Employees Sales Performance Tracker

GROUP 6 FINAL PROJECT

Group Members:

Almirol, Joel

Doplayna, Clifford Lee C.

Licas, Rayven Ferry

Ines, Djay

## Project Description

The **Employee Sales Performance Tracker** is a C++ command-line application designed to manage employee sales records, track transactions, evaluate employee performance, and analyze sales quotas.

### DSA Concepts Used:
- Array: Stores fixed-capacity employee records.
- Linked List: Maintains chronological sales transaction history.
- Stack: Enables undo functionality for recent sales transactions (LIFO).
- Queue: Manages performance evaluations in FIFO order.
- Merge Sort: Sorts employees by total sales performance in descending order.
- Linear Search: Finds employee indexes by ID for lookups.
- Binary Search: Analyzes and determines how many employees meet a designated sales quota.

---

## How to Compile and Run

### Prerequisites
* A C++ compiler supporting standard **C++17** or higher (e.g., `g++` or `clang++`).

### Compilation
Open your terminal/command prompt in the directory containing the source files and run:

```bash
g++ -std=c++17 -O2 main.cpp Sales-Tracker.cpp -o sales_tracker
