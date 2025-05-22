#include <stdio.h>
#define N 3
int main() {
    int matrix[N][N] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };
    int sumDiag1 = 0, sumDiag2 = 0;
    // Calculate the sum of the main diagonal and secondary diagonal
    for (int i = 0; i < N; i++) {
        sumDiag1 += matrix[i][i];               // Main diagonal
        sumDiag2 += matrix[i][N - i - 1];       // Secondary diagonal
    }
    // Check if both diagonals have the same sum
    if (sumDiag1 != sumDiag2) {
        printf("Not a magic square (diagonals mismatch).\n");
        return 0;
    }
    int magicSum = sumDiag1;
    // Check each row and column
    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            printf("Not a magic square (row/column mismatch).\n");
            return 0;
        }
    }
    printf("The matrix is a Magic Square! Sum = %d\n", magicSum);
    return 0;
}
