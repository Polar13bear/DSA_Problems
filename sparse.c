#include <stdio.h>
#define ROW 3
#define COL 3
int main() {
    int matrix[ROW][COL] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };
    printf("Original Matrix:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nSparse Matrix Representation:\n");
    printf("Row  Col  Val\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (matrix[i][j] != 0) {
                printf("%d    %d    %d\n", i, j, matrix[i][j]);
            }
        }
    }
    return 0;
}
