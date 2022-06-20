#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int counter, i, temp, j = 0, countAppearance[26];
    char name[120];
    bool flag = true;

    if (argc < 3 || argc > 5)
        printf("\nError!\nPlease enter a name(Letters only) with at least 2 words and at most 4 words!");
    else
    {
        for (i = 0; i < 26; i++)
            countAppearance[i] = 0;

        for (counter = 1; counter < argc; counter++)
        {
            temp = strlen(argv[counter]);
            for (i = 0; i < temp; i++)
            {
                name[j] = argv[counter][i];
                j++;
                if (argv[counter][i] >= 'A' && argv[counter][i] <= 'Z')
                    countAppearance[argv[counter][i] - 65] += 1;
                else if (argv[counter][i] >= 'a' && argv[counter][i] <= 'z')
                    countAppearance[argv[counter][i] - 97] += 1;
                else
                {
                    printf("\nError!\nPlease enter a name[Letters only] with at least 2 words and at most 4 words!");
                    flag = false;
                }
            }
        }
        if (flag)
        {
            printf("Your name is : ");
            for (counter = 1; counter < argc; counter++)
                printf("%s\t", argv[counter]);
            printf("\n\nList of characters in my name:\n");
            for (i = 0; i < 26; i++)
                if (countAppearance[i])
                    printf("%c\t%d\n", 97 + i, countAppearance[i]);
        }
    }
    return 0;
}