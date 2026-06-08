#include <stdio.h>

void sequential()
{
    int start, len;

    printf("\nEnter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &len);

    printf("\nSequential Allocation:\n");

    for(int i = 0; i < len; i++)
    {
        printf("Block %d -> %d\n", i + 1, start + i);
    }
}

void indexed()
{
    int n, indexBlock;

    printf("\nEnter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int blocks[n];

    printf("Enter block numbers:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndexed Allocation:\n");
    printf("Index Block = %d\n", indexBlock);

    for(int i = 0; i < n; i++)
    {
        printf("Block %d -> %d\n", i + 1, blocks[i]);
    }
}

void linked()
{
    int n;

    printf("\nEnter number of blocks: ");
    scanf("%d", &n);

    int blocks[n];

    printf("Enter block numbers:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nLinked Allocation:\n");

    for(int i = 0; i < n - 1; i++)
    {
        printf("%d -> %d\n", blocks[i], blocks[i + 1]);
    }

    printf("%d -> NULL\n", blocks[n - 1]);
}

int main()
{
    int choice;

    printf("FILE ALLOCATION STRATEGIES\n");
    printf("1. Sequential Allocation\n");
    printf("2. Indexed Allocation\n");
    printf("3. Linked Allocation\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            sequential();
            break;

        case 2:
            indexed();
            break;

        case 3:
            linked();
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}
