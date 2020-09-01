#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctype.h>

char* Reverse(char* str)
{
    if (!str)
        return nullptr;

    int size = strlen(str);

    char* newStr = (char*)malloc((size + 1) * sizeof(char));
    char* pNewStr = newStr;
    char* pStr = str + strlen(str) - 1;

    for (int i = 0; i < size; ++i)
    {
        *pNewStr = *pStr;
        pNewStr++;
        pStr--;
    }

    *pNewStr = '\0';

    return newStr;
}

int main()
{
    char str[] = "Hello my friend! 1234???+==-";

    printf("%s\n", str);

    char* newStr = Reverse(str);

    if (newStr)
        printf("%s\n", newStr);
    else
        printf("Error!\n", newStr);

    free(newStr);

    return 0;
}