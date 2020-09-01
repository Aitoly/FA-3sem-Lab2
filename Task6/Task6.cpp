#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctype.h>

char* StrPlus(char* str1, char* str2)
{
    if (!str1 && !str2)
        return nullptr;

    if (!str1)
    {
        char *newStr = (char*)malloc((strlen(str2) + 1) * sizeof(char));
        strcpy(newStr, str2);
        return newStr;
    }

    if (!str2)
    {
        char* newStr = (char*)malloc((strlen(str1) + 1) * sizeof(char));
        strcpy(newStr, str1);
        return newStr;
    }

    char* newStr = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    char* pNewStr = newStr;

    strcpy(pNewStr, str1);
    pNewStr += strlen(pNewStr);

    strcpy(pNewStr, str2);

    return newStr;
}

int main()
{
    char str1[] = "Hello m";
    char str2[] = "y friend!";

    char* newStr = StrPlus(str1, str2);

    if(newStr)
        printf("%s\n", newStr);
    else
        printf("Error!\n", newStr);

    free(newStr);

    return 0;
}