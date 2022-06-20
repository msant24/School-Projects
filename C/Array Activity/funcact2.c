#include <stdio.h>

#include <string.h>

#include "encode.h"

#define MAX 80

int main()
{

    printf("Enter sentence followed by enter: ");

    char str[MAX + 1];

    fgets(str, MAX, stdin);

    printf("Enter shift amount followed by enter: ");

    int n;

    scanf("%d", &n);

    decode(str, n);

    printf("Decoded sentence: %s", str);
}