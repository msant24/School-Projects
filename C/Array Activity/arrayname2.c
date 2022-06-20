#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int counter, i, count, len = 0, space = 0;
    char name[120];
    bool flag = true;
    printf("Please enter your name : ");
    scanf("%[^\n]%*c", name);

    len = strlen(name);
    for (i = 0; i < len; i++)
    {
        if (name[i] == 32)
        {
            space += 1;
            if (space > 3)
            {
                printf("\nError!\nPlease enter a name with at most 4 words!");
                exit(0);
            }
        }
        else if (isdigit(name[i]))
        {
            printf("\nError!\nPlease enter a name with letters only!");
            exit(0);
        }
    }
    if (space < 1)
    {
        printf("\nError!\nPlease enter a name with at least 2 words!");
        exit(0);
    }
    printf("Your Name is :\n");
    for (i = 0; i < len; i++)
    {
        printf("%c", name[i]);
    }
    printf("\n");
    printf("Length of your name is : %d\n", len - space);

    printf("Your Name word by word given as:\n");
    count = 0;
    for (i = 0; i < len; i++)
    {
        if (name[i] == 32)
        {
            printf("\nlength of above word = %d\n", count);
            count = 0;
        }
        else
        {
            printf("%c", name[i]);
            count++;
        }
    }
    printf("\nlength of above word = %d\n", count);

    return 0;
}