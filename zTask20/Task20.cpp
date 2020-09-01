#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ввод размерности матриц столбцов и строк.
	int size_A_i;
	int size_A_j;
	int size_B_i;
	int size_B_j;
	printf("Введите количество стобцов матрицы А: ");
	scanf("%d", &size_A_i);
	printf("Введите количество строк матрицы А: ");
	scanf("%d", &size_A_j);
	printf("Введите количество стобцов матрицы B: ");
	scanf("%d", &size_B_i);
	printf("Введите количество строк матрицы B: ");
	scanf("%d", &size_B_j);

	if (size_A_i != size_B_j || size_A_j != size_B_i)
	{
		printf("Умножение таких матриц невозможно!\n");
		exit(-1);
	}

	int i;
	int j;
	int y;
	int** res = (int**)malloc(size_A_i * sizeof(int*));
	for (int i = 0; i < size_A_j; ++i)
	{
		res[i] = (int*)malloc(size_B_i * sizeof(int));
	}

	for (i = 0; i < size_A_j; i++)
		for (j = 0; j < size_B_i; j++)
			res[i][j] = 0;

	int** Matrix_A = (int**)malloc(size_A_i * sizeof(int*));
	for (int i = 0; i < size_A_j; ++i)
	{
		Matrix_A[i] = (int*)malloc(size_A_i * sizeof(int));
	}

	int** Matrix_B = (int**)malloc(size_B_i * sizeof(int*));
	for (int i = 0; i < size_B_j; ++i)
	{
		Matrix_B[i] = (int*)malloc(size_B_i * sizeof(int));
	}

	for (i = 0; i < size_A_j; i++)
		for (j = 0; j < size_A_i; j++)
		{
			printf("Matrix A[%d][%d]: ", i, j);
			scanf("%d", &Matrix_A[i][j]);
		}

	for (i = 0; i < size_B_j; i++)
		for (j = 0; j < size_B_i; j++)
		{
			printf("Matrix B[%d][%d]: ", i, j);
			scanf("%d", &Matrix_B[i][j]);
		}

	for (i = 0; i < size_A_j; i++)
		for (j = 0; j < size_A_i; j++)
			for (y = 0; y < size_A_i; y++)
				res[i][j] = res[i][j] + (Matrix_A[i][y] * Matrix_B[y][j]);
	printf("result: \n");

	for (i = 0; i < size_A_j; i++)
	{
		for (j = 0; j < size_B_i; j++)
			printf("%10d ", res[i][j]);
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < size_A_j; ++i)
	{
		free(res[i]);
	}
	free(res);

	for (int i = 0; i < size_A_j; ++i)
	{
		free(Matrix_A[i]);
	}
	free(Matrix_A);

	for (int i = 0; i < size_B_j; ++i)
	{
		free(Matrix_B[i]);
	}
	free(Matrix_B);

	return 0;
}
