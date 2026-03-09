#include <stdio.h>

int main() {
    int n, i, j, sum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter %d x %d matrix elements:\n", n, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of left diagonal (primary diagonal) elements: %d\n", sum);

    return 0;
}
