#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define BOARDSIZE 8    
#define EMPTY_CHAR   '-'


int     difference(int i, int j)
{
    if (i < j) 
        return j - i;
    else
        return i - j;
}

int     is_valid(int a[], int row, int column)
{
    // check if any queen already placed threats board[row][column]
    for (int i = 0; i < row; i++) {
        if ((column == a[i])                        // column threat 
            || difference(i, row) == difference(a[i], column))  // diagonal threat
            return FALSE;
    }
    return TRUE;
}

void process_solution(int a[], int k)
{
    // print the board
    char    line[BOARDSIZE + 1];

    for (int i = 0; i < BOARDSIZE; i++) {
        line[i] = EMPTY_CHAR;
    }
    line[BOARDSIZE] = 0;

    for (int i = 0; i < BOARDSIZE; i++) {
        line[a[i]] = '*';
        puts(line);
        line[a[i]] = EMPTY_CHAR;
    }

    for (int i = 0; i < BOARDSIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


// k: number of queens already placed and k >= 0
int solve_8queens(int a[], int k)
{
    int counter = 0;

    if (k == BOARDSIZE) {
        // if all queens have already been placed ...
        process_solution(a, k);
        counter += 1;
    }
    else {
        // try row k. Rows 0 .. (k-1) already have a queen
        // Use j for columns
        for (int j = 0; j < BOARDSIZE; j++) { // tries every position in current row
            if (is_valid(a, k, j)) {
                a[k] = j;
                counter += solve_8queens(a, k+1);
                if (counter) {
                    // terminate after the first solution
                    break;
                }
            }
        }
    }
    return counter;
}

int main(int argc, char **argv)
{
    int a[BOARDSIZE] = {0};  /* location of queens. */
    
    // this is an array of size BOARDSIZE
    for (int i = 0; i < BOARDSIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    if (argc == 2) {
        int c = atoi(argv[1]);
        if (c < 0 || c >= BOARDSIZE) {
            printf("The position is not correct.\n");
            return -1;
        }
        a[0] = c;
    }

    // int solution_counts[]={1, 0, 0, 2, 10, 4, 40, 92};

    printf("Number of solutions=%d\n", solve_8queens(a, 1)); 
    // prints index of each queen in its respective row

    return 0;
}