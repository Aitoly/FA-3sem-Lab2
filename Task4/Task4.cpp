#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctype.h>

void Upper(char* str)
{
    if (!str)
        return;

    int size = strlen(str);

    for (int i = 0; i < size; i += 2)
    {
        *str = toupper(*str);
        str++;
        str++;
    }
}

int main()
{
    char str[] = "Hello my friend! 1234???+==-";

    printf("%s", str);

    Upper(str);

    printf(" => %s\n", str);

    return 0;
}