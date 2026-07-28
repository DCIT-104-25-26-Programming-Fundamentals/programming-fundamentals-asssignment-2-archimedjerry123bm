// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
// Function prototypes
double calculateSum(const double arr[], int size);
double calculateAverage(double sum, int size);
double findMaximum(const double arr[], int size);
double findMinimum(const double arr[], int size);

int main() {
    int n;

    // Prompt user for the count
    cout << "How many numbers? ";
    cin >> n;

    // Validate N is positive
    if (n <= 0) {
        cout << "Error: The number of elements must be a positive integer." << endl;
        return 1;
    }

    // Declare array dynamically or use a fixed dynamic array
    double* numbers = new double[n];

    // Read elements from user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Perform calculations
    double sum = calculateSum(numbers, n);
    double average = calculateAverage(sum, n);
    double maxVal = findMaximum(numbers, n);
    double minVal = findMinimum(numbers, n);

    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    // Clean up dynamic memory
    delete[] numbers;

    return 0;
}

// =============================================================================
// FUNCTION DEFINITIONS
// =============================================================================

// Calculates the sum of all elements in the array
double calculateSum(const double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Calculates the average from the total sum and element count
double calculateAverage(double sum, int size) {
    return sum / size;
}

// Finds the maximum value by comparing elements sequentially
double findMaximum(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Finds the minimum value by comparing elements sequentially
double findMinimum(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

