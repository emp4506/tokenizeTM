//
// File: scanner.h
//
// Description: Allows other files to access the functions of
//              scanner.c.
//
// Author: Evan Prizel, emp4506
//

#ifndef SCANNER_H_
#define SCANNER_H_

#include "matrix.h"

///
/// Scans standard input character by character and traverses the
/// tree based on the characters. It also determines whether a word
/// is accepted or not
///
/// @param matrix        - A pointer to the matrix
/// @param startState    - The starting state of the matrix
/// @param acceptedState - The accepting state of the matrix
///
void scanning(Cell**** matrix, int startState, int acceptedState);

#endif
