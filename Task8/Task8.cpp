#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <Windows.h>

#pragma warning(disable:4996)
#define EPS 0.000000000001

double Recursion(double x, int n)
{
	if (n == 0)
	{
		if (abs(x) < EPS)
		{
			printf("None\n");
			return 0;
		}
		return 1;
	}
	if (n < 0)
	{
		return Recursion(1 / x, -n);
	}

	if (n == 1)
		return x;

	if (n % 2)
	{
		return x * Recursion(x, n - 1);
	}
	else
	{
		double t = Recursion(x, n - 1);
		return t * t;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double n;
	int pow;
	printf("������� �����: ");
	scanf("%lf", &n);
	printf("������� �������: ");
	scanf("%d", &pow);

	printf("�����: %lf\n", Recursion(n, pow));
	return 0;
}
