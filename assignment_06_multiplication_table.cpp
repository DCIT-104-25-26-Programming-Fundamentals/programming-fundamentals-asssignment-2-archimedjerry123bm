// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function Prototypes
void printSingleTable(int num);
void generateTablesUpToN(int n);

// -----------------------------------------------------------------------------
// PART A — Single Table Function
// -----------------------------------------------------------------------------
void printSingleTable(int num) {
    cout << "Multiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        cout << num << "  x  " << setw(2) << left << i 
             << " =  " << num * i << "\n";
    }
}

// -----------------------------------------------------------------------------
// PART B — Tables from 1 to N Function
// -----------------------------------------------------------------------------
void generateTablesUpToN(int n) {
    for (int i = 1; i <= n; ++i) {
        printSingleTable(i);
        if (i < n) {
            cout << "---------------------------\n";
        }
    }
}

// -----------------------------------------------------------------------------
// MAIN PROGRAM
// -----------------------------------------------------------------------------
int main() {
    int choice;
    cout << "=== Multiplication Table Generator ===\n";
    cout << "1. Single Table (Part A)\n";
    cout << "2. Tables from 1 to N (Part B)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "\nEnter a positive integer: ";
        cin >> num;

        // Input Validation
        if (cin.fail() || num <= 0) {
            cout << "Error: Invalid input! Please enter a positive integer.\n";
            return 1;
        }

        cout << endl;
        printSingleTable(num);

    } else if (choice == 2) {
        int n;
        cout << "\nEnter a positive integer N: ";
        cin >> n;

        // Input Validation
        if (cin.fail() || n <= 0) {
            cout << "Error: Invalid input! Please enter a positive integer.\n";
            return 1;
        }

        cout << endl;
        generateTablesUpToN(n);

    } else {
        cout << "Error: Invalid menu choice!\n";
        return 1;
    }

    return 0;
}