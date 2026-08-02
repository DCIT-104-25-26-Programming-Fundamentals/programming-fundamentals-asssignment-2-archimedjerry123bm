// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

using namespace std;

const int MAX_SIZE = 10;

// Helper function to input matrix elements
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Helper function to display a matrix in a neat grid
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << "\n";
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = src[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], int rowsA, int colsA,
                      const int B[MAX_SIZE][MAX_SIZE], int colsB,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0; // Initialize sum accumulator
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    cout << "=========================================\n";
    cout << "        PART A: MATRIX TRANSPOSE         \n";
    cout << "=========================================\n";
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    int A[MAX_SIZE][MAX_SIZE];
    readMatrix(A, rowsA, colsA, "A");

    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(A, rowsA, colsA, transposed);

    cout << "\nOriginal Matrix A:\n";
    printMatrix(A, rowsA, colsA);

    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, colsA, rowsA);

    cout << "\n=========================================\n";
    cout << "        PART B: MATRIX ADDITION          \n";
    cout << "=========================================\n";
    cout << "Using dimension (" << rowsA << "x" << colsA << ") for Matrix B:\n";
    int B[MAX_SIZE][MAX_SIZE];
    readMatrix(B, rowsA, colsA, "B");

    int sum[MAX_SIZE][MAX_SIZE];
    addMatrices(A, B, rowsA, colsA, sum);

    cout << "\nMatrix A + Matrix B Result:\n";
    printMatrix(sum, rowsA, colsA);

    cout << "\n=========================================\n";
    cout << "      PART C: MATRIX MULTIPLICATION      \n";
    cout << "=========================================\n";
    int rowsB_mult, colsB_mult;
    cout << "Matrix A dimensions are currently (" << rowsA << "x" << colsA << ").\n";
    cout << "For multiplication (A x B), Matrix B MUST have " << colsA << " rows.\n";
    
    rowsB_mult = colsA; // Required for multiplication rule
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB_mult;

    int B_mult[MAX_SIZE][MAX_SIZE];
    readMatrix(B_mult, rowsB_mult, colsB_mult, "B (for Multiplication)");

    int product[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(A, rowsA, colsA, B_mult, colsB_mult, product);

    cout << "\nMatrix A x Matrix B Result (" << rowsA << "x" << colsB_mult << "):\n";
    printMatrix(product, rowsA, colsB_mult);

    return 0;
}