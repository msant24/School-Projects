#include <stdio.h>

#include <string.h>

#include <ctype.h>

void encode(char *str, int n)
{

    int len = strlen(str);

    int i;

    for (i = 0; i < len; ++i)
    {

        if (islower(str[i]))
        {

            int t = str[i] - 97;

            int shift = (t + n) % 26;

            str[i] = 97 + shift;
        }

        else if (isupper(str[i]))
        {

            int t = str[i] - 65;

            int shift = (t + n) % 26;

            str[i] = 65 + shift;
        }

        else
            continue;
    }
}

void decode(char *str, int n)
{

    int len = strlen(str);

    int i;

    for (i = 0; i < len; ++i)
    {

        if (islower(str[i]))
        {

            int t = 122 - str[i];

            int shift = (t + n) % 26;

            str[i] = 122 - shift;
        }

        else if (isupper(str[i]))
        {

            int t = 90 - str[i];

            int shift = (t + n) % 26;

            str[i] = 90 - shift;
        }

        else
            continue;
    }
}