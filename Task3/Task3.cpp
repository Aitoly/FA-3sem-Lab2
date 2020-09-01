#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>

int strLen(char* str)
{
    if (!str)
        return -1;//error code

    //return strlen(str);//LOL

    int size = 0;
    while (*str != '\0')
    {
        ++size;
        ++str;
    }

    return size;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[] = "Hello!";

    printf("%s : %d\n", str, strLen(str));
}