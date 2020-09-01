#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctype.h>

void Sort(char* str)
{
    if (!str)
        return;

    int size = strlen(str);

    char* digits = (char*)malloc((size + 1) * sizeof(char));
    char* alpha = (char*)malloc((size + 1) * sizeof(char));
    char* other = (char*)malloc((size + 1) * sizeof(char));
    char* pDigits = digits, * pAlpha = alpha, * pOther = other, *pStr = str;

    for (int i = 0; i < size; ++i)
    {
        if (isdigit(*pStr))
        {
            *pDigits = *pStr;
            ++pDigits;
        }
        else if (isalpha(*pStr))
        {
            *pAlpha = *pStr;
            ++pAlpha;
        }
        else
        {
            *pOther = *pStr;
            ++pOther;
        }

        ++pStr;
    }

    *pDigits = '\0';
    *pAlpha = '\0';
    *pOther = '\0';

    strcpy(str, digits);
    str += strlen(str);

    strcpy(str, alpha);
    str += strlen(str);

    strcpy(str, other);

    free(digits);
    free(alpha);
    free(other);
}

int main()
{
    char str[] = "Hello my friend! 1234???+==-";

    printf("%s", str);

    Sort(str);

    printf(" => %s\n", str);

    return 0;
}