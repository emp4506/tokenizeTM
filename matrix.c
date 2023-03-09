//
// File: matrix.c
//
// Description: Contains functions that will build the matrix given the file,
//              free said matrix, and print said matrix.
//
// @author: Evan Prizel, emp4506
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/matrix.h"
#include "header/classes.h"

///
/// Allocates and builds the matrix given the file pointer, the buffer, and the number
/// of states of the matrix.
///
void build_matrix (Cell ****matrix, FILE *fp, char buf[], int numStates) {

    char *spl;
    char *ptr;

    (*matrix) = malloc(numStates * sizeof(Cell**));
    for (int r = 0; r < numStates; ++r) {
        (*matrix)[r] = malloc(NUM_CLASSES * sizeof(Cell*));
        for (int c = 0; c < NUM_CLASSES; ++c) {
            (*matrix)[r][c] = malloc(sizeof(Cell));
            (*matrix)[r][c]->state = -1;
            (*matrix)[r][c]->action = 'd';
        }
    }
    int iRow;
    int iCol;
    int state;
    char action;

    while ((ptr = fgets(buf, BUFLENGTH, fp)) != NULL) {
        while (buf[0] == '#') {
            fgets(buf, BUFLENGTH, fp);
        }

        spl = strtok(buf, " \t\n");
        sscanf(spl, "%d", &iRow);

        spl = strtok(NULL, " \n\t");
        while (spl != NULL) {
            sscanf(spl, "%d/%d%c", &iCol, &state, &action);
            (*matrix)[iRow][iCol]->state = (state);
            (*matrix)[iRow][iCol]->action = action;
            spl = strtok(NULL, " \t\n");
        }
    }
    return;
}

///
/// Prints out the matrix in the format required.
///
void print_matrix (Cell**** matrix, int row) {
    printf("Scanning using the following matrix:\n");
    printf("     0    1    2    3    4    5    6    7    8    9   10   11");
    for (int r = 0; r < row; ++r) {
        if (r < 10) {
            printf("\n %d", r);
        } else {
            printf("\n%d", r);
        }
        for (int c = 0; c < NUM_CLASSES; ++c) {
            if ((*matrix)[r][c]->state < 10 && (*matrix)[r][c]->state > -1) {
                printf("   %d%c", (*matrix)[r][c]->state, (*matrix)[r][c]->action);
            } else {
                printf("  %d%c", (*matrix)[r][c]->state, (*matrix)[r][c]->action);
            }
        }
    }
    printf("\n");
    return;
}

///
/// Free's the entire matrix of its memory.
///
void free_matrix (Cell**** matrix, int row) {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < NUM_CLASSES; ++c) {
            free((*matrix)[r][c]);
        }
        free((*matrix)[r]);
    }
    free(*matrix);
    return;
}
