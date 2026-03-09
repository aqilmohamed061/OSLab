#include <stdio.h>

int main() {
    int n, i, position;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &position);


    if (position < 1 || position > n) {
        printf("Invalid position! Position must be between 1 and %d.\n", n);
        return 1;
    }


    position = position - 1;


    for (i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }


    printf("Array after deleting element at position %d:\n", position + 1);
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
