#include <stdio.h>

void singleLevel()
{
    int n;
    char file[20][30];

    printf("\nEnter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for(int i = 0; i < n; i++)
        scanf("%s", file[i]);

    printf("\nSingle Level Directory:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", file[i]);
}

void twoLevel()
{
    int users, files;

    printf("\nEnter number of users: ");
    scanf("%d", &users);

    for(int i = 0; i < users; i++)
    {
        printf("\nUser %d\n", i + 1);

        printf("Enter number of files: ");
        scanf("%d", &files);

        char file[20][30];

        printf("Enter file names:\n");
        for(int j = 0; j < files; j++)
            scanf("%s", file[j]);

        printf("Files of User %d:\n", i + 1);
        for(int j = 0; j < files; j++)
            printf("%s\n", file[j]);
    }
}

void hierarchical()
{
    int n;

    printf("\nEnter number of directories: ");
    scanf("%d", &n);

    char dir[20][30];

    printf("Enter directory names:\n");
    for(int i = 0; i < n; i++)
        scanf("%s", dir[i]);

    printf("\nHierarchical Directory Structure:\n");

    for(int i = 0; i < n; i++)
    {
        printf("Root/%s\n", dir[i]);
    }
}

int main()
{
    int choice;

    printf("FILE ORGANIZATION TECHNIQUES\n");
    printf("1. Single Level Directory\n");
    printf("2. Two Level Directory\n");
    printf("3. Hierarchical Directory\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            singleLevel();
            break;

        case 2:
            twoLevel();
            break;

        case 3:
            hierarchical();
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}
