
#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);


    if (n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 1;
    }

    int arr[n];


    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }


    if (secondSmallest == INT_MAX) {
        printf("There is no second smallest element (all elements are equal).\n");
    } else {
        printf("The second smallest element is: %d\n", secondSmallest);
    }

    return 0;
}

