//
// File: scanner.c
// 
// Description: Scan the standard input and traverse the tree
//              based on that.
//
// @author: Evan Prizel, emp4506
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "header/scanner.h"
#include "header/classes.h"
#include "header/matrix.h"

///
/// Scans standard input character by character and traverses the
/// tree based on the characters. It also determines whether a word
/// is accepted or not
/// 
void scanning(Cell**** matrix, int startState, int acceptedState) {
    
    int col;
    int row = startState;
    char *word = calloc(1, sizeof(char));
    Cell *matrixCell;
    char ch;
    char chword[1];
    bool validStart = true;

    while((ch = getchar())) {
        if ((ch == ' ' || ch == '\n') && !validStart) {
            validStart = true;
            continue;
        }
        if (!validStart) {
            continue;
        }
        if (isalpha(ch) != 0 || ch == '_') {
            col = CC_ALPHA;
        } else if (0 <= (ch - 0) && (ch - 0) <= 127) {
            switch(ch) {
                case ' ':
                case '\t':
                    col = CC_WS;
                    break;
                case '\n':
                    col = CC_NL;
                    break;
                case '0':
                    col = CC_ZERO;
                    break;
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    col = CC_OCTAL;
                    break;
                case '8':
                case '9':
                    col = CC_DECIMAL;
                    break;
                case '/':
                    col = CC_SLASH;
                    break;
                case '*':
                    col = CC_STAR;
                    break;
                case '+':
                case '-':
                case '%':
                    col = CC_ARITH;
                    break;
                case EOF:
                    col = CC_EOF;
                    break;
                default:
                    col = CC_OTHER;
                    break;
            }
        } else {
                col = CC_ERROR;
        }
        if (row == startState) {
            printf("%d ", startState);
        }
        matrixCell = (*matrix)[row][col];
        if(matrixCell->action == 's') {
            printf("%d ", matrixCell->state);
            word = realloc(word, (sizeof(char) * (strlen(word) + 2)));        
            chword[0] = ch;
            strcat(word, chword);
        }
        row = matrixCell->state;
        if (row == acceptedState) {
            printf("%d recognized \'%s\'\n", acceptedState, word);
            free(word);
            word = calloc(1, sizeof(char));
            row = startState;
        } if (ch == EOF) {
            printf("%d EOF\n", acceptedState);
            free(word);
            break;
        } if (row == -1) {
            printf("-1 rejected\n");
            free(word);
            word = calloc(1, sizeof(char));
            row = startState;
            validStart = false;
        }
    }
    return;
}
