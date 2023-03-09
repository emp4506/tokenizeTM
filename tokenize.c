//
// File: tokenize.c
//
// Description: Runs the program and handles the argument vectors
//
// @author: Evan Prizel, emp4506
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "header/matrix.h"
#include "header/scanner.h"
#include "header/classes.h"

///
/// main function
///
/// @param argc - number of things on the command line
/// @param argv - vector of command-line arguments
///
/// @return 0 on success, 1 if an error occurs
///
int main(int argc, char *argv[]) {
    FILE *fp;
    
    if (argc != 2) {
        fprintf(stderr, "usage: ./tokenize tmfile\n");
        exit( EXIT_FAILURE );
    }

    // open the TM file
    fp = fopen( argv[1], "r" );

    // check to be sure the open succeeded
    if( fp == NULL ) {
        // something went wrong - report it, and exit
        perror( argv[1] );
        exit( EXIT_FAILURE );
    }
    
    char buf[BUFLENGTH];
    int numStates;
    int startState;
    int acceptState;
    char * spl;

    for (int i = 0; i < 3; ++i) {
        fgets(buf, BUFLENGTH, fp);
        while (buf[0] == '#') {
            fgets(buf, BUFLENGTH, fp);
        }   
        
        spl = strtok(buf, " \t\n");
        spl = strtok(NULL, " \t\n");
        if (i == 0) {
            sscanf(spl, "%d", &numStates);
        } else if (i == 1) {
            sscanf(spl, "%d", &startState);
        } else {
            sscanf(spl, "%d", &acceptState);
        }   
    }   
    
    Cell*** matrix = NULL;

    build_matrix(&matrix, fp, buf, numStates);
    
    fclose(fp);

    print_matrix(&matrix, numStates);
    
    scanning(&matrix, startState, acceptState);
    
    free_matrix(&matrix, numStates);

    return EXIT_SUCCESS;
}
