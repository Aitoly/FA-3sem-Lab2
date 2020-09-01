#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<Windows.h>

const int s = 10;

int** matr(int** a, int n, int x) {
    int** res = (int**)malloc((n - 1) * sizeof(int*));

    for (int i = 0; i < n - 1; ++i)
        res[i] = (int*)malloc((n - 1) * sizeof(int));

    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k)
        {
            if (j == x) {
                --k;
                continue;
            }
            res[i - 1][k] = a[i][j];
        }
    return res;
}

int det(int** a, int n) {
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    int ans = 0, sig = 1;
    for (int i = 0; i < n; ++i) {
        ans += (sig * a[0][i] * det(matr(a, n, i), n - 1));
        sig *= -1;
    }
    return ans;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));
    int n;
    printf("Введите размерность матрицы: "); // Вводим матрицу
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Ошибка ввода!:");
        printf("\n"); // Ошибка матрицы
        return -1;
    }
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Определитель матрицы =  %d\n", det(a, n)); 

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}
