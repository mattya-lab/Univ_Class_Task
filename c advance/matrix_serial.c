#include < stdio.h >

#define ARRAY_SIZE (3)

/*
 * Routine to multiply a row by a column and place element in 
 * resulting matrix.
 */
void mult(int size, int row, int column, int MA[][ARRAY_SIZE], int MB[][ARRAY_SIZE], int MC[][ARRAY_SIZE])
{
    int position;

    //MC[row][column] = 0;

    for (position = 0; position < size; position++) {
        MC[row][column] = MC[row][column] + (MA[row][position] * MB[position][column]);
    }
}

/* 
 * Main: allocates matrix, assigns, values, compute the results
 */
int main(void)
{
    int size, row, column;

    /* Currently size hardwired to ARRAY_SIZE size */
    size = ARRAY_SIZE;

    /* Fill in matrix values, currently values are hardwired */
    int MA[ARRAY_SIZE][ARRAY_SIZE] = { {1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9} };

    int MB[ARRAY_SIZE][ARRAY_SIZE] = { {1, 0, 0},
                                       {0, 1, 0},
                                       {0, 0, 1} };

    int MC[ARRAY_SIZE][ARRAY_SIZE] = { {0, 0, 0},
                                       {0, 0, 0},
                                       {0, 0, 0} };
    
    /* Precess Matrix, by row, column */
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            mult(size, row, column, MA, MB, MC);
        }
    }

    /* print results */
    printf("MATRIX: The resulting matrix C is;\n");
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            printf("%5d ", MC[row][column]);
        }
        printf("\n");
    }
    return 0;
}