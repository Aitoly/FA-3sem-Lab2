#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>

#define SIZE 64

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* in, * out;

    in = fopen("in.txt", "r");
    if (!in)
    {
        printf("Не могу открыть файл in.txt\n");
        return 0;
    }

    out = fopen("out.txt", "w");
    if (!out)
    {
        printf("Не могу открыть файл out.txt\n");
        fclose(in);
        return 0;
    }

    int i = 0, num = 0;
    while (!feof(in) && i < SIZE)
    {
        if (fscanf(in, "%d", &num) != 1)
        {
            printf("Ошибка ввода!\n");
            return 0;
        }

        if (i % 2 == 0)
        {
            fprintf(out, "%d ", num);
        }

        fscanf(in, " ");

        ++i;
    }

    fclose(in);
    fclose(out);

    printf("Успешно!\n");

    return 0;
}