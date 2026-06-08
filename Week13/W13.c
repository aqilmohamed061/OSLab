#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

/* FCFS */
void FCFS(int req[], int n, int head)
{
    int seek = 0;

    printf("\nSeek Sequence: %d", head);

    for(int i = 0; i < n; i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
}

/* SSTF */
void SSTF(int req[], int n, int head)
{
    int visited[n];
    int seek = 0;

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nSeek Sequence: %d", head);

    for(int i = 0; i < n; i++)
    {
        int min = 9999;
        int index = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && abs(req[j] - head) < min)
            {
                min = abs(req[j] - head);
                index = j;
            }
        }

        visited[index] = 1;
        seek += abs(req[index] - head);
        head = req[index];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
}

/* SCAN */
void SCAN(int req[], int n, int head)
{
    sort(req, n);

    int seek = 0;
    int pos = 0;

    for(int i = 0; i < n; i++)
    {
        if(req[i] > head)
        {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", head);

    for(int i = pos; i < n; i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    seek += abs(199 - head);
    head = 199;

    for(int i = pos - 1; i >= 0; i--)
    {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
}

/* C-LOOK */
void CLOOK(int req[], int n, int head)
{
    sort(req, n);

    int seek = 0;
    int pos = 0;

    for(int i = 0; i < n; i++)
    {
        if(req[i] > head)
        {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", head);

    for(int i = pos; i < n; i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    seek += abs(head - req[0]);
    head = req[0];
    printf(" -> %d", head);

    for(int i = 1; i < pos; i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
}

int main()
{
    int n, head, choice;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.C-LOOK\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: FCFS(req, n, head); break;
        case 2: SSTF(req, n, head); break;
        case 3: SCAN(req, n, head); break;
        case 4: CLOOK(req, n, head); break;
        default: printf("Invalid Choice");
    }

    return 0;
}
