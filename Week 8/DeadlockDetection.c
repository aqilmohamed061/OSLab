#include <stdio.h>

#define MAX 10

int main() {
    int n, m;
    int alloc[MAX][MAX], request[MAX][MAX];
    int avail[MAX], work[MAX], finish[MAX];
    int i, j;


    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }


    for(i = 0; i < n; i++)
        finish[i] = 0;


    int changed = 1;
    while(changed) {
        changed = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canRun = 1;
                for(j = 0; j < m; j++) {
                    if(request[i][j] > work[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if(canRun) {
                    for(j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    changed = 1;
                }
            }
        }
    }


    int deadlock = 0;
    printf("\nResult:\n");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(!deadlock)
        printf("No Deadlock");

    printf("\n");

    return 0;
}
