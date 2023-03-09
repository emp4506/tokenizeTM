//
// File: matrix.h
//
// Description: To allow other files to access functions in matrix.h
//              as well as recognize the structure.
//
// Author: Evan Prizel, emp4506
//

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <stdlib.h>

// file buffer size
#define BUFLENGTH 255

///
/// This represents a single cell of the matrix.
///
typedef
    struct matrix_cell {
        int state;                  // transition state of the cell
        char action;                // 's' for save 'd' for discard
    } Cell;                         // This is the typedef name to make
                                    // my life easier

///
/// Allocates and builds the matrix given the file pointer, the buffer, and the number
/// of states of the matrix.
///
/// @param matrix    - A pointer to the matrix
/// @param fp        - The pointer to the file
/// @param buf       - The input buffer
/// @param numStates - The number of states in the matrix
///
void build_matrix (Cell ****matrix, FILE *fp, char buf[], int numStates);

///
/// Prints out the matrix in the format required.
///
/// @param matrix - A pointer to the matrix
/// @param row    - The number of rows in the matrix
///
void print_matrix (Cell**** matrix, int row);

///
/// Free's the entire matrix of its memory.
///
/// @param matrix - A pointer to the matrix
/// @param row    - The number of rows in the matrix
///
void free_matrix (Cell**** matrix, int row);

#endif
